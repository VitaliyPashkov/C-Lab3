#pragma once
#include "ILoggable.h"
class ExpressionEvaluator : public ILoggable {
public:
	ExpressionEvaluator(); // конструктор
	ExpressionEvaluator(size_t n); // конструктор с параметром
	~ExpressionEvaluator(); // удаление

	//объявление функций и переменных согласно заданию
	virtual double calculate() = 0; 
	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
	size_t operandCount;
	int* operandsIndex;
	double* operands;
};