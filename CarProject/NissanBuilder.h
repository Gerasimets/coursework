#pragma once
#include "CarBuilder.h"
class NissanBuilder : public CarBuilder {
public:
    NissanBuilder();
    virtual ~NissanBuilder();
    virtual void reset() override;
    void setHeatedSeats(bool value); //отличие ниссан от других - возможность сделать подогрев сидений 
};

