#pragma once
#include "student.h"

class Archive {
	friend ostream& operator << (ostream& os, const Archive& dt);
public:
	Archive();
	Archive(int count);
	Archive(Archive* orig);
	~Archive();

	void sortByAverageGrade();
	void showSortedList();
	void showWith4and5();

	Student** getList();
	void setList(Student** orig);
	int getSize();
	void setSize(int s);
	int getLimit();
	void setLimit(int l);
	void checkLimit();

	Archive& operator ++ ();      // �������� �������� � �����
	Archive& operator -- ();      // ������ ���������� ����������� �������� �� ������
	Archive& operator -= (int a); // ������ �������� ��� �������� �������
private:
	Student** list;
	int size;
	int limit;
};
