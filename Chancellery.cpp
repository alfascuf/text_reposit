#include "Chancellery.h"

Chancellery::Chancellery() {
	cout << "����� ������������ Chancellery ��� ����������" << endl;
	typeOf = new char[20];
	colour = new char[20];
	purpose = new char[100];
};
Chancellery::Chancellery(char* t, char* c, char* p) {
	cout << "����� ������������ Chancellery � �����������" << endl;
	typeOf = new char[20];
	colour = new char[20];
	purpose = new char[100];

	setTypeOf(t);
	setColour(c);
	setPurpose(p);
};
Chancellery::Chancellery(Chancellery* orig) {
	cout << "����� ������������ ����������� Chancellery" << endl;
	typeOf = new char[20];
	colour = new char[20];
	purpose = new char[100];

	setTypeOf(orig->getTypeOf());
	setColour(orig->getColour());
	setPurpose(orig->getPurpose());
};
Chancellery::~Chancellery() {
	cout << "����� ����������� Chancellery" << endl;
	delete[] typeOf;
	delete[] colour;
	delete[] purpose;
};

 ////////////////////////////////////
//  ������� ��� ������ � �������  //

void Chancellery::print() {
	cout << "��� ����������      " << getTypeOf() << endl;
	cout << "���� ����������     " << getColour() << endl;
	cout << "����������          " << getPurpose() << endl;
	cout << "���� ����������     " << getPrice() << endl;
};
void Chancellery::setProduct() {
	char* buffer = new char[20];
	cout << "������� ��� ����������             " << endl;
	getWord(typeOf,20);
	cout << "������� ���� ����������            " << endl;
	getWord(colour, 20);
	cout << "������� ���������� ����������      " << endl;
	getWord(purpose, 100);
	cout << "������� ���� ����������            " << endl;
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
//     ������� set � get     //////

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
