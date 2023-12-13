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
		cout << "Книжный магазин. Действия:\n";
		cout << "1) Вывести ассортимент магазина на экран\n";
		cout << "2) Показать данные об определённом товаре\n";
		cout << "3) Добавить товар в магазин\n";
		cout << "4) Убрать товар из магазина\n";
		cout << "5) Изменить данные о товаре\n";
		cout << "6) Очистить ассортимент магазина\n\n";
		cout << "0) Выйти из магазина (ассортимент сохранится в файле)\n";
		input(&choice);
		system("CLS");
		switch (choice) {
		case 1:
		{
			if (shop->getSize() == 0)
				cout << "Ассортимент магазина пуст" << endl;
			else {
				cout << "Ассортимент магазина:" << endl;
				shop->print();
			}
			break;
		}
		case 2:
		{
			cout << "Номер товара?" << endl;
			int num;
			input(&num);
			if (num > shop->getSize() || num<=0)
				cout << "Нет товара с таким номером" << endl;
			else {
				cout << "#" << num << "  ";
				shop->printProduct(num);
			}
			break;
		}
		case 3:
		{
			cout << "Добавить ...\n";
			cout << "1) Книгу\n";
			cout << "2) Учебник\n";
			cout << "3) Канцелярию\n";
			input(&choice);
			system("CLS");
			if (choice >= 1 && choice <= 3) {
				shop->addProduct(choice);
				cout << "\nТовар успешно добавлен" << endl;
			}
			else
				cout << "\nНекорректный ввод, попробуйте ещё раз\n" << endl;
			break;
		}
		case 4:
		{
			cout << "Номер товара?" << endl;
			int num;
			input(&num);
			if (num > shop->getSize())
				cout << "Нет товара с таким номером" << endl;
			else {
				shop->takeProduct(num);
				cout << "Товар убран" << endl;
			}
			break;
		}
		case 5:
		{
			cout << "Номер товара?" << endl;
			int num;
			input(&num);
			if (num > shop->getSize())
				cout << "Нет товара с таким номером" << endl;
			else {
				shop->editProduct(num);
				cout << "Товар изменён" << endl;
			}
			break;
		}
		case 6:
		{
			--(*shop);
			cout << "Ассортимент очищен" << endl;
			break;
		}
		case 0: {
			shop->save();
			delete shop;
			return 0;
		}
		default: {
			cout << "Некорректный ввод, попробуйте ещё раз" << endl;
			break;
		}
		}
		pressEnter();
	}
};
