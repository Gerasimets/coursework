#pragma once
#include "Car.h"
class KiaCar : public Car {
    bool heatedMirrors; //�������� ������ ������
public:
    KiaCar();
    virtual ~KiaCar();
    void setHeatedMirrors(bool value); //������� ��� �� ������ - ����������� ���������� �������� ������ ������
};

