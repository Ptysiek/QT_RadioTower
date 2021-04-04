#pragma once

#include <memory>
#include <QObject>
#include <vector>

#include "Channel.h"


class RadioTower : public QObject {
    Q_OBJECT

    const std::string _id;
    const size_t _x;
    const size_t _y;
    const size_t _range;
    std::vector<Channel> _channels;

public:
    RadioTower(const std::string& id, size_t x, size_t y, size_t range);
    size_t x() const;
    size_t y() const;
    size_t range() const;
    void addChannel(const Channel&& channel);
    void broadcast() const;

signals:
    void signal(const std::vector<Channel>& channels) const;
};
