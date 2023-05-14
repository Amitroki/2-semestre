#include <class/Workers.h>
#include <iostream>
#include <string>

using namespace std;
using namespace workers;

void adding_on_last_pos_full_time_worker(Employees& _Worker) {
	std::string word1;
	std::string word2;
	std::string word3;
	int a;
	int b;
	int c;
	int d;
	cout << "������� ��� ���������: ";
	cin >> word1;
	cout << "������� ������� ���������: ";
	cin >> word2;
	cout << "������� �������� ���������: ";
	cin >> word3;
	cout << "������� ����, ����� � ��� ����������� ���������� �� ������: ";
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "������� ���������� ����� ����������: ";
	cin >> d;
	EmployeePtr full_time_worker = Employee::create_full_time(word1, word2, word3, a, b, c, d);
	_Worker.add_worker(full_time_worker);
}

void adding_on_last_pos_part_time_worker(Employees& _Worker) {
	std::string word1;
	std::string word2;
	std::string word3;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	cout << "������� ��� ���������: ";
	cin >> word1;
	cout << "������� ������� ���������: ";
	cin >> word2;
	cout << "������� �������� ���������: ";
	cin >> word3;
	cout << "������� ����, ����� � ��� ����������� ���������� �� ������: ";
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "������� ������� ������ ���������� �� ��� ������: ";
	cin >> d;
	cout << "������� ������� �������� ��� ������� ����������: ";
	cin >> e;
	cout << "������� ���������� ������������ ����������� ����� �� ��������� �����: ";
	cin >> f;
	EmployeePtr part_time_worker = Employee::create_part_time(word1, word2, word3, a, b, c, d, e, f);
	_Worker.add_worker(part_time_worker);
}

void adding_on_index_pos_full_time_worker(Employees& _Worker, int index) {
	std::string word1;
	std::string word2;
	std::string word3;
	int a;
	int b;
	int c;
	int d;
	cout << "������� ��� ���������: ";
	cin >> word1;
	cout << "������� ������� ���������: ";
	cin >> word2;
	cout << "������� �������� ���������: ";
	cin >> word3;
	cout << "������� ����, ����� � ��� ����������� ���������� �� ������: ";
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "������� ���������� ����� ����������: ";
	cin >> d;
	EmployeePtr full_time_worker = Employee::create_full_time(word1, word2, word3, a, b, c, d);
	_Worker.insert_person(full_time_worker, index);
}

void adding_on_index_pos_part_time_worker(Employees& _Worker, int index) {
	std::string word1;
	std::string word2;
	std::string word3;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	cout << "������� ��� ���������: ";
	cin >> word1;
	cout << "������� ������� ���������: ";
	cin >> word2;
	cout << "������� �������� ���������: ";
	cin >> word3;
	cout << "������� ����, ����� � ��� ����������� ���������� �� ������: ";
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "������� ������� ������ ���������� �� ��� ������: ";
	cin >> d;
	cout << "������� ������� �������� ��� ������� ����������: ";
	cin >> e;
	cout << "������� ���������� ������������ ����������� ����� �� ��������� �����: ";
	cin >> f;
	EmployeePtr part_time_worker = Employee::create_part_time(word1, word2, word3, a, b, c, d, e, f);
	_Worker.insert_person(part_time_worker, index);
}

int main() {
	Employees _Worker;
	setlocale(LC_ALL, "Russian");
	cout << "����� ���� �������������� ����." << endl;
	cout << "��������� ��������:" << endl;
	cout << "�������� ������� � ������" << endl;
	cout << "������� ������� �� ������" << endl;
	cout << "������� ������ �� �����" << endl;
	cout << "����� ��������� � ���������� ���������� ������ �� ������" << endl << endl;
	int command;
	cout << "������� ����� �������: ";
	cin >> command;
	cout << endl;
	switch (command) {
	case 1: {
		bool checker1 = true;
		while (checker1) {
			checker1 = false;
			cout << "(1) �������� ������� � ����� / (2) �������� ������� �� �������" << endl;
			cout << "�������� ��������: ";
			int q;
			cin >> q;
			cout << endl;
			switch (q) {
			case 1: {
				bool checker2 = true;
				while (checker2) {
					checker2 = false;
					cout << "�������� ��� ��������� � ������ ���������: (1) ������� ��������; (2) ��������������� ��������" << endl;
					cout << "�������� ��� ���������: ";
					int k;
					cin >> k;
					cout << endl;
					switch (k) {
					case 1: {
						adding_on_last_pos_full_time_worker(_Worker);
					} break;
					case 2: {
						adding_on_last_pos_part_time_worker(_Worker);
					} break;
					default: {
						cout << "������� ���������� ����� ���� �����������!";
						checker2 = true;
					}

					}
				}
			} break;
			case 2: {
				bool checker2 = true;
				int number;
				cout << "������� ������: ";
				cin >> number;
				while (checker2) {
					checker2 = false;
					cout << "�������� ��� ��������� � ������ ���������: (1) ������� ��������; (2) ��������������� ��������";
					cout << "�������� ��� ���������: ";
					int k;
					cin >> k;
					cout << endl;
					switch (k) {
					case 1: {
						adding_on_index_pos_full_time_worker(_Worker, number);
					}break;
					case 2: {
						adding_on_index_pos_part_time_worker(_Worker, number);
					}break;
					default: {
						cout << "������� ���������� ����� ���� �����������!";
						checker2 = true;
					}break;
					}
				}
			}break;
			default: {
				cout << "������� ���������� �����";
				checker1 = true;
			} break;
			}
		}
	} break;
	case 2: {
		bool checker1 = true;
		while (checker1) {
			checker1 = false;
			cout << "(1) ������� ��������� ������� / (2) ������� ������� �� �������" << endl;
			int a;
			cin >> a;
			switch (a) {
			case 1: {
				int pos = _Worker.get_size() - 1;
				_Worker.delete_person(pos);
			}break;
			case 2: {
				cout << "������� ������: ";
				int pos;
				cin >> pos;
				_Worker.delete_person(pos);
			}break;
			default: {
				cout << "������� ���������� ����� ��������!";
				checker1 = true;
			}break;
			}
		}
	} break; 
	case 3: {
		for (int i = 0; i < _Worker.get_size(); i++) {
			cout << _Worker[i] << endl;
		}
	}


	}

}