#include <class/Workers.h>
#include <stdexcept>

using namespace workers;
using namespace std;

Employees::Employees() : _Worker(nullptr), _size(0) {}

Employees::Employees(const Employees& other) :
	_Worker(new EmployeePtr[other._size]),
	_size(other._size)
{
	for (int i = 0; i < _size; i++) {
		_Worker[i] = new Employee(*other._Worker[i]);
	}
}
int Employees::get_size() const {
	return _size;
}
EmployeePtr Employees :: operator[](const int index) const {
	if (index < 0 || _size <= index) {
		throw out_of_range("[EmployeeList::operator[]] Index is out of range.");
	}
	return _Worker[index];
}
void Employees::add_worker(const EmployeePtr f) {
	auto new_Employee = new EmployeePtr[_size + 1];
	for (int i = 0; i < _size; i++) {
		new_Employee[i] = _Worker[i];
	}
	delete[] _Worker;

	new_Employee[_size] = f;

	_Worker = new_Employee;

	++_size;
}
void Employees::delete_person(int index) {
	if (index < 0 || _size <= index) {
		throw out_of_range("[Employees::operator[]] Index is out of range.");
	}
	auto new_Employee = new EmployeePtr[_size - 1];
	for (int i = 0; i < index; i++) {
		new_Employee[i] = _Worker[i];
	}
	for (int i = index; i <= _size - 2; i++) {
		new_Employee[i] = _Worker[i + 1];
	}
	delete[] _Worker;
	_Worker = new_Employee;
	_size--;
}
void Employees::insert_person(EmployeePtr people, int index) {
	if (index < 0 || _size <= index) {
		throw out_of_range("[Employees::operator[]] Index is out of range.");
	}
	auto new_Employee = new EmployeePtr[_size + 1];
	for (int i = 0; i < index; i++) {
		new_Employee[i] = _Worker[i];
	}
	new_Employee[index] = people;
	for (int i = (index + 1); i < (_size + 1); i++) {
		new_Employee[i] = _Worker[i - 1];
	}
	delete[] _Worker;
	_Worker = new_Employee;
	_size++;
}
void Employees::change_data(const EmployeePtr f, int index) {
	if (index < 0 || _size < index) {
		throw out_of_range("[Employees::operator[]] Index is out of range.");
	}
	_Worker[index] = f;
}
void Employees::swap(Employees& other) {
	std::swap(this->_Worker, other._Worker);
	std::swap(this->_size, other._size);
}
Employees::~Employees() {
	for (int i = 0; i < _size; ++i) {
		delete _Worker[i];
	}
	delete[] _Worker;
}
int workers::search_max_salary(const Employees& _Worker) {
	int max_index = -1;
	float max_salary = 0;

	auto n = _Worker.get_size();

	for (int i = 0; i < n; i++) {
		auto value = _Worker[i]->calculating_salary();
		if (value > max_salary || max_index == -1) {
			max_index = i;
			max_salary = value;
		}
	}
	return max_index;
}