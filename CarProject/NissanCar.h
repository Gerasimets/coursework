#pragma once
#include "Car.h"
class NissanCar : public Car {
    bool heatedSeats; //подогрев сидений
public:
    NissanCar();
    virtual ~NissanCar();
    void setHeatedSeats(bool value); //отличие ниссан от других - возможность сделать подогрев сидений
};

