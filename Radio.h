#pragma once
#include <memory>
#include <string>
#include <QObject>
#include <QDebug>
#include <vector>

#include "Tile.h"
#include "Channel.h"


class Radio : public QObject {
    Q_OBJECT

    size_t _x;
    size_t _y;
    size_t _currentFrequency;
    bool _isOn;
    Tile _lastlyConnected;
    using ChannelID = std::string;
    std::map<ChannelID, Channel> _channels;

public:
    Radio();

    size_t x() const;
    size_t y() const;
    size_t frequency() const;
    bool isOn() const;
    void setFrequency(const size_t frequency);

    bool turnRadio();
    void move(const size_t x, const size_t y, const Tile& tile);
    std::string play() const;

public slots:
    void onSignal(const std::vector<Channel>& channels);

private:
    std::string browseChannels() const;
    void disconnectAll();
    void connectAll();
};

