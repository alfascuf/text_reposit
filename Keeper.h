#pragma once
#include "Bookstore.h"
#include "Book.h"
#include "Manual.h"
#include "Chancellery.h"

class Keeper {
public:
	Keeper();
	Keeper(int count);
	Keeper(Keeper* orig);
	~Keeper();

	void setLimit(int count);
	int getLimit();
	void setSize(int count);
	int getSize();

	void print();
	Keeper& operator -- ();  // очистить ассортимент
	void checkLimit();

	void printProduct(int count);
	void addProduct(int type);
	void takeProduct(int count);
	void editProduct(int count);

	void save();
	void load();
private:
	Bookstore** storage;
	int size;
	int limit;
};