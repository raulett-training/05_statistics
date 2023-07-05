//
// Created by raulett on 05.07.2023.
//

#ifndef STATISTICS_SIGMA_H
#define STATISTICS_SIGMA_H
#include "IStatistics.h"
#include <cmath>
#include <list>

class Sigma : public IStatistics {
public:
    Sigma():
            summ{0},
            elements{},
            element_count{0}{}

    void update(double next) override;

    [[nodiscard]] double eval() const override;

    [[nodiscard]] const char * name() const override;

private:
    double summ;
    std::list<double> elements;
    size_t element_count;
};

#endif //STATISTICS_SIGMA_H
