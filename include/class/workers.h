#pragma once
#include <string>

namespace workers {
	enum class Type {
		Part_time,
		Full_time
	};
	class Employee;
	using EmployeePtr = Employee*;
	class Employee {
	private:
		Type _type;
		std::string _name;
		std::string _surname;
		std::string _fathername;
		int _day;
		int _month;
		int _year;
		int _salary;
		int _based_salary;
		int _percent;
		int _number_of_hours;
		Employee(Type type, std::string name, std::string surname, std::string fathername, int day, int month, int year, int salary);
		Employee(Type type, std::string name, std::string surname, std::string fathername, int day, int month, int year, int based_salary, int percent, int number_of_hours);
	public:
		static Employee create_full_time(std::string name, std::string surname, std::string fathername, int day, int month, int year, int salary);
		static Employee create_part_time(std::string name, std::string surname, std::string fathername, int day, int month, int year, int based_salary, int percent, int number_of_hours);

		Employee();
		Type get_type() const;
		std::string get_name() const;
		std::string get_surname() const;
		std::string get_fathername() const;
		int get_day() const;
		int get_month() const;
		int get_year() const;
		int get_number_of_hours() const;
		void set_salary(int count);
		void set_based_salary(int count);
		void set_percent(int number);

		double calculating_salary_for_full();
		double calculating_salary_for_part();

		double calculating_salary();
	};

	class Employees {
	public:
		static const int CAPACITY = 10;
		Employees();
		int get_size() const;
		Employee operator[](int index) const;
		void add1(Employee f);
		void add2(Employee f, int index);
		void delete_person(int index);
		void insert_person(Employee people, int index);
		void remove(int index);
	private:
		Employee _Worker[CAPACITY];
		int _size;
	};

	int search_max_salary(const Employees& _Worker);
}