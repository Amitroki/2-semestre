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
	cout << "Введите имя работника: ";
	cin >> word1;
	cout << "Введите фамилию работника: ";
	cin >> word2;
	cout << "Введите отчество работника: ";
	cin >> word3;
	cout << "Введите день, месяц и год поступления сотрудника на работу: " << endl;
	cin >> a;
	bool checker1 = true;
	while (checker1) {
		if (1 > a || a > 31) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите день: ";
			cin >> a;
		}
		else
			checker1 = false;
	}
	cin >> b;
	checker1 = true;
	while (checker1) {
		if (1 > b || b > 12) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите месяц: ";
			cin >> b;
		}
		else
			checker1 = false;
	}
	cin >> c;
	checker1 = true;
	while (checker1) {
		if (0 > c || c > 2023) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите год: ";
			cin >> c;
		}
		else
			checker1 = false;
	}
	cout << "Введите заработную плату сотрудника: ";
	cin >> d;
	checker1 = true;
	while (checker1) {
		if (1 > d) {
			cout << "Некорректное число, введите другое" << endl;
			cout << "Введите заработную плату сотрудника: ";
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
	cout << "Введите имя работника: ";
	cin >> word1;
	cout << "Введите фамилию работника: ";
	cin >> word2;
	cout << "Введите отчество работника: ";
	cin >> word3;
	cout << "Введите день, месяц и год поступления сотрудника на работу: " << endl;
	cin >> a;
	bool checker1 = true;
	while (checker1) {
		if (1 > a || a > 31) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите день: ";
			cin >> a;
		}
		else
			checker1 = false;
	}
	cin >> b;
	checker1 = true;
	while (checker1) {
		if (1 > b || b > 12) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите месяц: ";
			cin >> b;
		}
		else
			checker1 = false;
	}
	cin >> c;
	checker1 = true;
	while (checker1) {
		if (0 > c || c > 2023) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите год: ";
			cin >> c;
		}
		else
			checker1 = false;
	}
	cout << "Введите базовую ставку сотрудника за час работы: ";
	cin >> d;
	checker1 = true;
	while (checker1) {
		if (1 > d) {
			cout << "Некорректное выражение, введите другое" << endl;
			cout << "Введите заработную плату сотрудника за час: ";
			cin >> d;
		}
		else
			checker1 = false;
	}
	cout << "Введите процент надбавки (от 1% до 5%) для данного сотрудника: ";
	cin >> e;
	checker1 = true;
	while (checker1) {
		if (1 > e || e > 5) {
			cout << "Некорректное выражение, введите другое" << endl;
			cout << "Введите процент надбавки: ";
			cin >> e;
		}
		else
			checker1 = false;
	}
	cout << "Введите количество отработанных сотрудником часов за последний месяц: ";
	cin >> f;
	checker1 = true;
	while (checker1) {
		if (0 > f || f > 744) {
			cout << "Некорректное выражение, введите другое" << endl;
			cout << "Введите количество отработанных часов: ";
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
	cout << "Введите имя работника: ";
	cin >> word1;
	cout << "Введите фамилию работника: ";
	cin >> word2;
	cout << "Введите отчество работника: ";
	cin >> word3;
	cout << "Введите день, месяц и год поступления сотрудника на работу: " << endl;
	cin >> a;
	bool checker1 = true;
	while (checker1) {
		if (1 > a || a > 31) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите день: ";
			cin >> a;
		}
		else
			checker1 = false;
	}
	cin >> b;
	checker1 = true;
	while (checker1) {
		if (1 > b || b > 12) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите месяц: ";
			cin >> b;
		}
		else
			checker1 = false;
	}
	cin >> c;
	checker1 = true;
	while (checker1) {
		if (0 > c || c > 2023) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите год: ";
			cin >> c;
		}
		else
			checker1 = false;
	}
	cout << "Введите заработную плату сотрудника: ";
	cin >> d;
	checker1 = true;
	while (checker1) {
		if (1 > d) {
			cout << "Некорректное число, введите другое" << endl;
			cout << "Введите заработную плату сотрудника: ";
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
	cout << "Введите имя работника: ";
	cin >> word1;
	cout << "Введите фамилию работника: ";
	cin >> word2;
	cout << "Введите отчество работника: ";
	cin >> word3;
	cout << "Введите день, месяц и год поступления сотрудника на работу: ";
	cin >> a;
	bool checker1 = true;
	while (checker1) {
		if (1 > a || a > 31) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите день: ";
			cin >> a;
		}
		else
			checker1 = false;
	}
	cin >> b;
	checker1 = true;
	while (checker1) {
		if (1 > b || b > 12) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите месяц: ";
			cin >> b;
		}
		else
			checker1 = false;
	}
	cin >> c;
	checker1 = true;
	while (checker1) {
		if (0 > c || c > 2023) {
			cout << "Некорректная дата, введите другую" << endl;
			cout << "Введите год: ";
			cin >> c;
		}
		else
			checker1 = false;
	}
	cout << "Введите базовую ставку сотрудника за час работы: ";
	cin >> d;
	checker1 = true;
	while (checker1) {
		if (1 > d) {
			cout << "Некорректное выражение, введите другое" << endl;
			cout << "Введите заработную плату сотрудника за час: ";
			cin >> d;
		}
		else
			checker1 = false;
	}
	cout << "Введите процент надбавки (от 1% до 5%) для данного сотрудника: ";
	cin >> e;
	checker1 = true;
	while (checker1) {
		if (1 > e || e > 5) {
			cout << "Некорректное выражение, введите другое" << endl;
			cout << "Введите процент надбавки: ";
			cin >> e;
		}
		else
			checker1 = false;
	}
	cout << "Введите количество отработанных сотрудником часов за последний месяц: ";
	cin >> f;
	checker1 = true;
	while (checker1) {
		if (0 > f || f > 744) {
			cout << "Некорректное выражение, введите другое" << endl;
			cout << "Введите количество отработанных часов: ";
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
	cout << "Перед вами многоуровневое меню." << endl;
	while (flag) {
		cout << "Возможные операции:" << endl << endl;
		cout << "1) Вставить элемент в список" << endl;
		cout << "2) Удалить элемент из списка" << endl;
		cout << "3) Вывести список на экран" << endl;
		cout << "4) Найти работника с наибольшей заработной платой из списка" << endl;
		cout << "5) Завершение работы программы" << endl << endl;
		int command;
		cout << "Введите номер команды: ";
		cin >> command;
		cout << endl;
		switch (command) {
		case 1: {
			bool checker1 = true;
			while (checker1) {
				checker1 = false;
				cout << "(1) Вставить элемент в конец / (2) вставить элемент по индексу" << endl;
				cout << "Выберите действие: ";
				int q;
				cin >> q;
				cout << endl;
				switch (q) {
				case 1: {
					bool checker2 = true;
					while (checker2) {
						checker2 = false;
						cout << "Выберите тип вносимого в список работника: (1) Штатный работник; (2) Подрабатывающий работник" << endl;
						cout << "Выберите тип работника: ";
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
							cout << "Введите корректный номер типа работающего!" << endl;
							checker2 = true;
						}

						}
					}
				} break;
				case 2: {
					bool checker2 = true;
					int number;
					cout << "Введите индекс: ";
					cin >> number;
					bool size = true;
					while (size) {
						if (number < 0 || number > _Worker.get_size()) {
							cout << "Введите корректный индекс!" << endl;
							cout << "Введите индекс: ";
							cin >> number;
						}
						else
							size = false;
					}
					while (checker2) {
						checker2 = false;
						cout << "Выберите тип вносимого в список работника: (1) Штатный работник; (2) Подрабатывающий работник" << endl;
						cout << "Выберите тип работника: ";
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
							cout << "Введите корректный номер типа работающего!" << endl;
							checker2 = true;
						}break;
						}
					}
				}break;
				default: {
					cout << "Введите корректное число" << endl;
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
				cout << "(1) Удалить последний элемент / (2) Удалить элемент по индексу" << endl;
				cout << "Выберите действие: ";
				int a;
				cin >> a;
				switch (a) {
				case 1: {
					if (_Worker.get_size() == 0) {
						cout << "Невозможно удалить элемент в пустом массиве!" << endl;
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
						cout << "Невозможно удалить элемент в пустом массиве!" << endl;
						checker1 = false;
						break;
					}
					else {
						cout << "Введите индекс: ";
						int pos;
						cin >> pos;
						bool size = true;
						while (size) {
							if (pos < 0 || pos > _Worker.get_size()) {
								cout << "Введите корректный индекс!" << endl;
								cout << "Введите индекс: ";
								cin >> pos;
							}
							else
								size = false;
						}
						_Worker.delete_person(pos);
					}
				}break;
				default: {
					cout << "Введите корректный номер операции!" << endl;
					checker1 = true;
				}break;
				}
			}
		} break;
		case 3: {
			cout << "Все рабочие:" << endl;
			for (int i = 0; i < _Worker.get_size(); i++) {
				cout << "(" << i + 1 << ")" << endl;
				cout << _Worker[i] << endl;
			}
		} break;
		case 4: {
			cout << "Работником с наибольшей заработной платой является " << search_max_salary(_Worker) + 1 << " в списке работник" << endl;
			cout << _Worker[search_max_salary(_Worker)] << endl;
			cout << "Его заработная плата: " << _Worker[search_max_salary(_Worker)]->calculating_salary() << endl;
		} break;
		case 5: {
			flag = false;
		} break;

		}
	}

}