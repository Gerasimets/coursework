#pragma once
#include "Car.h"
class VazCar : public Car {
    bool trunkOnRoof; //�������� �� �����
public:
    VazCar();
    virtual ~VazCar();
    void setTrunkOnRoof(bool value); //����������� ���������� �������� �� �����
};

