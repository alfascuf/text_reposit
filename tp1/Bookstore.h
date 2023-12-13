#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Bookstore {
public:
	Bookstore();
	Bookstore(int price, char t);
	Bookstore(Bookstore* orig);
	virtual ~Bookstore();

	virtual void print() = 0;
	virtual void setProduct() = 0;

	virtual void getFromFile(ifstream& fin) = 0;
	virtual void printInFile(ofstream& fout) = 0;

	void setPrice(int new_price);
	int getPrice();
	void setType(char s);
	char getType();

	void printFullType();
protected:
	void copyWord(char* orig, char* copy);
	void getWord(char* word, int count);
	void getWordF(ifstream& fin, char* word, int count);
private:
	int price;
	char type; //M - учебник   B - книга   C - канцелярия
	           //manual        book        chancellery
};
