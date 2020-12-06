#include "stdafx.h"
#include "VazCar.h"
#include <iostream>
#include <fstream>

using namespace std;

VazCar::VazCar() {
}

VazCar::~VazCar() {
}

void VazCar::setTrunkOnRoof(bool value) {
    trunkOnRoof = value;
}

void VazCar::display() {
    cout << "Car type: VAZ" << endl;
    Car::display();
    if (trunkOnRoof) {
        cout << "Trunk is on roof" << endl;
    }
    else {
        cout << "Trunk is not on roof" << endl;
    }
}

string VazCar::getFileName() {
    return "vaz";
}

void VazCar::writeAdditionalData(ofstream& ofs) {
    ofs << trunkOnRoof << endl;
}