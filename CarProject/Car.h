#pragma once

#include <string>
#include "VehicleSize.h"

enum Color //перечисляемый тип данных, цвет машины
{
    COLOR_BLACK,
    COLOR_YELLOW,
    COLOR_RED,
    COLOR_PINK,
    COLOR_BLUE
};

enum EngineType // перчисляемый тип данных, тип двигателя
{
    ENGINE_TYPE_DIESEL, // дизельный
    ENGINE_TYPE_INJECTOR // инжекторный
};

class Car 
{
    Color color; //цвет
    EngineType engineType; //тип двигателя
    double engineVolume; // объем двигателя
    VehicleSize size; // габариты машины
    int yearOfBirthday; //год выпуска 
    int doorsCount; // число дверей 
    std::string model; //модель
    std::string tireBrand; // марка шин
    double trunkVolume; // объем багажника
protected:
    Car(); //конструктор ///// почему он в протектед?///////////////////////////
public:
    virtual ~Car();
    void setColor(Color value); 
    void setEngineType(EngineType value);
    void setSize(VehicleSize value);
    void setYearOfBirthday(int value);
    void setDoorsCount(int value);
    void setModel(std::string value);
    void setTireBrand(std::string value);
    void setTrunkVolume(double value);
};

