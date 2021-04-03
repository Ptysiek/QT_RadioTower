#pragma once

#include <vector>

#include "RadioTower.h"
#include "Tile.h"


class World {
    std::vector<std::vector<Tile>> _tiles;
    std::vector<RadioTower> _radioTowers;

public:
    World():
        _tiles(),
        _radioTowers()
    {}

private:
    std::vector<RadioTower> initRadioTowers() {

    }

    std::vector<<std::vector<Tile>> initTiles() {

    }

};
