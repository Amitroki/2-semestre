#include <iostream>
#include <string>
#include <class/workers.h>

using namespace std;
using namespace workers;

int main() {
	Employees();
	cout << "����� ���� �������������� ����." << endl;
	cout << "��������� ��������:" << endl;
	cout << "�������� ������� � ������" << endl;
	cout << "������� ������� �� ������" << endl;
	cout << "������� ������ �� �����" << endl;
	cout << "����� ��������� � ���������� ���������� ������ �� ������" << endl;
	int command;
	cout << "������� ����� �������: ";
	cin >> command;
	switch(command)
		case 1:
			cout << "(1) �������� ������� � ����� / (2) �������� ������� �� �������" << endl;
			int a;
			cin >> a;
			switch (a) {
				case 1: 

					break;
				case 2:

					break;
				default:
					cout << "������� ���������� �����";
					break;
			}
		case 2: 
			cout << "(1) ������� ��������� ������� / (2) ������� ������� �� �������" << endl;
			int a;
			cin >> a;
			switch (a) {
			case 1:

				break;
			case 2:

				break;
			default:
				cout << "������� ���������� �����";
				break;
			}


}