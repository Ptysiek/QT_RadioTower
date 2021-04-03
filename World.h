#pragma once

#include <exception>
#include <memory>
#include <vector>

#include "RadioTower.h"
#include "Tile.h"


class World {
    const size_t _matrixSize;
    std::vector<std::vector<Tile>> _tiles;
    std::vector<std::shared_ptr<RadioTower>> _radioTowers;

public:
    World();

    Tile& tile(size_t x, size_t y) {
        return _tiles.at(y).at(x);
    }

    bool setTile(size_t x, size_t y, std::shared_ptr<RadioTower> radioTower) {
        try {
            auto& choosenTile = tile(x, y);
            choosenTile._towersInRange.push_back(radioTower);
            return true;
        }
        catch (const std::out_of_range& e) {
            return false;
        }
    }

private:
    std::vector<std::vector<Tile>> initTiles() const;
    std::vector<std::shared_ptr<RadioTower>> initRadioTowers() const;

    void putRadioTowersOnTiles() {
        for (auto& radioTower : _radioTowers) {
            setTiles(radioTower);
        }
    }

    void setTiles(std::shared_ptr<RadioTower> radioTower) {
        const int startX = static_cast<int>(radioTower->x());
        const int startY = static_cast<int>(radioTower->y());
        const int range = static_cast<int>(radioTower->range());

        for (int row = startY - range; row < startY + range; ++row) {
            for (int col = startX - range; col < startX + range; ++col) {
                setTile(col, row, radioTower);
            }
        }
    }
};
