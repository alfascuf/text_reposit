#include "Bookstore.h"

Bookstore::Bookstore() {
	cout << "����� ������������ Bookstore ��� ����������" << endl;
	price = 0;
	type = 'B';
};
Bookstore::Bookstore(int p, char t) {
	cout << "����� ������������ Bookstore � �����������" << endl;
	price = p;
	type = t;
};
Bookstore::Bookstore(Bookstore* orig) {
	cout << "����� ������������ ����������� Bookstore" << endl;
	price = orig->getPrice();
	type = orig->getType();
};
Bookstore::~Bookstore() {
	cout << "����� ����������� Bookstore" << endl;
};

 ////////////////////////////////
///  ������� set � get  ////////

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
		cout << "�����";
		break;
	}
	case 'M': {
		cout << "�������";
		break;
	}
	case 'C': {
		cout << "����������";
		break;
	}
	}
};

 ///////////////////////////////////
// ������� ��� ������ � �������� //

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
