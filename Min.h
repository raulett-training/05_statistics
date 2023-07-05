//
// Created by raulett on 05.07.2023.
//

#ifndef INC_05_HOMEWORK_MIN_H
#define INC_05_HOMEWORK_MIN_H

#include <limits>
#include "IStatistics.h"

class Min : public IStatistics {
public:
    Min() : m_min{std::numeric_limits<double>::max()}{}

    void update(double next) override;

    [[nodiscard]] double eval() const override;

    [[nodiscard]] const char * name() const override;

private:
    double m_min{};
};


#endif //INC_05_HOMEWORK_MIN_H
