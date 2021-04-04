#pragma once
#include <string>
#include <QObject>
#include <vector>

#include "Tile.h"
#include "Channel.h"


class Radio : public QObject {
    Q_OBJECT

    const size_t _minRadioFrequency;
    const size_t _maxRadioFrequency;
    size_t _x;
    size_t _y;
    size_t _currentFrequency;
    bool _isOn;
    Tile _lastlyConnected;
    using ChannelID = std::string;
    std::map<ChannelID, Channel> _channels;

public:
    Radio(size_t minFrequency, size_t maxFrequency);
    size_t x() const;
    size_t y() const;
    size_t frequency() const;
    bool isOn() const;
    void setFrequency(const size_t frequency);
    bool autoSetFrequency();
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

