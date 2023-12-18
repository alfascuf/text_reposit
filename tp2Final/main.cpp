#include "part2.h"
#include "Archive.h"
#include "Header.h"

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	while (TRUE) {
		char* userWord;
		cout << "(1) ������ � ��������� ������ Student " << endl;
		cout << "(2) ����� ����������� � ����� � �������� ������ " << endl;
		cout << endl;
		cout << "(0) ����� �� ��������� " << endl;
		int choice;
		input(&choice);
		system("CLS");
		switch (choice) {
		case 1: {
			Archive* students = new Archive;
			while (TRUE) {
				cout << "������ � ��������� ������ Student" << endl;
				cout << "(1) �������� �������� � ������ " << endl;
				cout << "(2) ������ ������������ �������� " << endl;
				cout << "(3) ������� ������ ��������� �� ����� " << endl;
				cout << "(4) ������� ��������������� �� �������� ����� ������ ��������� �� ����� " << endl;
				cout << "(5) ������� ������ ��������� ������� ������ 4 � 5 �� ����� " << endl;
				cout << "(6) ������������� ������ ��������� " << endl;
				cout << endl;
				cout << "(0) ����� �� ��������� " << endl;
				input(&choice);
				system("CLS");
				switch (choice) {
				case 1: {
					++(*students);
					break;
				}
				case 2: {
					cout << "����� �������� � ������?" << endl;
					int num;
					input(&num);
					if (num <= students->getSize() && num > 0) {
						(*students) -= num;
						cout << "������� ������� �����" << endl;
					}
					else {
						cout << "������������ ����" << endl;
					}
					break;
				}
				case 3: {
					if (students->getSize() == 0) {
						cout << "������ ��������� ����" << endl;
					}
					else {
						cout << (*students) << endl;
					}
					break;
				}
				case 4: {
					if (students->getSize() == 0) {
						cout << "������ ��������� ����" << endl;
					}
					else {
						students->showSortedList();
					}
					break;
				}
				case 5: {
					if (students->getSize() == 0) {
						cout << "������ ��������� ����" << endl;
					}
					else {
						students->showWith4and5();
					}
					break;
				}
				case 6: {
					if (students->getSize()) {
						students->sortByAverageGrade();
						cout << "������ ������� ������������" << endl;
					}
					else {
						cout << "������ ��������� ����" << endl;
					}
					break;
				}
				case 0: {
					delete students;
					cout << "������ ��������� ��������" << endl;
					return;
				}
				default: {
					cout << "������������ ����" << endl;
					break;
				}
				}
				pressEnter();
			}
		}
		case 2: {
			cout << "������� ����� ��� ������:" << endl;
			userWord = getUserWord();
			findWordInFile(userWord);
			delete[] userWord;
			pressEnter();
			break;

		}
		case 0: {
			cout << "������ ��������� ���������" << endl;
			return;
		}
		default: {
			cout << "������������ ����" << endl;
			pressEnter();
			break;
		}
		}
	}
	return;
}
