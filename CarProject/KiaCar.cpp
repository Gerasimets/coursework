#include "stdafx.h"
#include "KiaCar.h"
#include <iostream>
#include <fstream>

using namespace std;


KiaCar::KiaCar() : heatedMirrors(false) {
}


KiaCar::~KiaCar() {
}

void KiaCar::setHeatedMirrors(bool value) {
    heatedMirrors = value;
}

void KiaCar::display() { // вывод машин 
    cout << "Car type: KIA" << endl; 
    Car::display(); //вызываем display(), который отображает общие характеристики
    if (heatedMirrors) { //если есть подогрев зеркал, то...
        cout << "Mirrors are heated" << endl; // печатем это
    }
    else { //иначе...
        cout << "Mirrors are not heated" << endl;
    }
}


string KiaCar::getFileName() {
    return "kia"; //возвращает имя файла
}

void KiaCar::writeAdditionalData(ofstream& ofs) {
    ofs << heatedMirrors << endl;
}