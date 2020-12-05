#include "stdafx.h"
#include "Car.h"


Car::Car() // по умолчанию данные 
    : color(COLOR_BLACK),
    engineType(ENGINE_TYPE_INJECTOR),
    engineVolume(1.7),
    yearOfBirthday(2000),
    doorsCount(5),
    model("<Unknown>"),
    tireBrand("<Unknown>"),
    trunkVolume(450.0)
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

}
