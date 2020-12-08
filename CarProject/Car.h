#pragma once

#include <string>
#include "VehicleSize.h"

enum class Color //������������� ��� ������, ���� ������
{
    BLACK,
    YELLOW,
    RED,
    PINK,
    BLUE
};

enum class EngineType // ������������ ��� ������, ��� ���������
{
    DIESEL, // ���������
    INJECTOR // �����������
};

class Car 
{
    Color color; //����
    EngineType engineType; //��� ���������
    VehicleSize size; // �������� ������
    int yearOfBirthday; //��� ������� 
    int doorsCount; // ����� ������ 
    std::string model; //������
    std::string tireBrand; // ����� ���
    double trunkVolume; // ����� ���������
    double engineVolume; // ����� ���������
protected:
    Car(); //����������� 
    virtual std::string getFileName() = 0; //����� ����������� �������, ��� ��� ��� ����� � ������� ����
    virtual void writeAdditionalData(std::ofstream& ofs) = 0; //����� ����������� �������, ��� ��� ��� �������������� � ������� ����
public:
    virtual ~Car();
    void setColor(Color value); 
    void setEngineType(EngineType value);
    void setSize(VehicleSize value);
    void setYearOfBirthday(int value);
    void setDoorsCount(int value);
    void setModel(std::string value);
    void setTireBrand(std::string value);
    void setTrunkVolume(double value);
    void setEngineVolume(double value);
    virtual void display();
    void save();
};

