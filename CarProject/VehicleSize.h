#pragma once
class VehicleSize //����� ��������� ������
{
    int x; //�����
    int y; // ������
    int z; //������
public:
    VehicleSize(); //�����������
    VehicleSize(int x, int y, int z); //����������� � ����������
    virtual ~VehicleSize(); //����������� ����������
    /*�������� ������*/
    int getX(); 
    int getY();
    int getZ();
};

