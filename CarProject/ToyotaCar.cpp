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

void ToyotaCar::display() { //вывод машин
    cout << "Car type: Toyota" << endl;
    Car::display(); //вызываем display(), который отображает общие характеристики
    if (automaticTransmission) { //если АКПП, то печатем, что АКПП
        cout << "Automatic transmission" << endl;
    }
    else { //иначе
        cout << "Manual transmission" << endl;
    }
}

string ToyotaCar::getFileName() {
    return "toyota";
}

void ToyotaCar::writeAdditionalData(ofstream& ofs) {
    ofs << automaticTransmission << endl;
}