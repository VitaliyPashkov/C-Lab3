#include <typeinfo>
#include "Stadion.h"
#include "Cort.h"
#include "SportInventory.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

void imitateGameAndReturnPercent(Stadion* stadionArr, size_t N) { // функция имитации игры
	srand(unsigned(time(0)));
	for (size_t i = 0; i < N; i++)
	{
		double attendance = 0;
		for (size_t j = 0; j < N; j++)
		{
			attendance += rand() % stadionArr[j].getCapacity() + 300;
		}
		stadionArr[i].setAttendance((int)attendance/N);

	}
}

void sortByAveragePercent(Stadion* stadionArr, size_t N) { // функция сортировки по среднему проценту
	Stadion temp;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (stadionArr[j].getAttendance() / stadionArr[j].getCapacity() < 
				stadionArr[j+1].getAttendance() / stadionArr[j+1].getCapacity()) {
				temp = stadionArr[j];
					stadionArr[j] = stadionArr[j + 1];
					stadionArr[j + 1] = temp;
			}
		}
	}
}
int main() {
	remove("data.txt");
	//1 стадион 
	Stadion s1 = Stadion("Donetsk", "Shakhtar", 5, 3000, 2000);
	std::cout << typeid(s1).name() << std::endl; // работа RTTI в программе
	s1.printInfo();
	s1.ticket(); // вызов функции выдачи абонемента

	////2 стадион
	Stadion s2 = Stadion("Moscow", "Zenit", 6, 5000, 3000);
	std::cout << typeid(s2).name() << std::endl;
	s2.printInfo();
	s2.ticket();
	s2.ticket();


	////3 Cort
	Cort c1 = Cort(65, "F", "June");
	std::cout << typeid(c1).name() << std::endl;
	c1.printInfo();
	c1.ticket(); // несколько раз вызывается функция выдачи абонемента 
	c1.ticket(); // для демонстрации рандома и декремента оставшихся билетов
	c1.ticket();


	Stadion s4 = Stadion("test", "bbbbb", 4, 8000, 6456);
	std::cout << typeid(s4).name() << std::endl;
	s4.printInfo();
	s4.ticket();
	//imitateGameAndReturnPercent(stadionArr, 3);
	//sortByAveragePercent(stadionArr, 3);
	//
	//for (size_t i = 0; i < 3; i++) {
	//	stadionArr[i].printInfo();
	//	stadionArr[i].serialize();
	//}
	//	
	return 0;
}
