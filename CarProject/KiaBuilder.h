#pragma once

#include "CarBuilder.h"

class KiaBuilder : public CarBuilder // �����-���������, ��� ������������  ������
{
public:
    KiaBuilder();
    virtual ~KiaBuilder();
    virtual void reset() override; 
    void setHeatedMirrors(bool value); //������� ��� �� ������ - ����������� ���������� �������� ������ ������
};

