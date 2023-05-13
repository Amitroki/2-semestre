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
		static EmployeePtr create_full_time(std::string name, std::string surname, std::string fathername, int day, int month, int year, int salary);
		static EmployeePtr create_part_time(std::string name, std::string surname, std::string fathername, int day, int month, int year, int based_salary, int percent, int number_of_hours);

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
	private:
		EmployeePtr* _Worker;
		int _size;
	public:
		Employees();
		Employees(const Employees& other);
		int get_size() const;
		EmployeePtr operator[](int index) const;
		void add_worker(EmployeePtr f);
		void change_data(EmployeePtr f, int index);
		void delete_person(int index);
		void insert_person(EmployeePtr people, int index);
		void swap(Employees& other);
		~Employees();
	};

	int search_max_salary(const Employees& _Worker);
}