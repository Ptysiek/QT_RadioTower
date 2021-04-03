#include "World.h"

World::World():
    _matrixSize(20),
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
    const int smallRange = _matrixSize / 4;
    const int mediumRange = (_matrixSize * 2) / 3;
    const int fullRange = _matrixSize;

    return { std::make_shared<RadioTower>(random(0, fullRange), random(0, fullRange), random(2, smallRange)),
                std::make_shared<RadioTower>(random(0, fullRange), random(0, fullRange), random(2, smallRange)),
                std::make_shared<RadioTower>(random(0, fullRange), random(0, fullRange), random(smallRange, mediumRange)),
                std::make_shared<RadioTower>(random(0, fullRange), random(0, fullRange), random(smallRange, mediumRange)),
                std::make_shared<RadioTower>(random(0, fullRange), random(0, fullRange), random(mediumRange, fullRange)),
                std::make_shared<RadioTower>(random(0, fullRange), random(0, fullRange), random(mediumRange, fullRange)) };
}

int World::random(int a, int b) const {
    return QRandomGenerator::global()->bounded(a, b);
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
