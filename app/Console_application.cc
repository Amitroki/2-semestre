#include <class/workers.h>
#include <iostream>
#include <string>
#include <windows.h>

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
	cout << "������� ����, ����� � ��� ����������� ���������� �� ������: " << endl;
	cin >> a;
	bool checker1 = true;
	while (checker1) {
		if (1 > a || a > 31) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� ����: ";
			cin >> a;
		}
		else
			checker1 = false;
	}
	cin >> b;
	checker1 = true;
	while (checker1) {
		if (1 > b || b > 12) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� �����: ";
			cin >> b;
		}
		else
			checker1 = false;
	}
	cin >> c;
	checker1 = true;
	while (checker1) {
		if (0 > c || c > 2023) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� ���: ";
			cin >> c;
		}
		else
			checker1 = false;
	}
	cout << "������� ���������� ����� ����������: ";
	cin >> d;
	checker1 = true;
	while (checker1) {
		if (1 > d) {
			cout << "������������ �����, ������� ������" << endl;
			cout << "������� ���������� ����� ����������: ";
			cin >> d;
		}
		else
			checker1 = false;
	}
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
	cout << "������� ����, ����� � ��� ����������� ���������� �� ������: " << endl;
	cin >> a;
	bool checker1 = true;
	while (checker1) {
		if (1 > a || a > 31) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� ����: ";
			cin >> a;
		}
		else
			checker1 = false;
	}
	cin >> b;
	checker1 = true;
	while (checker1) {
		if (1 > b || b > 12) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� �����: ";
			cin >> b;
		}
		else
			checker1 = false;
	}
	cin >> c;
	checker1 = true;
	while (checker1) {
		if (0 > c || c > 2023) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� ���: ";
			cin >> c;
		}
		else
			checker1 = false;
	}
	cout << "������� ������� ������ ���������� �� ��� ������: ";
	cin >> d;
	checker1 = true;
	while (checker1) {
		if (1 > d) {
			cout << "������������ ���������, ������� ������" << endl;
			cout << "������� ���������� ����� ���������� �� ���: ";
			cin >> d;
		}
		else
			checker1 = false;
	}
	cout << "������� ������� �������� (�� 1% �� 5%) ��� ������� ����������: ";
	cin >> e;
	checker1 = true;
	while (checker1) {
		if (1 > e || e > 5) {
			cout << "������������ ���������, ������� ������" << endl;
			cout << "������� ������� ��������: ";
			cin >> e;
		}
		else
			checker1 = false;
	}
	cout << "������� ���������� ������������ ����������� ����� �� ��������� �����: ";
	cin >> f;
	checker1 = true;
	while (checker1) {
		if (0 > f || f > 744) {
			cout << "������������ ���������, ������� ������" << endl;
			cout << "������� ���������� ������������ �����: ";
			cin >> f;
		}
		else
			checker1 = false;
	}
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
	cout << "������� ����, ����� � ��� ����������� ���������� �� ������: " << endl;
	cin >> a;
	bool checker1 = true;
	while (checker1) {
		if (1 > a || a > 31) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� ����: ";
			cin >> a;
		}
		else
			checker1 = false;
	}
	cin >> b;
	checker1 = true;
	while (checker1) {
		if (1 > b || b > 12) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� �����: ";
			cin >> b;
		}
		else
			checker1 = false;
	}
	cin >> c;
	checker1 = true;
	while (checker1) {
		if (0 > c || c > 2023) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� ���: ";
			cin >> c;
		}
		else
			checker1 = false;
	}
	cout << "������� ���������� ����� ����������: ";
	cin >> d;
	checker1 = true;
	while (checker1) {
		if (1 > d) {
			cout << "������������ �����, ������� ������" << endl;
			cout << "������� ���������� ����� ����������: ";
			cin >> d;
		}
		else
			checker1 = false;
	}
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
	bool checker1 = true;
	while (checker1) {
		if (1 > a || a > 31) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� ����: ";
			cin >> a;
		}
		else
			checker1 = false;
	}
	cin >> b;
	checker1 = true;
	while (checker1) {
		if (1 > b || b > 12) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� �����: ";
			cin >> b;
		}
		else
			checker1 = false;
	}
	cin >> c;
	checker1 = true;
	while (checker1) {
		if (0 > c || c > 2023) {
			cout << "������������ ����, ������� ������" << endl;
			cout << "������� ���: ";
			cin >> c;
		}
		else
			checker1 = false;
	}
	cout << "������� ������� ������ ���������� �� ��� ������: ";
	cin >> d;
	checker1 = true;
	while (checker1) {
		if (1 > d) {
			cout << "������������ ���������, ������� ������" << endl;
			cout << "������� ���������� ����� ���������� �� ���: ";
			cin >> d;
		}
		else
			checker1 = false;
	}
	cout << "������� ������� �������� (�� 1% �� 5%) ��� ������� ����������: ";
	cin >> e;
	checker1 = true;
	while (checker1) {
		if (1 > e || e > 5) {
			cout << "������������ ���������, ������� ������" << endl;
			cout << "������� ������� ��������: ";
			cin >> e;
		}
		else
			checker1 = false;
	}
	cout << "������� ���������� ������������ ����������� ����� �� ��������� �����: ";
	cin >> f;
	checker1 = true;
	while (checker1) {
		if (0 > f || f > 744) {
			cout << "������������ ���������, ������� ������" << endl;
			cout << "������� ���������� ������������ �����: ";
			cin >> f;
		}
		else
			checker1 = false;
	}
	EmployeePtr part_time_worker = Employee::create_part_time(word1, word2, word3, a, b, c, d, e, f);
	_Worker.insert_person(part_time_worker, index);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Employees _Worker;
	bool flag = true;
	cout << "����� ���� �������������� ����." << endl;
	while (flag) {
		cout << "��������� ��������:" << endl << endl;
		cout << "1) �������� ������� � ������" << endl;
		cout << "2) ������� ������� �� ������" << endl;
		cout << "3) ������� ������ �� �����" << endl;
		cout << "4) ����� ��������� � ���������� ���������� ������ �� ������" << endl;
		cout << "5) ���������� ������ ���������" << endl << endl;
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
							cout << "������� ���������� ����� ���� �����������!" << endl;
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
					bool size = true;
					while (size) {
						if (number < 0 || number > _Worker.get_size()) {
							cout << "������� ���������� ������!" << endl;
							cout << "������� ������: ";
							cin >> number;
						}
						else
							size = false;
					}
					while (checker2) {
						checker2 = false;
						cout << "�������� ��� ��������� � ������ ���������: (1) ������� ��������; (2) ��������������� ��������" << endl;
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
							cout << "������� ���������� ����� ���� �����������!" << endl;
							checker2 = true;
						}break;
						}
					}
				}break;
				default: {
					cout << "������� ���������� �����" << endl;
					checker1 = true;
				} break;
				}
			}
		} break;
		case 2: {
			bool checker1 = true;
			if (_Worker.get_size() == 0)
				bool checker1 = false;
			while (checker1) {
				checker1 = false;
				cout << "(1) ������� ��������� ������� / (2) ������� ������� �� �������" << endl;
				cout << "�������� ��������: ";
				int a;
				cin >> a;
				switch (a) {
				case 1: {
					if (_Worker.get_size() == 0) {
						cout << "���������� ������� ������� � ������ �������!" << endl;
						checker1 = false;
						break;
					}
					else {
						int pos = _Worker.get_size() - 1;
						_Worker.delete_person(pos);
					}
				}break;
				case 2: {
					if (_Worker.get_size() == 0) {
						cout << "���������� ������� ������� � ������ �������!" << endl;
						checker1 = false;
						break;
					}
					else {
						cout << "������� ������: ";
						int pos;
						cin >> pos;
						bool size = true;
						while (size) {
							if (pos < 0 || pos > _Worker.get_size()) {
								cout << "������� ���������� ������!" << endl;
								cout << "������� ������: ";
								cin >> pos;
							}
							else
								size = false;
						}
						_Worker.delete_person(pos);
					}
				}break;
				default: {
					cout << "������� ���������� ����� ��������!" << endl;
					checker1 = true;
				}break;
				}
			}
		} break;
		case 3: {
			cout << "��� �������:" << endl;
			for (int i = 0; i < _Worker.get_size(); i++) {
				cout << "(" << i + 1 << ")" << endl;
				cout << _Worker[i] << endl;
			}
		} break;
		case 4: {
			cout << "���������� � ���������� ���������� ������ �������� " << search_max_salary(_Worker) + 1 << " � ������ ��������" << endl;
			cout << _Worker[search_max_salary(_Worker)] << endl;
			cout << "��� ���������� �����: " << _Worker[search_max_salary(_Worker)]->calculating_salary() << endl;
		} break;
		case 5: {
			flag = false;
		} break;

		}
	}

}