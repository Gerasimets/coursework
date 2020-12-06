#pragma once
#include "Car.h"
class NissanCar : public Car {
    bool heatedSeats; //подогрев сидений
protected:
    virtual std::string getFileName() override;
    virtual void writeAdditionalData(std::ofstream& ofs) override;
public:
    NissanCar();
    virtual ~NissanCar();
    void setHeatedSeats(bool value); //отличие ниссан от других - возможность сделать подогрев сидений
    virtual void display() override;
};

