#pragma once
#include <iostream>
#include <fstream>
#include "ExpressionEvaluator.h"
#include "IShuffle.h"

using namespace std;

class Summator : public ExpressionEvaluator, public IShuffle {
public:
	Summator(); // конструктор
	Summator(size_t n); // конструктор с параметрами
	// объявление функций
	double calculate() override;
	void shuffle() override;
	void shuffle(size_t i, size_t j) override;
	void logToScreen() override;
	void logToFile(const std::string& filename) override;
private:
	void swap(double* xp, double* yp)
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}
};