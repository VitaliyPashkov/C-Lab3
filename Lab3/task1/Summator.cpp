#pragma once
#include "Summator.h"
#include <iostream>
#include <fstream>
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
using namespace std;

// реализация функций, описанных в классе
Summator::Summator() : ExpressionEvaluator(), IShuffle() {};
Summator::Summator(size_t n) : ExpressionEvaluator(n), IShuffle() {};

	double Summator::calculate()  {
		double result = this->operands[0];

		for (size_t i = 1; i < this->operandCount; i++)
		{
			result += this->operands[i];
		}
		return result;
	}


	void Summator::shuffle() {
		for (int i = 0; i < operandCount; i++)
			for (int j = 0; j < operandCount; j++)
				if (operands[i] < 0 && operands[j] < 0)
					if (operands[i] < operands[j])
						swap(&operands[i], &operands[j]);
	}

	void Summator::shuffle(size_t i, size_t j)  {
		for (; i < j - 1; i++)
			if (operands[i] < 0 && operands[i + 1] < 0) {
				if (operands[i] < operands[i + 1])
					swap(&operands[i], &operands[i + 1]);
			}
			else if (operands[i] > operands[i + 1])
				swap(&operands[i], &operands[i + 1]);

	}

	void Summator::logToScreen()  {
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
				cout << " + " << "(" << this->operands[i] << ")";
			else
				cout << " + " << this->operands[i];
		}

		cout << "\b\b\n-> " << this->calculate() << endl;
	}

	void Summator::logToFile(const std::string& filename)  {
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
				fout << " + " << "(" << this->operands[i] << ")";
			else
				fout << " + " << this->operands[i];
		}

		fout << "\b\b\n-> " << this->calculate() << endl;
	}


