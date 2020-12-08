#include "stdafx.h"
#include "NissanCar.h"
#include <iostream>
#include <fstream>

using namespace std;


NissanCar::NissanCar() : heatedSeats(false) {
}


NissanCar::~NissanCar() {
}

void NissanCar::setHeatedSeats(bool value) {
    heatedSeats = value;
}

void NissanCar::display() { // вывод машин 
    cout << "Car type: Nissan" << endl;
    Car::display(); //вызываем display(), который отображает общие характеристики
    if (heatedSeats) { //если есть подогрев сидений, то
        cout << "With heated seats" << endl; //печтаем это
    }
    else { //иначе...
        cout << "Seats are not heated" << endl;
    }
}

string NissanCar::getFileName() {
    return "nissan";
}

void NissanCar::writeAdditionalData(ofstream& ofs) {
    ofs << heatedSeats << endl;
}