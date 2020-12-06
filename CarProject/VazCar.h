#pragma once
#include "Car.h"
class VazCar : public Car {
    bool trunkOnRoof; //багажник на крышу
protected:
    virtual std::string getFileName() override;
    virtual void writeAdditionalData(std::ofstream& ofs) override;
public:
    VazCar();
    virtual ~VazCar();
    void setTrunkOnRoof(bool value); //возможность установить багажник на крышу
    virtual void display() override;
};

