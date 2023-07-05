//
// Created by raulett on 05.07.2023.
//

#include "Sigma.h"

void Sigma::update(double next) {
    summ += next;
    element_count++;
    elements.push_back(next);
}

double Sigma::eval() const{
    double mean = summ/element_count;
    double dispersion = 0;
    for (double el : elements){
        dispersion += std::pow((el - mean), 2);
    }
    dispersion /= element_count;
    return std::sqrt(dispersion);
}

const char *Sigma::name() const {
    return "sigma";
}
