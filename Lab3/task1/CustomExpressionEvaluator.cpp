#pragma once
#include "CustomExpressionEvaluator.h"
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <iostream>
#include <fstream>

// реализация функций, описанных в классе
CustomExpressionEvaluator::CustomExpressionEvaluator() : ExpressionEvaluator(), IShuffle() {}
CustomExpressionEvaluator::CustomExpressionEvaluator(size_t n) : ExpressionEvaluator(n), IShuffle() {}

double CustomExpressionEvaluator::calculate()  {
	double result;
	if (operandsIndex[0] == 0)
		result = this->operands[0];
	else
		result = this->operands[0] / (operandsIndex[0] + 1);

	for (size_t i = 1; i < operandCount; i++)
	{
		if (i % 2 == 1) {
			result -= operands[i] / (operandsIndex[i] + 1);
		}
		else
			result += operands[i] / (operandsIndex[i] + 1);
	}

	return result;
}

void CustomExpressionEvaluator::shuffle()  {
	for (int i = 0; i < operandCount; i++)
		for (int j = 0; j < operandCount; j++)
			if (operands[i] < 0 && operands[j] < 0)
				if (operands[i] / (operandsIndex[i] + 1) < operands[j] / (operandsIndex[j] + 1))
				{
					swap(&operands[i], &operands[j]);
					swap(&operandsIndex[i], &operandsIndex[j]);

				}
}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j)  {
	for (; i < j - 1; i++)
		for (int k = (j - 1); k >= (i + 1); k--) {
			if (operands[i] < 0 && operands[i - 1] < 0) {
				if (operands[i] < operands[i - 1]) {
					swap(&operands[i], &operands[i - 1]);
					swap(&operandsIndex[i], &operandsIndex[i - 1]);

				}
			}
			//else swap(&operands[i], &operands[i - 1]);
		}
}

void CustomExpressionEvaluator::logToScreen() {
	for (int i = 0; i < this->operandCount; i++)
		cout << "Op" << i + 1 << ", ";
	cout << "\b\b : ";
	if (operands[0] < 0)
		if (operandsIndex[0] == 0)
			cout << "(" << this->operands[0] << ")";
		else
			cout << "(" << this->operands[0] << "/" << operandsIndex[0] + 1 << ")";

	else if (operandsIndex[0] == 0)
		cout << this->operands[0];
	else
		cout << this->operands[0] << "/" << operandsIndex[0] + 1;

	for (size_t i = 1; i < this->operandCount; i++)
	{
		if (operands[i] < 0)
			if (i % 2 == 1)
				cout << " - " << "(" << this->operands[i] << "/" << operandsIndex[i] + 1 << ")";
			else
				cout << " + " << "(" << this->operands[i] << "/" << operandsIndex[i] + 1 << ")";
		else if (i % 2 == 1)
			cout << " - " << this->operands[i] << "/" << operandsIndex[i] + 1;
		else
			cout << " + " << this->operands[i] << "/" << operandsIndex[i] + 1;

	}

	cout << "\b\b\n-> " << this->calculate() << endl;
}

void CustomExpressionEvaluator::logToFile(const std::string& filename) {
	std::ofstream fout(filename, ios::app);

	for (int i = 0; i < this->operandCount; i++)
		fout << "Op" << i + 1 << ", ";
	fout << "\b\b : ";
	if (operands[0] < 0)
		if (operandsIndex[0] == 0)
			fout << "(" << this->operands[0] << ")";
		else
			fout << "(" << this->operands[0] << "/" << operandsIndex[0] + 1 << ")";

	else if (operandsIndex[0] == 0)
		fout << this->operands[0];
	else
		fout << this->operands[0] << "/" << operandsIndex[0] + 1;

	for (size_t i = 1; i < this->operandCount; i++)
	{
		if (operands[i] < 0)
			if (i % 2 == 1)
				fout << " - " << "(" << this->operands[i] << "/" << operandsIndex[i] + 1 << ")";
			else
				fout << " + " << "(" << this->operands[i] << "/" << operandsIndex[i] + 1 << ")";
		else if (i % 2 == 1)
			fout << " - " << this->operands[i] << "/" << operandsIndex[i] + 1;
		else
			fout << " + " << this->operands[i] << "/" << operandsIndex[i] + 1;

	}

	fout << "\b\b\n-> " << this->calculate() << endl;
}
