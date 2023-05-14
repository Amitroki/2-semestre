#include <class/workers.h>
#include <iostream>
#include <string>

using namespace std;
using namespace workers;

int main() {
	Employees();
	setlocale(LC_ALL, "Russian");
	cout << "Перед вами многоуровневое меню." << endl;
	cout << "Возможные операции:" << endl;
	cout << "Вставить элемент в список" << endl;
	cout << "Удалить элемент из списка" << endl;
	cout << "Вывести список на экран" << endl;
	cout << "Найти работника с наибольшей заработной платой из списка" << endl;
	int command;
	cout << "Введите номер команды: ";
	cin >> command;
	switch (command) {
	case 1: {
		cout << "(1) Вставить элемент в конец / (2) вставить элемент по индексу" << endl;
		int a;
		cin >> a;
		switch (a) {
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		default:
			cout << "Введите корректное число";
			break;
		}
	}
	case 2: {
		cout << "(1) Удалить последний элемент / (2) Удалить элемент по индексу" << endl;
		int a;
		cin >> a;
		switch (a) {
		case 1:

			break;
		case 2:

			break;
		default:
			cout << "Введите корректное число";
			break;
		}
	}

	}

}