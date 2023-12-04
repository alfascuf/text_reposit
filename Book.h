#pragma once
#include "Bookstore.h"

class Book : public Bookstore {
public:
	Book();
	Book(char* name, char* author, int releaseYear, char* annotation, char* genre, int size);
	Book(Book* orig);
	~Book();

	void print();
	void setProduct();
	void getFromFile(ifstream& fin);
	void printInFile(ofstream& fout);

	void setName(char* n);
	char* getName();
	void setAuthor(char* a);
	char* getAuthor();
	void setReleaseYear(int rY);
	int getReleaseYear();
	void setAnnotation(char* a);
	char* getAnnotation();
	void setGenre(char* g);
	char* getGenre();
	void setSize(int s);
	int getSize();
private:
	// Книга : название, автор, год выпуска, аннотация, жанр, объем страниц
	char* name;
	char* author;
	int releaseYear;
	char* annotation;
	char* genre;
	int size;
};
