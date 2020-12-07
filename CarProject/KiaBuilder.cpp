#include "stdafx.h"
#include "KiaBuilder.h"
#include "KiaCar.h"

KiaBuilder::KiaBuilder() {
    reset();
}


KiaBuilder::~KiaBuilder() {
}

void KiaBuilder::reset() {
    car = new KiaCar; // выделить память под переменную типа KiaCar, возвращает алрес, где будет храниться
													
}

void KiaBuilder::setHeatedMirrors(bool value) {
    ((KiaCar*)car)->setHeatedMirrors(value);
}