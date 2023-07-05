//
// Created by raulett on 05.07.2023.
//

#ifndef INC_05_HOMEWORK_ISTATISTICS_H
#define INC_05_HOMEWORK_ISTATISTICS_H


class IStatistics {
public:
    virtual ~IStatistics() {}

    virtual void update(double next) = 0;
    virtual double eval() const = 0;
    virtual const char * name() const = 0;
};

#endif //INC_05_HOMEWORK_ISTATISTICS_H
