#pragma once
#include "Car.h"
class ToyotaCar : public Car 
{
    bool automaticTransmission; // �������������� ������� �������
public:
    ToyotaCar();
    virtual ~ToyotaCar();
    void setAutomaticTransmission(bool value); // ������ ���������� ������������ ���������� �������������� ������� �������
};

