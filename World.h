#pragma once

#include <vector>

#include "RadioTower.h"
#include "Tile.h"


class World {
    const size_t _matrixSize;
    std::vector<std::vector<Tile>> _tiles;
    std::vector<RadioTower> _radioTowers;

public:
    World();

private:
    std::vector<std::vector<Tile>> initTiles();
    std::vector<RadioTower> initRadioTowers();
};
