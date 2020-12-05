#pragma once
#include "Car.h"
class KiaCar : public Car {
    bool heatedMirrors; //подогрев задних зеркал
public:
    KiaCar();
    virtual ~KiaCar();
    void setHeatedMirrors(bool value); //отличие киа от других - возможность установить подогрев задних зеркал
};

