#include "stdafx.h"
#include "NissanBuilder.h"
#include "NissanCar.h"


NissanBuilder::NissanBuilder() {
    reset();
}

NissanBuilder::~NissanBuilder() {
}

void NissanBuilder::reset() {
    car = new NissanCar;
}

void NissanBuilder::setHeatedSeats(bool value) {
    ((NissanCar*)car)->setHeatedSeats(value);
}
