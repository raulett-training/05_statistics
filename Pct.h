//
// Created by raulett on 05.07.2023.
//

#ifndef INC_05_HOMEWORK_PCT_H
#define INC_05_HOMEWORK_PCT_H

#include <cstdint>
#include <list>
#include <string>
#include "IStatistics.h"

class Pct : public IStatistics{
public:
    explicit Pct(int percentil) : elements{}, percentil{percentil}{}
    void update(double next) override;
    [[nodiscard]] double eval() const override;
    [[nodiscard]] const char * name() const override;
private:
    std::list<double> elements;
    int percentil;
};


#endif //INC_05_HOMEWORK_PCT_H
