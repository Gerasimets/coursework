#pragma once
#include "Car.h"
class ToyotaCar : public Car 
{
    bool automaticTransmission; // �������������� ������� �������
protected:
    virtual std::string getFileName() override;
    virtual void writeAdditionalData(std::ofstream& ofs) override;
public:
    ToyotaCar();
    virtual ~ToyotaCar();
    void setAutomaticTransmission(bool value); // ������ ���������� ������������ ���������� �������������� ������� �������
    virtual void display() override;
};

