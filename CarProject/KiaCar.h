#pragma once
#include "Car.h"
class KiaCar : public Car {
    bool heatedMirrors; //�������� ������ ������
protected:
    virtual std::string getFileName() override;
    virtual void writeAdditionalData(std::ofstream& ofs) override;
public:
    KiaCar();
    virtual ~KiaCar();
    void setHeatedMirrors(bool value); //������� ��� �� ������ - ����������� ���������� �������� ������ ������
    virtual void display() override;
};

