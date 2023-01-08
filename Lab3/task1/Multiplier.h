#pragma once
#include "ExpressionEvaluator.h"


using namespace std;

class Multiplier : public ExpressionEvaluator {
public:
	Multiplier(); // конструктор
	Multiplier(size_t n); // конструктор с парамаетрами
	// объявление функций
	double calculate() override;
	void logToScreen() override;
	void logToFile(const std::string& filename) override;
};
