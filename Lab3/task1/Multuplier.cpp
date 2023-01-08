#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "ExpressionEvaluator.h"
#include "Multiplier.h"

using namespace std;

// реализация функций, описанных в классе
Multiplier::Multiplier() : ExpressionEvaluator() {};
Multiplier::Multiplier(size_t n) : ExpressionEvaluator(n) {};

double Multiplier::calculate() {
	double result = operands[0];

	for (size_t i = 1; i < operandCount; i++)
	{
		result *= operands[i];
	}

	return result;
}

void Multiplier::logToScreen()  {
	for (int i = 0; i < this->operandCount; i++)
		cout << "Op" << i + 1 << ", ";
	cout << "\b\b : ";
	if (operands[0] < 0)
		cout << "(" << this->operands[0] << ")";
	else
		cout << this->operands[0];

	for (size_t i = 1; i < this->operandCount; i++)
	{
		if (operands[i] < 0)
			cout << " x " << "(" << this->operands[i] << ")";
		else
			cout << " x " << this->operands[i];
	}

	cout << "\b\b\n-> " << this->calculate() << endl;
}

void Multiplier::logToFile(const std::string& filename)  {
	std::ofstream fout(filename, ios::app);

	for (int i = 0; i < this->operandCount; i++)
		fout << "Op" << i + 1 << ", ";
	fout << "\b\b : ";
	if (operands[0] < 0)
		fout << "(" << this->operands[0] << ")";
	else
		fout << this->operands[0];

	for (size_t i = 1; i < this->operandCount; i++)
	{
		if (operands[i] < 0)
			fout << " x " << "(" << this->operands[i] << ")";
		else
			fout << " x " << this->operands[i];
	}

	fout << "\b\b\n-> " << this->calculate() << endl;
}