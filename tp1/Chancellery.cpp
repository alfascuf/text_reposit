#include "Chancellery.h"

Chancellery::Chancellery() {
	cout << "Вызов конструктора Chancellery без параметров" << endl;
	typeOf = new char[20];
	colour = new char[20];
	purpose = new char[100];
};
Chancellery::Chancellery(char* t, char* c, char* p) {
	cout << "Вызов конструктора Chancellery с параметрами" << endl;
	typeOf = new char[20];
	colour = new char[20];
	purpose = new char[100];

	setTypeOf(t);
	setColour(c);
	setPurpose(p);
};
Chancellery::Chancellery(Chancellery* orig) {
	cout << "Вызов конструктора копирования Chancellery" << endl;
	typeOf = new char[20];
	colour = new char[20];
	purpose = new char[100];

	setTypeOf(orig->getTypeOf());
	setColour(orig->getColour());
	setPurpose(orig->getPurpose());
};
Chancellery::~Chancellery() {
	cout << "Вызов деструктора Chancellery" << endl;
	delete[] typeOf;
	delete[] colour;
	delete[] purpose;
};

 ////////////////////////////////////
//  Функции для работы с товаром  //

void Chancellery::print() {
	cout << "Тип канцелярии      " << getTypeOf() << endl;
	cout << "Цвет канцелярии     " << getColour() << endl;
	cout << "Назначение          " << getPurpose() << endl;
	cout << "Цена канцелярии     " << getPrice() << endl;
};
void Chancellery::setProduct() {
	char* buffer = new char[20];
	cout << "Введите тип канцелярии             " << endl;
	getWord(typeOf,20);
	cout << "Введите цвет канцелярии            " << endl;
	getWord(colour, 20);
	cout << "Введите назначение канцелярии      " << endl;
	getWord(purpose, 100);
	cout << "Введите цену канцелярии            " << endl;
	getWord(buffer, 20);
	setPrice(atoi(buffer));
	delete[] buffer;
};
void Chancellery::getFromFile(ifstream& fin) {
	char* buffer = new char[20];
	getWordF(fin, typeOf, 20);
	getWordF(fin, colour, 20);
	getWordF(fin, purpose, 20);
	getWordF(fin, buffer, 20);
	setPrice(atoi(buffer));
	delete[] buffer;
};
void Chancellery::printInFile(ofstream& fout) {
	fout << getType() << endl;
	fout << getTypeOf() << endl;
	fout << getColour() << endl;
	fout << getPurpose() << endl;
	fout << getPrice() << endl;
};

////////////////////////////////////
//     Функции set и get     //////

void Chancellery::setTypeOf(char* tO) {
	copyWord(tO, typeOf);
};
char* Chancellery::getTypeOf() {
	return typeOf;
};
void Chancellery::setColour(char* c) {
	copyWord(c, colour);
};
char* Chancellery::getColour() {
	return colour;
};
void Chancellery::setPurpose(char* p) {
	copyWord(p, purpose);
};
char* Chancellery::getPurpose() {
	return purpose;
};
