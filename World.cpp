#include "World.h"

World::World():
    _matrixSize(100),
    _tiles(initTiles()),
    _radioTowers(initRadioTowers())
{}

std::vector<std::vector<Tile> > World::initTiles() {
    std::vector<std::vector<Tile>> rows(_matrixSize);
    for (auto& row : rows) {
        row.resize(_matrixSize);
    }
    return rows;
}

std::vector<RadioTower> World::initRadioTowers() {
    return {{2,13,5}, {52,60,4}, {18,60,11}, {86,96,58}, {66,15,49}};
}
