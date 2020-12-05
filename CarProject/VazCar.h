#pragma once
#include "Car.h"
class VazCar : public Car {
    bool trunkOnRoof; //багажник на крышу
public:
    VazCar();
    virtual ~VazCar();
    void setTrunkOnRoof(bool value); //возможность установить багажник на крышу
};

