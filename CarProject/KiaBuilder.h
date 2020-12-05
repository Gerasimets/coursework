#pragma once

#include "CarBuilder.h"

class KiaBuilder : public CarBuilder // класс-наследник, тип наследования  паблик
{
public:
    KiaBuilder();
    virtual ~KiaBuilder();
    virtual void reset() override; 
    void setHeatedMirrors(bool value); //отличие киа от других - возможность установить подогрев задних зеркал
};

