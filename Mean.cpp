//
// Created by raulett on 05.07.2023.
//

#include "Mean.h"

void Mean::update(double next){
    mean += next;
    element_count++;
}

double Mean::eval() const {
    return mean/element_count;
}

const char *Mean::name() const {
    return "mean";
}
