#pragma once

#include <QDebug>

#include "Map.h"
#include "World.h"


class Program {
    Map _map;
    World _world;

public:
    Program():
        _map(),
        _world()
    {}

    bool execute() {
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
                qInfo() << " enter radio frequency: ";
            }
            else if (userInput == "RA") {
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

private:
    void updateWorld() {
        showSeparator();
        listenToRadio(_world.radio());
        showInstructionToUserInterface();
        broadcastRadioTowers();
    }

    void showSeparator() {
        qInfo() << " _________________________________________";
    }
    void showInstructionToUserInterface() {
        qInfo() << " [u] -> show user interface\n";
    }

    void showUserInterface() {
        qInfo() << "  [m] -> show map\n"
            << " [rt] -> turn radio on / off\n"
            << " [rm] -> move radio\n"
            << " [rs] -> set radio frequency\n"
            << " [ra] -> auto-tune radio frequency\n\n"
            << " [q] -> quit program\n"
            << " [r] -> restart program\n";
    }

    QString getUserInput() {
        QTextStream stream(stdin);
        QString line = stream.readLine();
        return line;
    }

    void listenToRadio(const Radio& radio) {
        qInfo(" radio says: \"%s\"", radio.play().c_str());
    }

    bool moveRadio(Radio& radio) {
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

    void broadcastRadioTowers() {
        for (const auto& radioTower : _world.radioTowers()) {
            radioTower->broadcast();
        }
    }
};

