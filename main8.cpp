#include "Keeper.h"
#include "Header.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	Keeper* shop = new Keeper;
	shop->load();
	pressEnter();

	while (true) {
		int choice;
		cout << "������� �������. ��������:\n";
		cout << "1) ������� ����������� �������� �� �����\n";
		cout << "2) �������� ������ �� ����������� ������\n";
		cout << "3) �������� ����� � �������\n";
		cout << "4) ������ ����� �� ��������\n";
		cout << "5) �������� ������ � ������\n";
		cout << "6) �������� ����������� ��������\n\n";
		cout << "0) ����� �� �������� (����������� ���������� � �����)\n";
		input(&choice);
		system("CLS");
		switch (choice) {
		case 1:
		{
			if (shop->getSize() == 0)
				cout << "����������� �������� ����" << endl;
			else {
				cout << "����������� ��������:" << endl;
				shop->print();
			}
			break;
		}
		case 2:
		{
			cout << "����� ������?" << endl;
			int num;
			input(&num);
			if (num > shop->getSize() || num<=0)
				cout << "��� ������ � ����� �������" << endl;
			else {
				cout << "#" << num << "  ";
				shop->printProduct(num);
			}
			break;
		}
		case 3:
		{
			cout << "�������� ...\n";
			cout << "1) �����\n";
			cout << "2) �������\n";
			cout << "3) ����������\n";
			input(&choice);
			system("CLS");
			if (choice >= 1 && choice <= 3) {
				shop->addProduct(choice);
				cout << "\n����� ������� ��������" << endl;
			}
			else
				cout << "\n������������ ����, ���������� ��� ���\n" << endl;
			break;
		}
		case 4:
		{
			cout << "����� ������?" << endl;
			int num;
			input(&num);
			if (num > shop->getSize())
				cout << "��� ������ � ����� �������" << endl;
			else {
				shop->takeProduct(num);
				cout << "����� �����" << endl;
			}
			break;
		}
		case 5:
		{
			cout << "����� ������?" << endl;
			int num;
			input(&num);
			if (num > shop->getSize())
				cout << "��� ������ � ����� �������" << endl;
			else {
				shop->editProduct(num);
				cout << "����� ������" << endl;
			}
			break;
		}
		case 6:
		{
			--(*shop);
			cout << "����������� ������" << endl;
			break;
		}
		case 0: {
			shop->save();
			delete shop;
			return 0;
		}
		default: {
			cout << "������������ ����, ���������� ��� ���" << endl;
			break;
		}
		}
		pressEnter();
	}
};
