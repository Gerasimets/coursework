#include "stdafx.h"
#include "VehicleSize.h"

VehicleSize::VehicleSize(): x(0), y(0), z(0) 
{

}

VehicleSize::VehicleSize(int x, int y, int z)
    : x(x), y(y), z(z) /////////////////////////////////////////////////////////// это одна из форм записи?
{
}

VehicleSize::~VehicleSize() 
{
}

int VehicleSize::getX() {
    return x;
}

int VehicleSize::getY() {
    return y;
}

int VehicleSize::getZ() {
    return z;
}
