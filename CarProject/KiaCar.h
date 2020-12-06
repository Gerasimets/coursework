#pragma once
#include "Car.h"
class KiaCar : public Car {
    bool heatedMirrors; //подогрев задних зеркал
protected:
    virtual std::string getFileName() override;
    virtual void writeAdditionalData(std::ofstream& ofs) override;
public:
    KiaCar();
    virtual ~KiaCar();
    void setHeatedMirrors(bool value); //отличие киа от других - возможность установить подогрев задних зеркал
    virtual void display() override;
};

