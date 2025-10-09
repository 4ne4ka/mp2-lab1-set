#include "Traffics.h"

using namespace std;
// 00 - зеленый
// 01 - красный
// 10 - красный
// 11 - красный
TrafficP::TrafficP() : TrafficLight(2) {
    color.SetBit(0);
    color.ClrBit(1);
}

bool TrafficP::isRed() {
    return (color.GetBit(1) == 1) || (color.GetBit(0) == 1);
}

bool TrafficP::isYellow() {
    return false;
}

bool TrafficP::isGreen() {
    return (color.GetBit(1) == 0) && (color.GetBit(0) == 0);
}

void TrafficP::next() {
    int bit1 = color.GetBit(1);
    int bit0 = color.GetBit(0);

    if (bit1 == 0 && bit0 == 0) {
        color.SetBit(0);
    }
    else if (bit1 == 0 && bit0 == 1) {
        color.ClrBit(0);
        color.SetBit(1);
    }
    else if (bit1 == 1 && bit0 == 0) {
        color.SetBit(0);
    }
    else {
        color.ClrBit(1);
        color.ClrBit(0);
    }
}

void TrafficP::print() {
    if (isGreen()) cout << "pesh: Green" << endl;
    else cout << "pesh: Red" << endl;
}

// 00 - зеленый
// 01 - желтый
// 10 - красный
// 11 - желтый
TrafficA::TrafficA() : TrafficLight(2) {
    color.SetBit(1);
    color.ClrBit(0);
}

bool TrafficA::isRed() {
    return (color.GetBit(1) == 1) && (color.GetBit(0) == 0);
}

bool TrafficA::isYellow() {
    return (color.GetBit(0) == 1) ||
        (color.GetBit(1) == 1 && color.GetBit(0) == 1);
}

bool TrafficA::isGreen() {
    return (color.GetBit(1) == 0) && (color.GetBit(0) == 0);
}

void TrafficA::next() {
    int bit1 = color.GetBit(1);
    int bit0 = color.GetBit(0);

    if (bit1 == 0 && bit0 == 0) {
        color.SetBit(0);
    }
    else if (bit1 == 0 && bit0 == 1) {
        color.ClrBit(0);
        color.SetBit(1);
    }
    else if (bit1 == 1 && bit0 == 0) {
        color.SetBit(0);
    }
    else {
        color.ClrBit(1);
        color.ClrBit(0);
    }
}

void TrafficA::print() {
    if (isGreen()) cout << "avt: Green" << endl;
    else if (isYellow()) cout << "avt: Yellow" << endl;
    else cout << "avt: Red" << endl;
}
