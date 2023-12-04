#include "Manual.h"

Manual::Manual() {
	cout << "Вызов констр Manual без парам-ов" << endl;
	name = new char[50];
	author = new char[50];
	educFacility = new char[100];

	releaseYear = 0;
	yearStudy = 0;
	size = 0;
};
Manual::Manual(char* n, char* a, int rY, char* eF, int yS, int s) {
	cout << "Вызов констр Manual с парам-ов" << endl;
	name = new char[50];
	author = new char[50];
	educFacility = new char[100];

	setName(n);
	setAuthor(a);
	releaseYear = rY;
	setEducFacility(eF);
	yearStudy = yS;
	size = s;
};
Manual::Manual(Manual* orig) {
	cout << "Вызов констр копирования Manual" << endl;
	name = new char[50];
	author = new char[50];
	educFacility = new char[100];

	setName(orig->getName());
	setAuthor(orig->getAuthor());
	releaseYear = orig->getReleaseYear();
	setEducFacility(orig->getEducFacility());
	setYearStudy(orig->getYearStudy());
	size = orig->getSize();
};
Manual::~Manual() {
	cout << "Вызов деструкт Manual" << endl;
	delete[] name;
	delete[] author;
	delete[] educFacility;
};

 ////////////////////////////////////
//  Функции для работы с товаром  //

void Manual::print() {
	cout << "Название учебника   " << name << endl;
	cout << "Имя автора          " << author << endl;
	cout << "Год выпуска         " << releaseYear << endl;
	cout << "Учебное заведение   " << educFacility << endl;
	cout << "Год обучения        " << yearStudy << endl;
	cout << "Количество страниц  " << size << endl;
	cout << "Цена книги          " << getPrice() << endl;
};
void Manual::setProduct() {
	char* buffer = new char[20];
	cout << "Введите название книги                " << endl;
	getWord(name, 50);
	cout << "Введите имя автора                    " << endl;
	getWord(author, 50);
	cout << "Введите год выпуска                   " << endl;
	getWord(buffer, 20);
	setReleaseYear(atoi(buffer));
	cout << "Введите название учебного заведения   " << endl;
	getWord(educFacility, 100);
	cout << "Введите год обучения                  " << endl;
	getWord(buffer, 20);
	setYearStudy(atoi(buffer));
	cout << "Введите размер книги                  " << endl;
	getWord(buffer, 20);
	setSize(atoi(buffer));
	cout << "Введите цену книги                    " << endl;
	getWord(buffer, 20);
	setPrice(atoi(buffer));
	delete[] buffer;
};
void Manual::getFromFile(ifstream& fin) {
	char* buffer = new char[20];
	getWordF(fin, name, 50);
	getWordF(fin, author, 50);
	getWordF(fin, buffer, 20);
	setReleaseYear(atoi(buffer));
	getWordF(fin, educFacility, 100);
	getWordF(fin, buffer, 20);
	setYearStudy(atoi(buffer));
	getWordF(fin, buffer, 20);
	setSize(atoi(buffer));
	getWordF(fin, buffer, 20);
	setPrice(atoi(buffer));
	delete[] buffer;
};
void Manual::printInFile(ofstream& fout) {
	fout << getType() << endl;
	fout << getName() << endl;
	fout << getAuthor() << endl;
	fout << getReleaseYear() << endl;
	fout << getEducFacility() << endl;
	fout << getYearStudy() << endl;
	fout << getSize() << endl;
	fout << getPrice() << endl;
};
 //////////////////////////////////
//   set  и  get    //////////////

void Manual::setName(char* n) {
	copyWord(n, name);
};
char* Manual::getName() {
	return name;
};
void Manual::setAuthor(char* a) {
	copyWord(a, author);
};
char* Manual::getAuthor() {
	return author;
};
void Manual::setReleaseYear(int rY) {
	releaseYear = rY;
};
int Manual::getReleaseYear() {
	return releaseYear;
};
void Manual::setEducFacility(char* eF) {
	copyWord(eF,educFacility);
};
char* Manual::getEducFacility() {
	return educFacility;
};
void Manual::setYearStudy(int yS) {
	yearStudy = yS;
};
int Manual::getYearStudy() {
	return yearStudy;
};
void Manual::setSize(int s) {
	size = s;
};
int Manual::getSize() {
	return size;
};
