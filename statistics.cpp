#include <iostream>
#include <limits>
#include <list>
#include <cmath>

class IStatistics {
public:
	virtual ~IStatistics() {}

	virtual void update(double next) = 0;
	virtual double eval() const = 0;
	virtual const char * name() const = 0;
};

class Min : public IStatistics {
public:
	Min() : m_min{std::numeric_limits<double>::max()} {
	}

	void update(double next) override {
		if (next < m_min) {
			m_min = next;
		}
	}

	double eval() const override {
		return m_min;
	}

	const char * name() const override {
		return "min";
	}

private:
	double m_min;
};

class Max : public IStatistics {
public:
    Max() : m_max{std::numeric_limits<double>::min()}{}
    void update(double next) override{
        if (next > m_max) {
            m_max = next;
        }
    }

    double eval() const override {
        return m_max;
    }

    const char * name() const override {
        return "max";
    }
private:
    double m_max;
};

class Mean : public IStatistics {
public:
    Mean() : mean{0}, element_count{0}{}

    void update(double next) override{
        mean += next;
        element_count++;
    }

    double eval() const override {
        return mean/element_count;
    }

    const char * name() const override {
        return "mean";
    }
private:
    double mean;
    size_t element_count;
};

class Sigma : public IStatistics {
public:
    Sigma():
    summ{0},
    element_count{0},
    elements{}{}

    void update(double next) override {
        summ += next;
        element_count++;
        elements.push_back(next);
    }

    double eval() const override{
        double mean = summ/element_count;
        double dispersion = 0;
        for (double el : elements){
            dispersion += std::pow((el - mean), 2);
        }
        dispersion /= element_count;
        return std::sqrt(dispersion);
    }

    const char * name() const override {
        return "sigma";
    }

private:
    double summ;
    std::list<double> elements;
    size_t element_count;
};

class Pct90 : public IStatistics{
public:
    Pct90() : elements{}{}

    void update(double next) override {
        elements.push_back(next);
    }

    double eval() const override{
        std::list<double> el_list = elements;
        el_list.sort();
        size_t percentil95_num = (elements.size()/100.0) * 90;
        auto it = elements.begin();
        std::advance(it, percentil95_num);
        return *it;
    }

    const char * name() const override {
        return "pct90";
    }

private:
    std::list<double> elements;
};

class Pct95 : public IStatistics{
public:
    Pct95() : elements{}{}

    void update(double next) override {
        elements.push_back(next);
    }

    double eval() const override{
        std::list<double> el_list = elements;
        el_list.sort();
        int percentil90_num = (elements.size()/100.0) * 95;
        auto it = elements.begin();
        std::advance(it, percentil90_num);
        return *it;
    }

    const char * name() const override {
        return "pct95";
    }

private:
    std::list<double> elements;
};

int main() {

	const size_t statistics_count = 6;
	IStatistics *statistics[statistics_count] {new Min{}, new Max{}, new Mean{},
                                               new Sigma{}, new Pct90{}, new Pct95{}};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}

	return 0;
}