#pragma once
#include "Car.h"
class VazCar : public Car {
    bool trunkOnRoof; //�������� �� �����
protected:
    virtual std::string getFileName() override;
    virtual void writeAdditionalData(std::ofstream& ofs) override;
public:
    VazCar();
    virtual ~VazCar();
    void setTrunkOnRoof(bool value); //����������� ���������� �������� �� �����
    virtual void display() override;
};