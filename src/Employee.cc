#include <class/workers.h>

#include <cassert>
#include <stdexcept>
#include <ctime>
#include <iostream>

using namespace std;
using namespace workers;

Employee::Employee(std::string name, std::string surname, std::string fathername, int day, int month, int year) :
	_name(name), 
	_surname(surname),
	_fathername(fathername),
	_day(day),
	_month(month),
	_year(year)
{}

std::string Employee::get_name() const {
	return _name;
}

void Employee::set_name(std::string worker_name) {
	_name = worker_name;
}

std::string Employee::get_surname() const {
	return _surname;
}

void Employee::set_surname(std::string worker_surname) {
	_surname = worker_surname;
}

std::string Employee::get_fathername() const {
	return _fathername;
}

void Employee::set_fathername(std::string worker_fathername) {
	_fathername = worker_fathername;
}

int Employee::get_day() const {
	return _day;
}

void Employee::set_day(int day) {
	_day = day;
}

int Employee::get_month() const {
	return _month;
}

void Employee::set_month(int month) {
	_month = month;
}

int Employee::get_year() const {
	return _year;
}

void Employee::set_year(int year) {
	_year = year;
}

//ДЛЯ ПОСТОЯННОГО РАБОЧЕГО

FullEmployee::FullEmployee(std::string name, std::string surname, std::string fathername, int day, int month, int year, int salary) :
	Employee(name, surname, fathername, day, month, year),
	_salary(salary) {}

void FullEmployee::set_salary(int count) {
	_salary = count;
}

int FullEmployee::get_salary() const {
	return _salary;
}

EmployeePtr FullEmployee::clone() const {
	return make_shared<FullEmployee>(_name, _surname, _fathername, _day, _month, _year, _salary);
}

std::ostream& FullEmployee::print(std::ostream& out) const {
	out << "Имя: " << get_name() << "\n"
		<< "Фамилия: " << get_surname() << "\n"
		<< "Отчество: " << get_fathername() << "\n"
		<< "День поступления на работу: " << get_day() << "\n"
		<< "Месяц поступления на работу: " << get_month() << "\n"
		<< "Год поступления на работу: " << get_year() << "\n"
		<< "Заработная плата - " << get_salary() << endl << endl;
	return out;
}


//ДЛЯ ВРЕМЕННОГО РАБОЧЕГО


PartEmployee::PartEmployee(std::string name, std::string surname, std::string fathername, int day, int month, int year, int based_salary, int percent, int number_of_hours) :
	Employee(name, surname, fathername, day, month, year),
	_based_salary(based_salary),
	_percent(percent),
	_number_of_hours(number_of_hours) {}

void PartEmployee::set_based_salary(int count) {
	_based_salary = count;
}

int PartEmployee::get_based_salary() const {
	return _based_salary;
}

void PartEmployee::set_percent(int number) {
	_percent = number;
}

int PartEmployee::get_percent() const {
	return _percent;
}

int PartEmployee::get_number_of_hours() const {
	return _number_of_hours;
}

void PartEmployee::set_number_of_hours(int number_of_hours) {
	_number_of_hours = number_of_hours;
}

EmployeePtr PartEmployee::clone() const {
	return make_shared<PartEmployee>(_name, _surname, _fathername, _day, _month, _year, _based_salary, _percent, _number_of_hours);
}

std::ostream& PartEmployee::print(std::ostream& out) const {
	out << "Имя: " << get_name() << "\n"
		<< "Фамилия: " << get_surname() << "\n"
		<< "Отчество: " << get_fathername() << "\n"
		<< "День поступления на работу: " << get_day() << "\n"
		<< "Месяц поступления на работу: " << get_month() << "\n"
		<< "Год поступления на работу: " << get_year() << "\n"
		<< "Базовая ставка за час работы: " << get_based_salary() << "\n"
		<< "Процент надбавки: " << get_percent() << "\n"
		<< "Количество отработанных часов за последний месяц: " << get_number_of_hours() << endl << endl;
	return out;
}

double FullEmployee::calculating_salary() const{
	time_t t;
	time(&t);
	int a1 = (14 - _month) / 12;
	int y1 = _year + 4800 - a1;
	int m1 = _month + 12 * a1 - 3;
	int jdn1 = _day + (153 * m1 + 2) / 5 + 365 * y1 + y1 / 4 - y1 / 100 + y1 / 400 - 32045;
	int nowday = localtime(&t)->tm_mday;
	int nowmonth = localtime(&t)->tm_mon + 1;
	int nowyear = localtime(&t)->tm_year + 1900;
	int a = (14 - nowmonth) / 12;
	int y = nowyear + 4800 - a;
	int m = nowmonth + 12 * a - 3;
	int jdn = nowday + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
	int res = jdn - jdn1;
	double cal_salary = _salary * (1 + 0.005 * (res / 365));
	return cal_salary;
}

double PartEmployee::calculating_salary() const{
	double cal_salary = _based_salary * _number_of_hours * (1 + _percent * 1.0 / 100);
	return cal_salary;
}