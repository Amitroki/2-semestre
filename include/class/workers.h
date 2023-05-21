#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <vector>

namespace workers {

	class Employee;
	using EmployeePtr = std::shared_ptr<Employee>;

	class Employee {
	public:

		Employee(std::string name, std::string surname, std::string fathername, int day, int month, int year);

		virtual double calculating_salary() const = 0;

		virtual EmployeePtr clone() const = 0;

		std::string get_name() const;
		void set_name(std::string worker_name);

		std::string get_surname() const;
		void set_surname(std::string worker_surname);

		std::string get_fathername() const;
		void set_fathername(std::string worker_fathername);

		int get_day() const;
		void set_day(int day);

		int get_month() const;
		void set_month(int month);

		int get_year() const;
		void set_year(int year);

		virtual ~Employee() = default;

		virtual std::ostream& print(std::ostream & = std::cout) const = 0;

	protected:

		std::string _name;
		std::string _surname;
		std::string _fathername;
		int _day;
		int _month;
		int _year;

		Employee() = default;
		Employee(const Employee&) = default;
		Employee& operator=(const Employee&) = default;
	};

	class FullEmployee : public Employee {
	private:
		int _salary;

	public:

		FullEmployee(std::string name, std::string surname, std::string fathername, int day, int month, int year, int salary);

		int get_salary() const;
		void set_salary(int count);

		double calculating_salary() const override;

		EmployeePtr clone() const override;

		std::ostream& print(std::ostream& os) const override;

	};

	class PartEmployee : public Employee {
	private:

		int _based_salary;
		int _percent;
		int _number_of_hours;

	public:

		PartEmployee(std::string name, std::string surname, std::string fathername, int day, int month, int year, int based_salary, int percent, int number_of_hours);

		int get_based_salary() const;
		void set_based_salary(int count);

		int get_percent() const;
		void set_percent(int number);

		int get_number_of_hours() const;
		void set_number_of_hours(int number_of_hours);

		double calculating_salary() const override;

		EmployeePtr clone() const override;

		std::ostream& print(std::ostream& os) const override;

	};

	class Employees {
	private:

		std::vector<EmployeePtr> _worker;

	public:

		Employees() = default;
		Employees(const Employees& other);
		int size() const;
		EmployeePtr operator[](int index) const;
		Employees& operator=(const Employees& other);
		void add_worker(EmployeePtr f);
		void delete_person(int index);
		void insert_person(EmployeePtr people, int index);
		void swap(Employees& other);
	};

	int search_max_salary(const Employees& _worker);
}