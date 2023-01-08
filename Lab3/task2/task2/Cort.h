#pragma once
#include "ISeasonTicketProvider.h"
#include "Stadion.h"
class Cort : public Stadion {
public:
	Cort(); // конструктор
	Cort(double area, const std::string& coating_type, const std::string& month); // конструктор с параметрами
	void printInfo() const;

	// сеттеры
	void setArea(double area);
	void SetCoatingType(const std::string& coating_type);
	void SetMonth(const std::string& month);
	// геттеры
	double getArea() const;
	std::string getMonth() const;
public:
	void ticket() const override; // та самая функция 
protected:
	double area_{ 0 };
	std::string coating_type_ = { "" };
private:
	mutable int restOfTickets_; // mutable - чтобы изменять значение переменной в константной функции
	std::string month_ = { "" };
};