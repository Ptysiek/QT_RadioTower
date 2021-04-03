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
            auto userInput = getUserInput();

            if (userInput == "M") {
                _map.lookup(_world);
            }

            if (userInput == "Q") {
                qInfo() << "quiting program..";
                return false;
            }
            if (userInput == "R") {
                qInfo() << "restarting program..";
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
            << " [ra] -> auto-tune radio frequency\n";
        qInfo() << "  [q] -> quit program\n"
            << " [r] -> restart program\n";
    }

    QString getUserInput() {
        QTextStream stream(stdin);
        QString line = stream.readLine();
        return line.trimmed().toUpper();
    }
};

