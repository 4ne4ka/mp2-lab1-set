#include "Road.h"
#include <iostream>
using namespace std;

void Road::begin(TrafficA& avt, TrafficP& pesh, int time) {
    while (!avt.isRed()) {
        avt.next();
    }
    while (!pesh.isGreen()) {
        pesh.next();
    }

    cout << "Begin:" << endl;
    avt.print();
    pesh.print();
    cout << "----------" << endl;

    for (int i = 0; i < time; i++) {
        avt.next();
        pesh.next();

        avt.print();
        pesh.print();
        cout << "----------" << endl;
    }
}