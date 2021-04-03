#pragma once

#include <exception>
#include <memory>
#include <QRandomGenerator>
#include <vector>

#include "Radio.h"
#include "RadioTower.h"
#include "Tile.h"


class World {
    const size_t _matrixSize;
    Radio _radio;
    std::vector<std::vector<Tile>> _tiles;
    std::vector<std::shared_ptr<RadioTower>> _radioTowers;

public:
    World();

    const Radio& radio() const { return _radio; }
    const std::vector<std::vector<Tile>>& tiles() const;
    const Tile& tile(size_t x, size_t y) const;
    bool setTile(size_t x, size_t y, std::shared_ptr<RadioTower> radioTower);

private:
    Radio initRadio() const;
    std::vector<std::vector<Tile>> initTiles() const;
    std::vector<std::shared_ptr<RadioTower>> initRadioTowers() const;
    int random(int a, int b) const;
    void putRadioTowersOnTiles();
    void setTiles(std::shared_ptr<RadioTower> radioTower);
};
