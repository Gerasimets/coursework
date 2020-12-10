#pragma once

#include "Car.h"

class CarBuilder {
protected:
    Car *car; // ������� ��������� ���� car
    CarBuilder();
public:
    virtual ~CarBuilder();
    virtual void reset() = 0; // ����� ����������� �������
    /*��� ��������� ������*/
    void setColor(Color value);
    void setEngineType(EngineType value);
    void setSize(VehicleSize value);
    void setYearOfBirthday(int value);
    void setDoorsCount(int value);
    void setModel(std::string value);
    void setTireBrand(std::string value);
    void setTrunkVolume(double value);
    void setEngineVolume(double value);
    Car *getResult(); //
};
