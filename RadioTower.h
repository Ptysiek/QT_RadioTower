#pragma once

#include <memory>
#include <vector>
#include <QObject>

#include "Channel.h"


class RadioTower : public QObject {
    Q_OBJECT

    const size_t _x;
    const size_t _y;
    const size_t _range;
    std::vector<std::shared_ptr<Channel>> _channels;

public:
    RadioTower(size_t x, size_t y, size_t range);
    size_t x() const;
    size_t y() const;
    size_t range() const;
};
