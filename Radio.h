#pragma once

#include <QObject>

class Radio : public QObject {
    Q_OBJECT

    size_t _x;
    size_t _y;
    size_t _currentFrequency;
    bool _isOn;

public:
    Radio(size_t x, size_t y, size_t frequency):
        _x(x),
        _y(y),
        _currentFrequency(frequency),
        _isOn(false)
    {}

    Radio(const Radio& radio):
        _x(radio.x()),
        _y(radio.y()),
        _currentFrequency(radio.frequency()),
        _isOn(radio.isOn())
    {}

    size_t x() const { return _x; }
    size_t y() const { return _y; }
    size_t frequency() const { return _currentFrequency; }
    bool isOn() const { return _isOn; }


};

