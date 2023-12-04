#include "Keeper.h"

Keeper::Keeper() {
	cout << "Вызов конструктора Keeper без параметров" << endl;
	storage = new Bookstore * [5];
	limit = 5;
	size = 0;
};
Keeper::Keeper(int count) {
	cout << "Вызов конструктора Keeper с параметрами" << endl;
	storage = new Bookstore * [count];
	limit = count;
	size = 0;
};
Keeper::Keeper(Keeper* orig) {
	cout << "Вызов конструктора копирования Keeper" << endl;
	this->setLimit(orig->getLimit());
	this->setSize(orig->getSize());
	storage = new Bookstore * [limit];
	for (int i = 0;i < size;++i) {
		this->storage[i] = orig->storage[i];
	}
};
Keeper::~Keeper() {
	cout << "Вызов деструктора Keeper" << endl;
	--(*this);
	delete[] storage;
};

 ////////////////////////////////
//  Функции set и get  /////////

void Keeper::setLimit(int count) {
	limit = count;
};
int Keeper::getLimit() {
	return limit;
};
void Keeper::setSize(int count) {
	size = count;
};
int Keeper::getSize() {
	return size;
};

 ////////////////////////////////
//  Работа со складом  /////////

void Keeper::print() {
	for (int i = 1;i <= size;++i) {
		cout << "#" << i << "  ";
		printProduct(i);
		cout << "\n\n";
	}
};
Keeper& Keeper::operator -- () {
	while (size > 0) {
		takeProduct(size);
	}
	return *this;
};
void Keeper::checkLimit() {
	if (size == limit) {
		limit += 5;
	}
	else if ((size == limit - 10) && (limit >= 10)) {
		limit -= 5;
	}
	else {
		return;
	}

	Bookstore** newStorage = new Bookstore * [limit];
	for (int i = 0;i < size;++i) {
		newStorage[i] = storage[i];
	}
	delete[] storage;
	storage = newStorage;
}

void Keeper::printProduct(int count) {
	storage[count - 1]->printFullType();
	putchar('\n');
	storage[count - 1]->print();
};

void Keeper::addProduct(int type) {
	checkLimit();
	try {
		switch (type) {
		case 1: {
			storage[size] = new Book;
			storage[size]->setType('B');
			break;
		}
		case 2: {
			storage[size] = new Manual;
			storage[size]->setType('M');
			break;
		}
		case 3: {
			storage[size] = new Chancellery;
			storage[size]->setType('C');
			break;
		}
		default: {
			throw "Возникла ошибка при создании товара";
			break;
		}
		}
	}
	catch (const char* ex) {
		std::cout << ex << endl;
		return;
	}
	storage[size++]->setProduct();
};
void Keeper::takeProduct(int count) {
	checkLimit();
	--count;
	delete storage[count];
	while (count + 1 < size) {
		storage[count] = storage[count + 1];
		++count;
	}
	storage[count] = nullptr;
	--size;
};
void Keeper::editProduct(int count) {
	cout << "Текущий вид товара:" << endl;
	printProduct(count);
	cout << endl;
	storage[count-1]->setProduct();
};

 ////////////////////////////////////
//  Сохранение и загрузка в файл  //

void Keeper::save() {
	ofstream fout;
	fout.open("storage.txt");
	if (!fout.is_open()) {
		std::cout << "Возникла ошибка при открытии файла, данные не сохранены" << endl;
		return;
	}
	for (int i = 0;i < size;i++) {
		storage[i]->printInFile(fout);
	}
	std::cout << "Данные успешно сохранены" << endl;
	fout.close();
};
void Keeper::load() {
	ifstream fin;
	fin.open("storage.txt");
	try {
	if (!fin.is_open()) {
		throw "Возникла ошибка при открытии файла, ассортимент будет пуст";
	}
	else if (fin.peek() == EOF) {
		throw "Файл пуст, ассортимент пуст";
		fin.close();
	}
	}
	catch (const char* ex) {
		std::cout << ex << endl;
		return;
	}
	int i = 0;
	char type;
	while (!(fin.peek() == EOF)) {
		checkLimit();
		fin.get(type);
		fin.get();
		try {
			switch (type) {
			case 'B': {
				storage[size] = new Book;
				break;
			}
			case 'M': {
				storage[size] = new Manual;
				break;
			}
			case 'C': {
				storage[size] = new Chancellery;
				break;
			}
			default: {
				throw "Ошибка при загрузке данных из файла, ассортимент очищен";
				break;
			}
			}
		}
		catch (const char* ex) { 
			--(*this);
			std::cout << ex << endl;
			fin.close();
			return;
		}

		storage[size]->setType(type);
		storage[size++]->getFromFile(fin);
	}
	std::cout << "Загрузка данных из файла прошла успешно" << endl;
	fin.close();
	return;
};
