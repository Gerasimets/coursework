#pragma once
#include "Car.h"
class NissanCar : public Car {
    bool heatedSeats; //�������� �������
protected:
    virtual std::string getFileName() override;
    virtual void writeAdditionalData(std::ofstream& ofs) override;
public:
    NissanCar();
    virtual ~NissanCar();
    void setHeatedSeats(bool value); //������� ������ �� ������ - ����������� ������� �������� �������
    virtual void display() override;
};

