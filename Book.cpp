#include "Book.h"


Book::Book() {
	cout << "Вызов конструктора Book без параметров" << endl;
	name = new char[50];
	author = new char[50];
	annotation = new char[500];
	genre = new char[20];

	releaseYear = 0;
	size = 0;
};
Book::Book(char* n, char* au, int rY, char* an, char* g, int s) {
	cout << "Вызов конструктора Book с параметрами" << endl;
	name = new char[50];
	author = new char[50];
	annotation = new char[500];
	genre = new char[20];

	setName(n);
	setAuthor(au);
	setReleaseYear(rY);
	setAnnotation(an);
	setGenre(g);
	setSize(s);
};
Book::Book(Book* orig) {
	cout << "Вызов конструктора копирования Book" << endl;
	name = new char[50];
	author = new char[50];
	annotation = new char[500];
	genre = new char[20];

	setName(orig->getName());
	setAuthor(orig->getAuthor());
	releaseYear = orig->getReleaseYear();
	setAnnotation(orig->getAnnotation());
	setGenre(orig->getGenre());
	size = orig->getSize();
};
Book::~Book() {
	cout << "Вызов деструктора Book" << endl;
	delete[] name;
	delete[] author;
	delete[] annotation;
	delete[] genre;
};

/////////////////////////////////////
//  Функции для работы с товаром  //

void Book::print() {
	cout << "Название книги      " << name << endl;
	cout << "Имя автора          " << author << endl;
	cout << "Год выпуска         " << releaseYear << endl;
	cout << "Аннотация           " << annotation << endl;
	cout << "Жанр                " << genre << endl;
	cout << "Количество страниц  " << size << endl;
	cout << "Цена книги          " << getPrice() << endl;
};
void Book::setProduct() {
	char* buffer = new char[20];
	cout << "Введите название книги      " << endl;
	getWord(name, 50);
	cout << "Введите имя автора          " << endl;
	getWord(author, 50);
	cout << "Введите год выпуска         " << endl;
	getWord(buffer, 20);
	setReleaseYear(atoi(buffer));
	cout << "Введите аннотацию           " << endl;
	getWord(annotation, 500);
	cout << "Введите жанр                " << endl;
	getWord(genre, 20);
	cout << "Введите количество страниц  " << endl;
	getWord(buffer, 20);
	setSize(atoi(buffer));
	cout << "Введите цену книги          " << endl;
	getWord(buffer, 20);
	setPrice(atoi(buffer));
	delete[] buffer;
};
void Book::getFromFile(ifstream& fin) {
	char* buffer = new char[20];
	getWordF(fin, name, 50);
	getWordF(fin, author, 50);
	getWordF(fin, buffer, 20);
	setReleaseYear(atoi(buffer));
	getWordF(fin, annotation, 500);
	getWordF(fin, genre, 20);
	getWordF(fin, buffer, 20);
	setSize(atoi(buffer));
	getWordF(fin, buffer, 20);
	setPrice(atoi(buffer));
	delete[] buffer;
};
void Book::printInFile(ofstream& fout) {
	fout << getType() << endl;
	fout << getName() << endl;
	fout << getAuthor() << endl;
	fout << getReleaseYear() << endl;
	fout << getAnnotation() << endl;
	fout << getGenre() << endl;
	fout << getSize() << endl;
	fout << getPrice() << endl;
};


////////////////////////////////////
//    Функции set и get       /////

void Book::setName(char* n) {
	copyWord(n, name);
};
char* Book::getName() {
	return name;
};

void Book::setAuthor(char* a) {
	copyWord(a, author);
};
char* Book::getAuthor() {
	return author;
};

void Book::setReleaseYear(int rY) {
	releaseYear = rY;
};
int Book::getReleaseYear() {
	return releaseYear;
};

void Book::setAnnotation(char* a) {
	copyWord(a, annotation);
};
char* Book::getAnnotation() {
	return annotation;
};

void Book::setGenre(char* g) {
	copyWord(g, genre);
};
char* Book::getGenre() {
	return genre;
};

void Book::setSize(int s) {
	size = s;
};
int Book::getSize() {
	return size;
};
