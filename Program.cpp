#include "Program.h"

Program::Program():
    _map(),
    _world()
{}

bool Program::execute() {
    while (true) {
        updateWorld();
        auto userInput = getUserInput().trimmed().toUpper();
        if (userInput == "U") {
            showSeparator();
            showUserInterface();
        }
        else if (userInput == "M") {
            _map.lookup(_world);
        }
        else if (userInput == "RT") {
            auto result = _world.radio().turnRadio();
            qInfo() << " radio is now " << ((result)? "ON" : "OFF");
        }
        else if (userInput == "RM") {
            qInfo() << " enter radio position x y: ";
            if (!moveRadio(_world.radio())) {
                qInfo() << " incorrect data typed";
            }
        }
        else if (userInput == "RS") {
            qInfo() << " enter radio frequency: [" << _world.minRadioFrequency() << ", " << _world.maxRadioFrequency() << "]";
            if (!setRadioFrequency(_world.radio())) {
                qInfo() << " incorrect data typed";
            }
        }
        else if (userInput == "RA") {
            _world.radio().autoSetFrequency();
        }
        else if (userInput == "Q") {
            qInfo() << " quiting program..";
            return false;
        }
        else if (userInput == "R") {
            qInfo() << " restarting program..";
            return true;
        }
    }
}

void Program::updateWorld() {
    showSeparator();
    listenToRadio(_world.radio());
    showInstructionToUserInterface();
    broadcastRadioTowers();
}

void Program::showSeparator() {
    qInfo() << " _________________________________________";
}

void Program::showInstructionToUserInterface() {
    qInfo() << " [u] -> show user interface\n";
}

void Program::showUserInterface() {
    qInfo() << "  [m] -> show map of radio towers\n"
            << " [rt] -> turn radio on / off\n"
            << " [rm] -> move radio\n"
            << " [rs] -> set radio frequency\n"
            << " [ra] -> auto-tune radio frequency\n\n"
            << " [q] -> quit program\n"
            << " [r] -> restart program\n";
}

QString Program::getUserInput() {
    QTextStream stream(stdin);
    QString line = stream.readLine();
    return line;
}

void Program::listenToRadio(const Radio &radio) {
    qInfo(" radio says: \"%s\"", radio.play().c_str());
    qInfo() << " current radio frequency: [" << _world.radio().frequency() << "]";
}

bool Program::moveRadio(Radio &radio) {
    auto numberInput = getUserInput().split(" ");
    if (numberInput.size() < 2) {
        return false;
    }
    bool isX = false;
    bool isY = false;
    size_t x = static_cast<size_t>(numberInput[0].toInt(&isX));
    size_t y = static_cast<size_t>(numberInput[1].toInt(&isY));
    if (!isX || !isY || x > (_world.size() - 1) || y > (_world.size() - 1)) {
        return false;
    }
    radio.move(x, y, _world.tile(x, y));
    return true;
}

bool Program::setRadioFrequency(Radio &radio) {
    auto numberInput = getUserInput().split(" ");
    if (numberInput.size() < 1) {
        return false;
    }
    bool isF = false;
    const size_t f = static_cast<size_t>(numberInput[0].toInt(&isF));
    if (!isF || f < (_world.minRadioFrequency()) || f > (_world.maxRadioFrequency())) {
        return false;
    }
    radio.setFrequency(f);
    return true;
}

void Program::broadcastRadioTowers() {
    for (const auto& radioTower : _world.radioTowers()) {
        radioTower->broadcast();
    }
}
