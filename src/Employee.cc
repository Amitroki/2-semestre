#include <class/Workers.h>

#include <cassert>
#include <stdexcept>
#include <ctime>

using namespace std;
using namespace workers;

Employee Employee::create_full_time(string name, string surname, string fathername, int day, int month, int year, int salary) {
	return Employee(Type::Part_time, name, surname, fathername, day, month, year, salary);
}

Employee Employee::create_part_time(string name, string surname, string fathername, int day, int month, int year, int based_salary, int percent, int number_of_hours) {
	return Employee(Type::Full_time, name, surname, fathername, day, month, year, based_salary, percent, number_of_hours);
}

Employee::Employee() : _type(Type::Part_time), _name("A"), _surname("B"), _fathername("C"), _day(1), _month(1), _year(2023), _based_salary(1000), _percent(1), _number_of_hours(30) {}

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

void Employee::set_based_salary(int count) {
	_based_salary = count;
}

void Employee::set_percent(int number) {
	_percent = number;
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