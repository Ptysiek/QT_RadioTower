#pragma once

#include <QObject>

class Radio : public QObject {
    Q_OBJECT

    size_t _x;
    size_t _y;
    size_t _currentFrequency;
    bool _isOn;

public:
    Radio():
        _x(),
        _y(),
        _currentFrequency(),
        _isOn(false)
    {}

    size_t x() const { return _x; }
    size_t y() const { return _y; }
    size_t frequency() const { return _currentFrequency; }
    bool isOn() const { return _isOn; }

    void setX(const size_t x) { _x = x; }
    void setY(const size_t y) { _y = y; }
    void setFrequency(const size_t frequency) { _currentFrequency = frequency; }
};

