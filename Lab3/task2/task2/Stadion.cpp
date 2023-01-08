#include <iostream>
#include <fstream>
#include "Stadion.h"
#include <windows.h>

// реализация функций класса
Stadion::Stadion() {}
Stadion::Stadion(std::string address,
	std::string club,
	int sectors_count,
	int capacity, double attendance) : address_(address), club_(club),
	sectors_count_(sectors_count), capacity_(capacity), attendance_(attendance), restOfTickets_(100)
{
}
void Stadion::setAddress(const std::string address)
{
	address_ = address;
}
void Stadion::setClub(const std::string club)
{
	club_ = club;
}
void Stadion::setAttendance(double attendance)
{
	attendance_ = attendance;
}
void Stadion::setSectorsCount(int sectors_count)
{
	sectors_count_ = sectors_count;
}
void Stadion::setCapacity(int capacity)
{
	capacity_ = capacity;
}
int Stadion::getSectorsCount() const {
	return sectors_count_;
}
int Stadion::getCapacity() const {
	return capacity_;
}
std::string Stadion::getAddress() const {
	return address_;
}
std::string Stadion::getClub() const {
	return club_;
}
double Stadion::getAttendance() const {
	return attendance_;
}

void Stadion::ticket() const {
	if (!restOfTickets_) {
		std::cout << "Абонементы закончились :(";
		return;
	}

	srand((time(0)));
	int abonementNum = (rand()) % capacity_;
	int sector = rand() % sectors_count_ + 1;
	int place = rand() % capacity_ / sectors_count_ + 1;
	restOfTickets_--;
	std::cout << "Abonement number: " << abonementNum << std::endl;
	std::cout << "Sector: " << sector << std::endl;
	std::cout << "Place: " << place << std::endl;
	std::cout << "Abonements rest: " << restOfTickets_ << std::endl << std::endl;

	std::ofstream out;          // поток для записи
	out.open("data.txt", std::ios::app); // окрываем файл для записи
	if (out.is_open())
	{
		out << "Abonement number: " << abonementNum << std::endl;
		out << "Sector: " << sector << std::endl;
		out << "Place: " << place << std::endl;
		out << "Abonements rest: " << restOfTickets_ << std::endl << std::endl;

	}
	out.close();
	Sleep(1000);
}

void Stadion::printInfo() const
{
	std::cout << "Name: " << address_ << std::endl;;
	std::cout << "Club: " << club_ << std::endl;
	std::cout << "Sectors count: " << sectors_count_ << std::endl;
	std::cout << "Attendance: " << attendance_ << std::endl;
	std::cout << "Capacity: " << capacity_ << std::endl;
	std::cout << "Average Percent: " << attendance_ / capacity_ * 100 << std::endl << std::endl;

}
void Stadion::serialize(std::string filename = "games.txt")
{
	std::ofstream out;          // поток для записи
	out.open(filename, std::ios::app); // окрываем файл для записи
	if (out.is_open())
	{
		out << "name " << address_ << std::endl;;
		out << "club " << club_ << std::endl;
		out << "Sectors count: " << sectors_count_ << std::endl;
		out << "Capacity " << capacity_ << std::endl;
		out << "Attendance " << attendance_ << std::endl;
		out << "fill(%) " << attendance_ / capacity_ * 100 << std::endl << std::endl;

	}
	out.close();
}
void Stadion::deserialize(std::string filename = "games.txt")
{
	std::string serializedLine;

	std::ifstream in(filename);
	if (in.is_open())
	{
		while (getline(in, serializedLine))
		{
			std::cout << serializedLine << std::endl;
		}
	}
	in.close();
}