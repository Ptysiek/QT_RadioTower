#pragma once

#include <QDebug>

#include "World.h"

class Program {
    World _world;


public:
    Program():
        _world()
    {}

    void execute() {
        auto userInput = getUserInput();

        while (true) {
            if (userInput == "") {

            }
        }
    }

private:
    QString getUserInput() {
        QTextStream stream(stdin);
        QString line = stream.readLine();
        return line.trimmed().toUpper();
    }
};

