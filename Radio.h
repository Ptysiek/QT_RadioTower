#pragma once
#include <memory>
#include <string>
#include <QObject>
#include <QDebug>

#include "Tile.h"


class Radio : public QObject {
    Q_OBJECT

    size_t _x;
    size_t _y;
    size_t _currentFrequency;
    bool _isOn;
    Tile _lastlyConnected;

    struct RadioData {
        std::vector<std::string> _radioTowerID;

    };
    using ChannelID = std::string;
    std::map<ChannelID, RadioData> _channels;

public:
    Radio();

    size_t x() const;
    size_t y() const;
    size_t frequency() const;
    bool isOn() const;
    void setFrequency(const size_t frequency);

    bool turnRadio() {
        _isOn = !_isOn;
        return _isOn;
    }

    std::string listen() const {
        if (!_isOn) {
            return "...";
        }
        return std::string();
    }

    void move(const size_t x, const size_t y, const Tile& tile) {
        _x = x;
        _y = y;
        disconnectAll();
        _lastlyConnected = tile;
        connectAll();
    }

public slots:
    void onSignal() {
        qInfo("%s", listen().c_str());
    }

private:
    void disconnectAll() {
        for (auto& radioTower : _lastlyConnected._towersInRange) {
            if (radioTower.expired()) {
                continue;
            }
            this->disconnect(std::shared_ptr<RadioTower>{radioTower}.get(), &RadioTower::signal, this, &Radio::onSignal);
        }
    }
    void connectAll() {
        for (auto& radioTower : _lastlyConnected._towersInRange) {
            if (radioTower.expired()) {
                continue;
            }
            this->connect(std::shared_ptr<RadioTower>{radioTower}.get(), &RadioTower::signal, this, &Radio::onSignal);
        }
    }
};

