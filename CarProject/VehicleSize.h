#pragma once
class VehicleSize //класс габаритов машины
{
    int x; //длина
    int y; // ширина
    int z; //высота
public:
    VehicleSize(); //конструктор
    VehicleSize(int x, int y, int z); //конструктор с параметром
    virtual ~VehicleSize(); //виртуальный диструктор
    /*получаем данные*/
    int getX(); 
    int getY();
    int getZ();
};

