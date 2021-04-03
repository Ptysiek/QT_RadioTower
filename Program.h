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

    void execute() {
       // auto userInput = getUserInput();

        _map.lookup(_world);
/*
        while (true) {
            if (userInput == "") {

            }
        }*/
    }

private:
    QString getUserInput() {
        QTextStream stream(stdin);
        QString line = stream.readLine();
        return line.trimmed().toUpper();
    }


};

