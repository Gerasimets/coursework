#pragma once
#include "Car.h"
class ToyotaCar : public Car 
{
    bool automaticTransmission; // автоматическая коробка передач
protected:
    virtual std::string getFileName() override;
    virtual void writeAdditionalData(std::ofstream& ofs) override;
public:
    ToyotaCar();
    virtual ~ToyotaCar();
    void setAutomaticTransmission(bool value); // тайота отличается возможностью установить автоматическая коробка передач
    virtual void display() override;
};

