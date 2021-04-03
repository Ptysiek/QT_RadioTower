#pragma once

#include <memory>
#include <vector>
#include <QObject>

#include "Channel.h"


class RadioTower {
    Q_OBJECT

    size_t _x;
    size_t _y;
    size_t _range;
    std::vector<std::shared_ptr<Channel>> _channels;

public:
    RadioTower(size_t x, size_t y, size_t range);





};


