#pragma once
#include <memory>
#include <vector>

#include "RadioTower.h"


struct Tile {
    std::vector<std::weak_ptr<RadioTower>> _towersInRange;

    bool empty() const { return _towersInRange.empty(); }
    size_t contentSize() const { return _towersInRange.size(); }
};
