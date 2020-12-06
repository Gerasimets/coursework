#include "stdafx.h"
#include "KiaCar.h"
#include <iostream>
#include <fstream>

using namespace std;


KiaCar::KiaCar() {
}


KiaCar::~KiaCar() {
}

void KiaCar::setHeatedMirrors(bool value) {
    heatedMirrors = value;
}

void KiaCar::display() {
    cout << "Car type: KIA" << endl;
    Car::display();
    if (heatedMirrors) {
        cout << "Mirrors are heated" << endl;
    }
    else {
        cout << "Mirrors are not heated" << endl;
    }
}


string KiaCar::getFileName() {
    return "kia";
}

void KiaCar::writeAdditionalData(ofstream& ofs) {
    ofs << heatedMirrors << endl;
}