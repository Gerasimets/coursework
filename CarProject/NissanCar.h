#pragma once
#include "Car.h"
class NissanCar : public Car {
    bool heatedSeats; //�������� �������
public:
    NissanCar();
    virtual ~NissanCar();
    void setHeatedSeats(bool value); //������� ������ �� ������ - ����������� ������� �������� �������
};

