#include "World.h"

World::World():
    _matrixSize(100),
    _tiles(initTiles()),
    _radioTowers(initRadioTowers())
{}

std::vector<std::vector<Tile> > World::initTiles() const {
    std::vector<std::vector<Tile>> rows(_matrixSize);
    for (auto& row : rows) {
        row.resize(_matrixSize);
    }
    return rows;
}

std::vector<std::shared_ptr<RadioTower>> World::initRadioTowers() const {
    return { std::make_shared<RadioTower>(2,13,5),
                std::make_shared<RadioTower>(52,60,4),
                std::make_shared<RadioTower>(18,60,11),
                std::make_shared<RadioTower>(86,96,58),
                std::make_shared<RadioTower>(66,15,49) };
}
