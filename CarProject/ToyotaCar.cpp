#include "stdafx.h"
#include "ToyotaCar.h"
#include <iostream>
#include <fstream>

using namespace std;

ToyotaCar::ToyotaCar() {
}

ToyotaCar::~ToyotaCar() {
}

void ToyotaCar::setAutomaticTransmission(bool value) {
    automaticTransmission = value;
}

void ToyotaCar::display() {
    cout << "Car type: Toyota" << endl;
    Car::display();
    if (automaticTransmission) {
        cout << "Automatic transmission" << endl;
    }
    else {
        cout << "Manual transmission" << endl;
    }
}

string ToyotaCar::getFileName() {
    return "toyota";
}

void ToyotaCar::writeAdditionalData(ofstream& ofs) {
    ofs << automaticTransmission << endl;
}