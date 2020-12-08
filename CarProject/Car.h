#pragma once

#include <string>
#include "VehicleSize.h"

enum class Color //перечисляемый тип данных, цвет машины
{
    BLACK,
    YELLOW,
    RED,
    PINK,
    BLUE
};

enum class EngineType // перчисляемый тип данных, тип двигателя
{
    DIESEL, // дизельный
    INJECTOR // инжекторный
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
    virtual std::string getFileName() = 0; //чисто виртуальная функция, так как имя файля у каждого свое
    virtual void writeAdditionalData(std::ofstream& ofs) = 0; //чисто виртуальная функция, так как доп характеристики у каждого свои
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
    virtual void display();
    void save();
};

