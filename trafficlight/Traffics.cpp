#include "Traffics.h"

using namespace std;

static const int GREEN_MASK = 0;  // 001
static const int YELLOW_MASK = 1; // 010  
static const int RED_MASK = 2; // 100


void TrafficLight::setColor(int stateMask) {
    for (int i = 0; i < color.GetMaxPower(); i++) {
        color.DelElem(i);
    }
    for (int i = 0; i < color.GetMaxPower(); i++) {
        if (stateMask & (1 << i)) {
            color.InsElem(i);
        }
    }
}


bool TrafficLight::isBitSet(int bitPosition) const {
    return color.IsMember(bitPosition);
}

TrafficP::TrafficP() : TrafficLight(3) {
    setColor(1 << GREEN_MASK);
}
bool TrafficP::isRed() {
    return isBitSet(RED_MASK) || isBitSet(YELLOW_MASK);
}

bool TrafficP::isYellow() {
    return isBitSet(YELLOW_MASK);
}

bool TrafficP::isGreen() {
    return isBitSet(GREEN_MASK);
}

void TrafficP::next() {
    if (isGreen()) {
        setColor(1 << YELLOW_MASK);
    }
    else if (isYellow()) {
        setColor(1 << RED_MASK);
    }
    else {
        setColor(1 << GREEN_MASK);
    }
}

void TrafficP::print() {
    string bitString = "";
    for (int i = color.GetMaxPower() - 1; i >= 0; i--) {
        if (color.IsMember(i)) {
            bitString += "1";
        }
        else {
            bitString += "0";
        }
    }
    cout << bitString << "    ";
    if (isGreen()) cout << "pesh: Green" << endl;
    else cout << "pesh: Red" << endl;
}

TrafficA::TrafficA() : TrafficLight(3) {
}

bool TrafficA::isRed() {
    return isBitSet(RED_MASK);
}

bool TrafficA::isYellow() {
    return isBitSet(YELLOW_MASK);
}

bool TrafficA::isGreen() {
    return isBitSet(GREEN_MASK);
}

void TrafficA::next() {
    if (isGreen()) {
        setColor(1 << YELLOW_MASK);
    }
    else if (isYellow()) {
        setColor(1 << RED_MASK);
    }
    else {
        setColor(1 << GREEN_MASK);
    }

}

void TrafficA::print() {
    string bitString = "";
    for (int i = color.GetMaxPower() - 1; i >= 0; i--) {
        if (color.IsMember(i)) {
            bitString += "1";
        }
        else {
            bitString += "0";
        }
    }
    cout << bitString << "    ";
    if (isGreen()) cout << "avt: Green" << endl;
    else if (isYellow()) cout << "avt: Yellow" << endl;
    else cout << "avt: Red" << endl;
}




//using namespace std;
//// 00 - зеленый
//// 01 - красный
//// 10 - красный
//// 11 - красный
//TrafficP::TrafficP() : TrafficLight(2) {
//    color.ClrBit(1);
//    color.ClrBit(0);
//}
//
//bool TrafficP::isRed() {
//    return !(color.GetBit(1) == 0 && color.GetBit(0) == 0);
//}
//
//bool TrafficP::isYellow() {
//    return false;
//}
//
//bool TrafficP::isGreen() {
//    return (color.GetBit(1) == 0) && (color.GetBit(0) == 0);
//}
//
//void TrafficP::next() {
//    int bit1 = color.GetBit(1);
//    int bit0 = color.GetBit(0);
//
//    if (bit1 == 0 && bit0 == 0) {
//        color.SetBit(0);
//    }
//    else if (bit1 == 0 && bit0 == 1) {
//        color.ClrBit(0);
//        color.SetBit(1);
//    }
//    else if (bit1 == 1 && bit0 == 0) {
//        color.SetBit(0);
//    }
//    else {
//        color.ClrBit(1);
//        color.ClrBit(0);
//    }
//}
//
//void TrafficP::print() {
//    if (isGreen()) cout << "pesh: Green" << endl;
//    else cout << "pesh: Red" << endl;
//}
//
//// 00 - зеленый
//// 01 - желтый
//// 10 - красный
//// 11 - желтый
//TrafficA::TrafficA() : TrafficLight(2) {
//    color.SetBit(1);
//    color.ClrBit(0);
//}
//
//bool TrafficA::isRed() {
//    return (color.GetBit(1) == 1) && (color.GetBit(0) == 0);
//}
//
//bool TrafficA::isYellow() {
//    return (color.GetBit(0) == 1);
//}
//
//bool TrafficA::isGreen() {
//    return (color.GetBit(1) == 0) && (color.GetBit(0) == 0);
//}
//
//void TrafficA::next() {
//    int bit1 = color.GetBit(1);
//    int bit0 = color.GetBit(0);
//
//    if (bit1 == 0 && bit0 == 0) {
//        color.SetBit(0);
//    }
//    else if (bit1 == 0 && bit0 == 1) {
//        color.ClrBit(0);
//        color.SetBit(1);
//    }
//    else if (bit1 == 1 && bit0 == 0) {
//        color.SetBit(0);
//    }
//    else {
//        color.ClrBit(1);
//        color.ClrBit(0);
//    }
//}
//
//void TrafficA::print() {
//    if (isGreen()) cout << "avt: Green" << endl;
//    else if (isYellow()) cout << "avt: Yellow" << endl;
//    else cout << "avt: Red" << endl;
//}
