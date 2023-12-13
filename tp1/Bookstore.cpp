#include "Bookstore.h"

Bookstore::Bookstore() {
	cout << "Вызов конструктора Bookstore без параметров" << endl;
	price = 0;
	type = 'B';
};
Bookstore::Bookstore(int p, char t) {
	cout << "Вызов конструктора Bookstore с параметрами" << endl;
	price = p;
	type = t;
};
Bookstore::Bookstore(Bookstore* orig) {
	cout << "Вызов конструктора копирования Bookstore" << endl;
	price = orig->getPrice();
	type = orig->getType();
};
Bookstore::~Bookstore() {
	cout << "Вызов деструктора Bookstore" << endl;
};

 ////////////////////////////////
///  Функции set и get  ////////

void Bookstore::setPrice(int new_price) {
	price = new_price;
};
int Bookstore::getPrice() {
	return price;
};
void Bookstore::setType(char s) {
	type = s;
};
char Bookstore::getType() {
	return type;
};

/////////////////////////////

void Bookstore::printFullType() {
	switch (type) {
	case 'B':{
		cout << "Книга";
		break;
	}
	case 'M': {
		cout << "Учебник";
		break;
	}
	case 'C': {
		cout << "Канцелярия";
		break;
	}
	}
};

 ///////////////////////////////////
// Функции для работы с строками //

void Bookstore::copyWord(char* orig, char* copy) {
	int i = 0;
	while ((copy[i] = orig[i++]) != '\0');
}
void Bookstore::getWord(char* word, int count) {
	char c;
	int i;
	for (i = 0;(i < count - 1) && ((c=getchar()) != '\n');word[i++] = c)
		;
	word[i] = '\0';
	if (i == count - 1) {
		while ((c = getchar()) != '\n');
	}
};
void Bookstore::getWordF(ifstream& fin, char* word, int count) {
	char c;
	int i = 0;
	while (((c = fin.get()) != '\n') && (!fin.eof()) && (i < count - 1)) {
		word[i++] = c;
	};
	word[i] = '\0';
	if (i == count - 1) {
		while ((c = fin.get()) != '\n');
	}
};
