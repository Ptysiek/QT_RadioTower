#include "RadioTower.h"


RadioTower::RadioTower(size_t x, size_t y, size_t range):
    _x(x),
    _y(y),
    _range(range)
{}

size_t RadioTower::x() const
{
    return _x;
}

size_t RadioTower::y() const
{
    return _y;
}

size_t RadioTower::range() const
{
    return _range;
}
