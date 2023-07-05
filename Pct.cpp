//
// Created by raulett on 05.07.2023.
//

#include "Pct.h"


void Pct::update(double next) {
    elements.push_back(next);
}

double Pct::eval() const {
    int percentil_num = (elements.size()/100.0) * percentil;
    auto it = elements.begin();
    std::advance(it, percentil_num);
    return *it;
}

const char *Pct::name() const {
    std::string s = "Pct";
    std::string k = s + std::to_string(percentil);
    const char * c = k.c_str();
    return c;
}

