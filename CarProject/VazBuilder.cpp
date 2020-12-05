#include "stdafx.h"
#include "VazBuilder.h"
#include "VazCar.h"


VazBuilder::VazBuilder() {
    reset();
}


VazBuilder::~VazBuilder() {
}

void VazBuilder::reset() {
    car = new VazCar;
}

void VazBuilder::setTrunkOnRoof(bool value) {
    ((VazCar*)car)->setTrunkOnRoof(value);
}