#include "World.h"

World::World():
    _matrixSize(100),
    _tiles(initTiles()),
    _radioTowers(initRadioTowers())
{
    putRadioTowersOnTiles();
}

Tile &World::tile(size_t x, size_t y) {
    return _tiles.at(y).at(x);
}

bool World::setTile(size_t x, size_t y, std::shared_ptr<RadioTower> radioTower) {
    try {
        auto& choosenTile = tile(x, y);
        choosenTile._towersInRange.push_back(radioTower);
        return true;
    }
    catch (const std::out_of_range& e) {
        return false;
    }
}

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

void World::putRadioTowersOnTiles() {
    for (auto& radioTower : _radioTowers) {
        setTiles(radioTower);
    }
}

void World::setTiles(std::shared_ptr<RadioTower> radioTower) {
    const int startX = static_cast<int>(radioTower->x());
    const int startY = static_cast<int>(radioTower->y());
    const int range = static_cast<int>(radioTower->range());

    for (int row = startY - range; row < startY + range; ++row) {
        for (int col = startX - range; col < startX + range; ++col) {
            setTile(col, row, radioTower);
        }
    }
}
