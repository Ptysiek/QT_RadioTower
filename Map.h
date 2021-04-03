#pragma once

#include <QDebug>

#include "World.h"
//#include "Radio.h"


class Map {
public:
    void lookup(const World& world) const {
        for (const auto& row : world.tiles()) {
            QString str;
            for (const auto& tile : row) {
                str += " ";
                str += QString::number(tile.contentSize());
                //qInfo() << " a";// << ;
            }
            qInfo() << str;
        }
    }
};
