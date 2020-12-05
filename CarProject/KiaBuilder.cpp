#include "stdafx.h"
#include "KiaBuilder.h"
#include "KiaCar.h"

KiaBuilder::KiaBuilder() {
    reset();
}


KiaBuilder::~KiaBuilder() {
}

void KiaBuilder::reset() {
    car = new KiaCar;
}

void KiaBuilder::setHeatedMirrors(bool value) {
    ((KiaCar*)car)->setHeatedMirrors(value);
}