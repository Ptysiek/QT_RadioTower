#pragma once

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

    bool setTile(size_t x, size_t y, const RadioTower* const radioTower) {
        try {
            tile(x, y)._towersInRange.emplace_back(radioTower);
            return true;
        }
        catch (std::out_of_range) {
            return false;
        }
    }

private:
    std::vector<std::vector<Tile>> initTiles() const;
    std::vector<std::shared_ptr<RadioTower>> initRadioTowers() const;

    void putRadioTowersOnTiles() {
        for (auto& radioTower : _radioTowers) {
            setTiles(radioTower.get());
        }
    }

    void setTiles(const RadioTower* const radioTower) {
        //const size_t startX = radioTower->
    }
};
