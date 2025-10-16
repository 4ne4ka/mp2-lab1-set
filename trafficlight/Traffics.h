#include <iostream>
#include <stdint.h>
#include "tset.h"

class TrafficLight {
protected:
    TSet color;
    //TBitField color;
public:

    virtual bool isRed() = 0;
    virtual bool isYellow() = 0;
    virtual bool isGreen() = 0;
    virtual void next() = 0;
    virtual void print() = 0;
    TrafficLight(int size) : color(size) {}
    virtual ~TrafficLight() = default;

    void setColor(int stateMask);
    bool getColor(int stateMask) const;
};

class TrafficP : public TrafficLight {
public:
    TrafficP();
    bool isRed() override;
    bool isYellow() override;
    bool isGreen() override;
    void next() override;
    void print() override;
};

class TrafficA : public TrafficLight {
public:
    TrafficA();
    bool isRed() override;
    bool isYellow() override;
    bool isGreen() override;
    void next() override;
    void print() override;
};