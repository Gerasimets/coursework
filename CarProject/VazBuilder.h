#pragma once
#include "CarBuilder.h"
class VazBuilder : public CarBuilder {
public:
    VazBuilder();
    virtual ~VazBuilder();
    virtual void reset() override;
    void setTrunkOnRoof(bool value); //возможность установить багажник на крышу
};

