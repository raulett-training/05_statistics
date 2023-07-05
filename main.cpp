#include <iostream>
#include <list>
#include "Pct.h"
#include "Min.h"
#include "Max.h"
#include "Sigma.h"
#include "Mean.h"



int main() {

	const size_t statistics_count = 6;
	IStatistics *statistics[statistics_count] {new Min{}, new Max{}, new Mean{},
                                               new Sigma{}, new Pct{90}, new Pct{95}};

	double val = 0;
	while (std::cin >> val) {
		for (auto & statistic : statistics) {
			statistic->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (auto & statistic : statistics) {
		std::cout << statistic->name() << " = " << statistic->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (auto & statistic : statistics) {
		delete statistic;
	}

	return 0;
}