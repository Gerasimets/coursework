#pragma once

#include <string>
#include "VehicleSize.h"

enum Color //������������� ��� ������, ���� ������
{
    COLOR_BLACK,
    COLOR_YELLOW,
    COLOR_RED,
    COLOR_PINK,
    COLOR_BLUE
};

enum EngineType // ������������ ��� ������, ��� ���������
{
    ENGINE_TYPE_DIESEL, // ���������
    ENGINE_TYPE_INJECTOR // �����������
};

class Car 
{
    Color color; //����
    EngineType engineType; //��� ���������
    double engineVolume; // ����� ���������
    VehicleSize size; // �������� ������
    int yearOfBirthday; //��� ������� 
    int doorsCount; // ����� ������ 
    std::string model; //������
    std::string tireBrand; // ����� ���
    double trunkVolume; // ����� ���������
protected:
    Car(); //����������� ///// ������ �� � ���������?///////////////////////////
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

