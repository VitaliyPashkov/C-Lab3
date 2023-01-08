#pragma once
#include <string>
#include "ISeasonTicketProvider.h"
class Stadion : public ISeasonTicketProvider
{
public:
	Stadion(); // конструктор
	Stadion(std::string address,
		std::string club,
		int count_sectors,
		int capacity, double attendance); // конструктор с параметрами
	void setAddress(const std::string address); // сеттеры
	void setClub(const std::string club); // сеттеры
	void setSectorsCount(int sectors_count); // сеттеры
	void setCapacity(int capacity); // сеттеры
	void setAttendance(double attendance); // сеттеры

	int getCapacity() const;
	std::string getAddress() const;
	std::string getClub() const;
	int getSectorsCount() const;
	double getAttendance() const;
	// сериализация / десериализация:
	void serialize() const;
	void serialize(std::string filename);
	void deserialize(std::string filename);
	void printInfo() const; // вывод информации о себе

public:
	void ticket() const override;
protected:
	std::string address_{ "" }; // название стадиона
	std::string club_{ "" }; // название клуба
	int sectors_count_{ 0 }, capacity_{ 0 }; // количество секторов и вместимость
	double attendance_{ 0 }; // посещаемость
private:
	mutable int restOfTickets_; // mutable - чтобы изменять значение переменной в константной функции
};
