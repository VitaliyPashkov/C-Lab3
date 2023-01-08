#pragma once
#include "ExpressionEvaluator.h"
using namespace std;

// реализация функций, описанных в классе
ExpressionEvaluator::ExpressionEvaluator() {
	this->operandCount = 20;
	this->operandsIndex = new int[this->operandCount] {0};
	this->operands = new double[this->operandCount] {0};
}

ExpressionEvaluator::ExpressionEvaluator(size_t n) {
	this->operandCount = n;
	this->operandsIndex = new int[this->operandCount] {0};
	this->operands = new double[this->operandCount] {0};
}

ExpressionEvaluator::~ExpressionEvaluator() {
	delete[] operands;
}


void ExpressionEvaluator::setOperand(size_t pos, double value) {
	this->operands[pos] = value;
	this->operandsIndex[pos] = pos;

}

void ExpressionEvaluator::setOperands(double ops[], size_t n) {
	for (size_t i = 0; i < n; i++)
	{
		this->operands[i] = ops[i];
		this->operandsIndex[i] = i;
	}
}
