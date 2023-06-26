#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>


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
	Max() : m_max{std::numeric_limits<double>::min()} {
	}

	void update(double next) override {
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
	Mean() {
		sum = 0;
		count = 0;
	}

	void update(double next) override {
		++count;
		sum += next;
	}

	double eval() const override {
		return sum/count;
	}

	const char * name() const override {
		return "mean";
	}

private:
	double sum;
	int count; 
};

class Std : public IStatistics {
public:
	Std() {
		sum = 0;
		count = 0;
	}

	void update(double next) override {
		++count;
		sum += next;
		vect.push_back(next);
	}

	double eval() const override {
		double average = sum/count;
		double std = 0; 
		for (auto iter = vect.cbegin(); iter != vect.cend(); ++iter) {
			std += pow((*iter - average),2);
		}
		return pow(std/count, 0.5);
	}

	const char* name() const override {
		return "std";
	}

private:
	double sum;
	int count; 
	std::vector<double> vect;
};

class Pct90 : public IStatistics { //90-й прецентиль — это такое число, что 90% элементов массива меньше или равны этому числу.
public:
	Pct90() {
		vect = {};
	}

	void update(double next) override {
		vect.push_back(next);
		std::sort(vect.begin(), vect.end());
	}

	double eval() const override {
		int seloe = ceil(vect.size()*0.9);
		return vect.at(seloe-1);
	}

	const char* name() const override {
		return "pct90";
	}

private:
	std::vector<double> vect;
};

class Pct95 : public IStatistics { 
public:
	Pct95() {
		vect = {};
	}

	void update(double next) override {
		vect.push_back(next);
		std::sort(vect.begin(), vect.end());
	}

	double eval() const override {
		int seloe = ceil(vect.size()*0.95);
		return vect.at(seloe-1);
	}

	const char* name() const override {
		return "pct95";
	}

private:
	std::vector<double> vect;
};

int main() {

	const size_t statistics_count = 6;
	IStatistics *statistics[statistics_count];
	std::vector<double> vector;

	statistics[0] = new Min{};
	statistics[1] = new Max{};
	statistics[2] = new Mean{};
	statistics[3] = new Std{};
	statistics[4] = new Pct90{};
	statistics[5] = new Pct95{};


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

	std::cout << std::endl;

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