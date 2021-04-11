#pragma once
#include <string>
#include <QDebug>

#include "Radio.h"
#include "World.h"


class Map {
public:
    void lookup(const World& world) const;

private:
    void drawMap(const World& world) const;
    void drawRadioInfo(const World& world) const;
};
