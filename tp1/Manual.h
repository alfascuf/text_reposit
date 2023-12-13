#pragma once
#include "Bookstore.h"

class Manual : public Bookstore {
public:
	Manual();
	Manual(char* n, char* a, int rY, char* eF, int yS, int s);
	Manual(Manual* orig);
	~Manual();

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
	void setEducFacility(char* eF);
	char* getEducFacility();
	void setYearStudy(int yS);
	int getYearStudy();
	void setSize(int s);
	int getSize();
private:

	char* name;
	char* author;
	int releaseYear;
	char* educFacility;
	int yearStudy;
	int size;
};