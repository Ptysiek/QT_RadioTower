#pragma once

#include <memory>
#include <vector>

#include "RadioTower.h"


struct Tile {
    std::vector<std::shared_ptr<RadioTower>> _towersInRange;
};
