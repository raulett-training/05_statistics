//
// Created by raulett on 05.07.2023.
//

#ifndef STATISTICS_MEAN_H
#define STATISTICS_MEAN_H

#include <cstdint>
#include "IStatistics.h"

class Mean : public IStatistics {
public:
    Mean() : mean{0}, element_count{0}{}

    void update(double next) override;

    [[nodiscard]] double eval() const override;

    [[nodiscard]] const char * name() const override;
private:
    double mean;
    size_t element_count;
};


#endif //STATISTICS_MEAN_H
