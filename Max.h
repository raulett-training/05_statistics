//
// Created by raulett on 05.07.2023.
//

#ifndef STATISTICS_MAX_H
#define STATISTICS_MAX_H

#include <limits>
#include "IStatistics.h"


class Max : public IStatistics {
public:
    Max() : m_max{std::numeric_limits<double>::max()*(-1)}{}
    void update(double next) override;

    [[nodiscard]] double eval() const override;

    [[nodiscard]] const char * name() const override;
private:
    double m_max;
};

#endif //STATISTICS_MAX_H
