#pragma once
#include "IShuffle.h"
#include "ExpressionEvaluator.h"


using namespace std;
class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle {
public:
	CustomExpressionEvaluator(); // конструктор
	CustomExpressionEvaluator(size_t n); // конструктор с параметром
	// объявление функций
	double calculate() override;
	void shuffle() override;
	void shuffle(size_t i, size_t j) override;
	void logToScreen() override;
	void logToFile(const std::string& filename) override;
private:
	// вспомогательная функция для перемещения местами значений
	void swap(double* xp, double* yp)
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}
	void swap(int* xp, int* yp)
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}
};