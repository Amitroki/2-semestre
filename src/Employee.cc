#include <class/Workers.h>

#include <cassert>
#include <stdexcept>
#include <ctime>
#include <iostream>

using namespace std;
using namespace workers;

EmployeePtr Employee::create_full_time(string name, string surname, string fathername, int day, int month, int year, int salary) {
	return new Employee(Type::Part_time, name, surname, fathername, day, month, year, salary);
}

EmployeePtr Employee::create_part_time(string name, string surname, string fathername, int day, int month, int year, int based_salary, int percent, int number_of_hours) {
	return new Employee(Type::Full_time, name, surname, fathername, day, month, year, based_salary, percent, number_of_hours);
}

Employee::Employee(Type type, string name, string surname, string fathername, int day, int month, int year, int salary) : _type(Type::Full_time), _name(name), _surname(surname), _fathername(fathername), _day(day), _month(month), _year(year), _salary(salary) {}

Employee::Employee(Type type, string name, string surname, string fathername, int day, int month, int year, int based_salary, int percent, int number_of_hours) : _type(Type::Part_time), _name(name), _surname(surname), _fathername(fathername), _day(day), _month(month), _year(year), _based_salary(based_salary), _percent(percent), _number_of_hours(number_of_hours) {}

Type Employee::get_type() const {
	return _type;
}

std::string Employee::get_name() const {
	return _name;
}

std::string Employee::get_surname() const {
	return _surname;
}

std::string Employee::get_fathername() const {
	return _fathername;
}

int Employee::get_day() const {
	return _day;
}

int Employee::get_month() const {
	return _month;
}

int Employee::get_year() const {
	return _year;
}

void Employee::set_salary(int count) {
	_salary = count;
}

int Employee::get_salary() const {
	return _salary;
}

void Employee::set_based_salary(int count) {
	_based_salary = count;
}

int Employee::get_based_salary() const {
	return _based_salary;
}

void Employee::set_percent(int number) {
	_percent = number;
}

int Employee::get_percent() const {
	return _percent;
}

int Employee::get_number_of_hours() const {
	return _number_of_hours;
}

double Employee::calculating_salary_for_full() {
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

double Employee::calculating_salary_for_part() {
	double cal_salary = _based_salary * _number_of_hours * (1 + _percent * 1.0 / 100);
	return cal_salary;
}

double Employee::calculating_salary() {
	switch (_type) {
	case::Type::Full_time:
		return calculating_salary_for_full();
	case::Type::Part_time:
		return calculating_salary_for_part();
	default:
		throw runtime_error("[Function::compute_derivative] Invalid function type.");
	}
}

std::ostream& operator<< (std::ostream& out, const Employee& other) {
	switch (other.get_type()) {
	case::Type::Full_time:
		out << "Employee(" << other.get_name() << other.get_surname() << other.get_fathername() << other.get_day() << other.get_month() << other.get_year() << other.get_salary();
		break;
	case::Type::Part_time:
		out << "Employee(" << other.get_name() << other.get_surname() << other.get_fathername() << other.get_day() << other.get_month() << other.get_year() << other.get_based_salary() << other.get_percent() << other.get_number_of_hours();
	default:
		throw runtime_error("[Function::compute_derivative] Invalid function type.");
	}

	return out;
}