#include "stdafx.h"
#include "Car.h"
#include <fstream>
#include <iostream>

using namespace std;

Car::Car() // по умолчанию данные 
    : color(Color::BLACK),
    engineType(EngineType::INJECTOR),
    yearOfBirthday(2000),
    doorsCount(5),
    model("<Unknown>"),
    tireBrand("<Unknown>"),
    trunkVolume(450.0),
    engineVolume(1.7)
{
}

Car::~Car() {
}

void Car::setColor(Color value) {
    color = value;
}

void Car::setEngineType(EngineType value) {
    engineType = value;
}

void Car::setSize(VehicleSize value) {
    size = value;
}

void Car::setYearOfBirthday(int value) {
    yearOfBirthday = value;
}

void Car::setDoorsCount(int value) {
    doorsCount = value;
}

void Car::setModel(std::string value) {
    model = value;
}

void Car::setTireBrand(std::string value) {
    tireBrand = value;
}

void Car::setTrunkVolume(double value) {
    trunkVolume = value;
}

void Car::setEngineVolume(double value) {
    engineVolume = value;
}

void Car::display() { //отображает общие характеристики
    string colorStr;
    if (color == Color::BLACK) {
        colorStr = "black";
    }
    else if (color == Color::BLUE) {
        colorStr = "blue";
    }
    else if (color == Color::PINK) {
        colorStr = "pink";
    }
    else if (color == Color::RED) {
        colorStr = "red";
    }
    else if (color == Color::YELLOW) {
        colorStr = "yellow";
    }
    string engineTypeStr;
    if (engineType == EngineType::DIESEL) {
        engineTypeStr = "diesel";
    }
    else {
        engineTypeStr = "injector";
    }
    cout << "Color: " << colorStr << endl;
    cout << "Engine type: " << engineTypeStr << endl;
    cout << "Length: " << size.getX() << "cm" << endl;
    cout << "Width: " << size.getY() << "cm" << endl;
    cout << "Height: " << size.getZ() << "cm" << endl;
    cout << "Year of creation: " << yearOfBirthday << endl;
    cout << "Doors count: " << doorsCount << endl;
    cout << "Model: " << model << endl;
    cout << "Tire brand: " << tireBrand << endl;
    cout << "Trunk volume: " << trunkVolume << endl;
    cout << "Engine volume: " << engineVolume << endl;
}

void Car::save() { //запись машин в файл
    ofstream ofs;
    ofs.open(getFileName(), std::ios::app); //открываем файл для записи в конец
    if (!ofs.is_open()) { //если не удалось открыть
        cerr << "Failed to open file " << getFileName() << endl; //выводим какой файл не удалось открыть
        return;
    }
    /*если открыть удалось, заносим данные в файл*/
    ofs << (int)color << endl;
    ofs << (int)engineType << endl;
    ofs << size.getX() << endl;
    ofs << size.getY() << endl;
    ofs << size.getZ() << endl;
    ofs << yearOfBirthday << endl;
    ofs << doorsCount << endl;
    ofs << model << endl;
    ofs << tireBrand << endl;
    ofs << trunkVolume << endl;
    ofs << engineVolume << endl;
    writeAdditionalData(ofs);
    ofs.close(); //закрываем файл
}