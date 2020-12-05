#include "stdafx.h"
#include "ToyotaBuilder.h"
#include "ToyotaCar.h"

ToyotaBuilder::ToyotaBuilder() {
    reset();
}


ToyotaBuilder::~ToyotaBuilder() {
}

void ToyotaBuilder::reset() {
    car = new ToyotaCar;
}

void ToyotaBuilder::setAutomaticTransmission(bool value) {
    ((ToyotaCar*)car)->setAutomaticTransmission(value);
}