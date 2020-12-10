#pragma once
#include "CarBuilder.h"
class ToyotaBuilder : public CarBuilder {
public:
    ToyotaBuilder();
    virtual ~ToyotaBuilder();
    virtual void reset() override;
    void setAutomaticTransmission(bool value); // ������ ���������� ������������ ���������� �������������� ������� �������
};