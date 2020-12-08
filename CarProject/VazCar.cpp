#include "stdafx.h"
#include "VazCar.h"
#include <iostream>
#include <fstream>

using namespace std;

VazCar::VazCar() : trunkOnRoof(false) {
}

VazCar::~VazCar() {
}

void VazCar::setTrunkOnRoof(bool value) {
    trunkOnRoof = value;
}

void VazCar::display() { //вывод машин
    cout << "Car type: VAZ" << endl;
    Car::display(); //вызываем display(), который отображает общие характеристики
    if (trunkOnRoof) { //если есть багажник на крыше, то
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