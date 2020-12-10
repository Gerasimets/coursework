#include "stdafx.h"
#include "CarBuilder.h"

enum class Color;
enum class EngineType; /////////////////////////////////////////////////////////////

CarBuilder::CarBuilder() : car(nullptr) {
}

CarBuilder::~CarBuilder() {
}

//значение, которе получили задаем в качестве нового для нашей машины
void CarBuilder::setColor(Color value) {
    car->setColor(value);
}

void CarBuilder::setEngineType(EngineType value) {
    car->setEngineType(value); 
}

void CarBuilder::setSize(VehicleSize value) {
    car->setSize(value);
}

void CarBuilder::setYearOfBirthday(int value) {
    car->setYearOfBirthday(value);
}

void CarBuilder::setDoorsCount(int value) {
    car->setDoorsCount(value);
}

void CarBuilder::setModel(std::string value) {
    car->setModel(value);
}

void CarBuilder::setTireBrand(std::string value) {
    car->setTireBrand(value);
}

void CarBuilder::setTrunkVolume(double value) {
    car->setTrunkVolume(value);
}

void CarBuilder::setEngineVolume(double value) {
    car->setEngineVolume(value);
}

Car *CarBuilder::getResult() {
    return car; //возвращает адрес того, где хранится машина
}