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
        auto& radio = _world.radio();
        while (true) {
            showUserInterface();
            auto userInput = getUserInput().trimmed().toUpper();

            if (userInput == "M") {
                _map.lookup(_world);
            }
            else if (userInput == "RL") {
                listenToRadio(radio);
            }
            else if (userInput == "RT") {
                auto result = radio.turnRadio();
                qInfo() << " radio is now " << ((result)? "ON" : "OFF");
            }
            else if (userInput == "RM") {
                qInfo() << " enter radio position x y: ";
                if (moveRadio(radio, _world.size())) {
                    listenToRadio(radio);
                }
                else {
                    qInfo() << " incorrect data typed";
                }
            }
            else if (userInput == "RS") {
                qInfo() << " enter radio frequency: ";
                listenToRadio(radio);
            }
            else if (userInput == "RA") {
                listenToRadio(radio);
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
    void showUserInterface() {
        qInfo() << " _________________________________________\n"
            << " [m] -> show map\n"
            << " [rl] -> listen radio\n"
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
        qInfo(" radio: \"%s\"", radio.listen().c_str());
    }

    bool moveRadio(Radio& radio, const size_t worldSize) {
        auto numberInput = getUserInput().split(" ");
        if (numberInput.size() < 2) {
            return false;
        }
        bool isA = false;
        bool isB = false;
        size_t a = static_cast<size_t>(numberInput[0].toInt(&isA));
        size_t b = static_cast<size_t>(numberInput[1].toInt(&isB));
        if (!isA || !isB || a > (worldSize - 1) || b > (worldSize - 1)) {
            return false;
        }
        radio.move(a, b);
        return true;
    }
};

