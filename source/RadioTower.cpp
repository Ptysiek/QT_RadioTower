#include "RadioTower.h"


RadioTower::RadioTower(const std::string& id, size_t x, size_t y, size_t range):
    _id(id),
    _x(x),
    _y(y),
    _range(range)
{}

size_t RadioTower::x() const {
    return _x;
}

size_t RadioTower::y() const {
    return _y;
}

size_t RadioTower::range() const {
    return _range;
}

void RadioTower::addChannel(const Channel &&channel) {
    _channels.emplace_back(channel);
}

void RadioTower::broadcast() const {
    emit signal(_channels);
}
