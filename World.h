#pragma once

#include <exception>
#include <memory>
#include <vector>
#include <QRandomGenerator>

#include "RadioTower.h"
#include "Tile.h"


class World {
    const size_t _matrixSize;
    std::vector<std::vector<Tile>> _tiles;
    std::vector<std::shared_ptr<RadioTower>> _radioTowers;

public:
    World();

    const std::vector<std::vector<Tile>>& tiles() const { return _tiles; }
    Tile& tile(size_t x, size_t y);
    bool setTile(size_t x, size_t y, std::shared_ptr<RadioTower> radioTower);

private:
    std::vector<std::vector<Tile>> initTiles() const;
    std::vector<std::shared_ptr<RadioTower>> initRadioTowers() const;
    int random(int a, int b) const;
    void putRadioTowersOnTiles();
    void setTiles(std::shared_ptr<RadioTower> radioTower);
};
