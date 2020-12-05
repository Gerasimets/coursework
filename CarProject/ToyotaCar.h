#pragma once
#include "Car.h"
class ToyotaCar : public Car 
{
    bool automaticTransmission; // автоматическая коробка передач
public:
    ToyotaCar();
    virtual ~ToyotaCar();
    void setAutomaticTransmission(bool value); // тайота отличается возможностью установить автоматическая коробка передач
};

