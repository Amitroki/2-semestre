#include <class/workers.h>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
using namespace workers;

void adding_on_index_pos_full_time_worker(Employees& _worker, int index) {
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
	cout << endl << endl;
	_worker.add_worker(make_shared<FullEmployee>(word1, word2, word3, a, b, c, d));
}

void adding_on_index_pos_part_time_worker(Employees& _worker, int index) {
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
	cout << endl << endl;
	_worker.add_worker(make_shared<PartEmployee>(word1, word2, word3, a, b, c, d, e, f));
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Employees _worker;
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
				cout << endl << endl;
				switch (q) {
				case 1: {
					bool checker2 = true;
					while (checker2) {
						checker2 = false;
						cout << "�������� ��� ��������� � ������ ���������: (1) ������� ��������; (2) ��������������� ��������" << endl;
						cout << "�������� ��� ���������: ";
						int k;
						cin >> k;
						cout << endl << endl;
						switch (k) {
						case 1: {
							adding_on_index_pos_full_time_worker(_worker, _worker.size());
						} break;
						case 2: {
							adding_on_index_pos_part_time_worker(_worker, _worker.size());
						} break;
						default: {
							cout << "������� ���������� ����� ���� �����������!" << endl << endl;
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
						if (number < 0 || number > _worker.size()) {
							cout << "������� ���������� ������!" << endl << endl;
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
						cout << endl << endl;
						switch (k) {
						case 1: {
							adding_on_index_pos_full_time_worker(_worker, number);
						}break;
						case 2: {
							adding_on_index_pos_part_time_worker(_worker, number);
						}break;
						default: {
							cout << "������� ���������� ����� ���� �����������!" << endl << endl;
							checker2 = true;
						}break;
						}
					}
				}break;
				default: {
					cout << "������� ���������� �����" << endl << endl;
					checker1 = true;
				} break;
				}
			}
		} break;
		case 2: {
			bool checker1 = true;
			if (_worker.size() == 0)
				bool checker1 = false;
			while (checker1) {
				checker1 = false;
				cout << "(1) ������� ��������� ������� / (2) ������� ������� �� �������" << endl;
				cout << "�������� ��������: ";
				int a;
				cin >> a;
				switch (a) {
				case 1: {
					if (_worker.size() == 0) {
						cout << "���������� ������� ������� � ������ �������!" << endl << endl;
						checker1 = false;
						break;
					}
					else {
						int pos = _worker.size() - 1;
						_worker.delete_person(pos);
					}
				}break;
				case 2: {
					if (_worker.size() == 0) {
						cout << "���������� ������� ������� � ������ �������!" << endl << endl;
						checker1 = false;
						break;
					}
					else {
						cout << "������� ������: ";
						int pos;
						cin >> pos;
						bool size = true;
						while (size) {
							if (pos < 0 || pos > _worker.size()) {
								cout << "������� ���������� ������!" << endl;
								cout << "������� ������: ";
								cin >> pos;
								cout << endl << endl;
							}
							else
								size = false;
						}
						_worker.delete_person(pos);
					}
				}break;
				default: {
					cout << "������� ���������� ����� ��������!" << endl << endl;
					checker1 = true;
				}break;
				}
			}
		} break;
		case 3: {
			cout << "��� �������:" << endl;
			for (int i = 0; i < _worker.size(); i++) {
				cout << "(" << i + 1 << ")" << endl;
				_worker[i]->print();
				cout << endl;
			}
		} break;
		case 4: {
			int checker = _worker.size();
			if (checker > 0) {
				cout << "���������� � ���������� ���������� ������ �������� " << search_max_salary(_worker) + 1 << " � ������ ��������" << endl;
				_worker[search_max_salary(_worker)]->print();
				cout << "��� ������� ���������� �����: " << _worker[search_max_salary(_worker)]->calculating_salary() << endl << endl;
			}
			else {
				cout << "������ ����, ������� ���" << endl << endl;
			}
		} break;
		case 5: {
			flag = false;
		} break;

		}
	}

}