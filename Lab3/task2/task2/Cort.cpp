#include <iostream>
#include <fstream>
#include <windows.h>
#include "Cort.h"


// реализация функций класса
Cort::Cort() : area_(0.0), coating_type_("nonetype") {
}
Cort::Cort(double area, const std::string& coating_type, const std::string& month) 
	: area_(area), coating_type_(coating_type), month_(month), restOfTickets_(15){
}

void Cort::setArea(double area) {
	area_ = area;
}
void Cort::SetCoatingType(const std::string& coating_type) {
	coating_type_ = coating_type;
}
void Cort::SetMonth(const std::string& month) {
	month_ = month;
}
double Cort::getArea() const {
	return area_;
}
std::string Cort::getMonth() const {
	return month_;
}

void Cort::ticket() const {
	if (!restOfTickets_) {
		std::cout << "Абонементы закончились :(";
		return;
	}
	if (month_ != "June" && month_ != "July" && month_ != "August") {
		std::cout << "Ошибка. Билет получить можно только летом." << std::endl;
		return;
	}
	srand(unsigned(time(0)));
	int abonementNum = rand() % 1000 + 1;

	restOfTickets_--;
	std::cout << "Abonement number: " << abonementNum << std::endl;
	std::cout << "Abonements rest: " << restOfTickets_ << std::endl << std::endl;

	std::ofstream out;          // поток для записи
	out.open("data.txt", std::ios::app); // окрываем файл для записи
	if (out.is_open())
	{
		out << "Abonement number: " << abonementNum << std::endl;
		out << "Abonements rest: " << restOfTickets_ << std::endl << std::endl;

	}
	out.close();
	Sleep(1000); // для создания бОльшего рандома, т.к. в моем случае он зависит от времени
}

void Cort::printInfo() const
{
	std::cout << "Area: " << area_ << std::endl;;
	std::cout << "Coating type: " << coating_type_ << std::endl;
	std::cout << "Current month: " << month_ << std::endl;

}
