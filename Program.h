#pragma once
#include <QDebug>

#include "Map.h"
#include "World.h"


class Program {
    Map _map;
    World _world;

public:
    Program();
    bool execute();

private:
    void updateWorld();
    void showSeparator();
    void showInstructionToUserInterface();
    void showUserInterface();
    QString getUserInput();
    void listenToRadio(const Radio& radio);
    bool moveRadio(Radio& radio);
    bool setRadioFrequency(Radio& radio);
    void broadcastRadioTowers();
};

