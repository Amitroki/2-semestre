#include <class/Workers.h>
#include <stdexcept>

using namespace workers;
using namespace std;

Employees::Employees() : _size(0) {}

int Employees::get_size() const {
	return _size;
}

Employee Employees :: operator[](const int index) const {
	if (index < 0 || _size <= index) {
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	return _Worker[index];
}
void Employees::add1(const Employee f) {
	if (_size == CAPACITY) {
		throw runtime_error("[EmployeeList::add1] Capacity is reached.");
	}
	_Worker[_size] = f;
	++_size;
}
void Employees::add2(const Employee f, int index) {
	if (0 > index || index > CAPACITY) {
		throw runtime_error("[EmployeeList::add1] Capacity is reached.");
	}
	_Worker[index] = f;
}
void Employees::remove(int index) {
	_size = 0;
}
void Employees::delete_person(int index) {
	if (index < 0 || _size <= index) {
		throw out_of_range("[Employees::operator[]] Index is out of range.");
	}
	Employee people;
	for (int i = index; i != CAPACITY - 1; i++) {
		_Worker[i] = _Worker[i + 1];
	}
	_size--;
}
void Employees::insert_person(Employee people, int index) {
	if (index < 0 || _size <= index) {
		throw out_of_range("[Employees::operator[]] Index is out of range.");
	}
	else {
		for (int i = _size - 1; i != index; i--) {
			_Worker[i + 1] = _Worker[i];
		}
	}
	_Worker[index] = people;
	_size++;
}
int workers::search_max_salary(const Employees& _Worker) {
	int max_index = -1;
	float max_salary = 0;

	auto n = _Worker.get_size();

	for (int i = 0; i < n; i++) {
		auto value = _Worker[i].calculating_salary();
		if (value > max_salary || max_index == -1) {
			max_index = i;
			max_salary = value;
		}
	}
	return max_index;
}