#include "stdafx.h"
#include "NissanCar.h"
#include <iostream>
#include <fstream>

using namespace std;


NissanCar::NissanCar() {
}


NissanCar::~NissanCar() {
}

void NissanCar::setHeatedSeats(bool value) {
    heatedSeats = value;
}

void NissanCar::display() {
    cout << "Car type: Nissan" << endl;
    Car::display();
    if (heatedSeats) {
        cout << "With heated seats" << endl;
    }
    else {
        cout << "Seats are not heated" << endl;
    }
}

string NissanCar::getFileName() {
    return "nissan";
}

void NissanCar::writeAdditionalData(ofstream& ofs) {
    ofs << heatedSeats << endl;
}