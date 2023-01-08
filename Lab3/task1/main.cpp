#include "ILoggable.h" // подключение хэдеров - созданных классов
#include "IShuffle.h"
#include "Summator.h"
#include "Multiplier.h"
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include <iostream>
using namespace std;

int main()
{
	remove("Lab3.log"); // удаление лога с целью его перезаписи в процессе выполнения программы
	ExpressionEvaluator* evaluators[3]; // создаем массив значений

	evaluators[0] = new Summator(2); // экземпляр сумматора
	evaluators[0]->setOperand(0, 39.1);
	evaluators[0]->setOperand(1, -12.7);

	evaluators[1] = new CustomExpressionEvaluator(5); // экземпляр индивидуального класса согласно варианту
	double customExpressionOperands[] = { 5, 16, -3, 10, 12 };
	evaluators[1]->setOperands(customExpressionOperands, 5);

	evaluators[2] = new Multiplier(4); // экземпляр мультиплиера
	double operands[] = { -4.5, 2, 3, -10 };
	evaluators[2]->setOperands(operands, 4);

	for (size_t i = 0; i < 3; ++i) // цикл для вывода результатов вычисления и запись в лог
	{
		evaluators[i]->logToFile("Lab3.log");
		evaluators[i]->logToScreen();
	}
	cout << endl;

	for (int i = 0; i < 3; ++i)  // демонстрация функции shuffle
	{
		IShuffle* shuffle = dynamic_cast<IShuffle*>(evaluators[i]);
		if (shuffle)
		{
			shuffle->shuffle();
			evaluators[i]->logToFile("Lab3.log");
			evaluators[i]->logToScreen();
		//	std::cout << evaluators[i]->calculate() << std::endl;
		}
	}
	cout << endl;

	//for (int i = 0; i < 3; ++i)
	//{
	//	IShuffle* shuffle = dynamic_cast<IShuffle*>(evaluators[i]);
	//	if (shuffle)
	//	{
	//		shuffle->shuffle(1, 5);

	//		evaluators[i]->logToFile("Lab3.log");
	//		evaluators[i]->logToScreen();
	//		//	std::cout << evaluators[i]->calculate() << std::endl;
	//	}
	//}
}