#pragma once

#include <iostream>
#include <string>

using namespace std;

const int scoresCount = 5;

class STUDENT {
    string name;
    int group;
    int scores[scoresCount];

public:
    STUDENT();
    STUDENT(const STUDENT& student);
    STUDENT(string name, int group, int scores[]);

    string GetName();
    int GetGroup() ;
    const int* GetScores() const;
    double GetAverage();
    static void DisplayAllSortedByAverage(STUDENT arr[], int n);
    static void RemoveStudentByName(STUDENT arr[], int& n, const std::string& name);
    static void EditStudentByName(STUDENT arr[], int n, const std::string& name);

    void SetName(string name);
    void SetGroup(int group);
    void SetScores(const int* scores);


    STUDENT& operator=(const STUDENT& student);

    ~STUDENT();

    void DisplayInfo() const;

    friend std::ostream& operator<<(std::ostream& os, const STUDENT& student);
    friend std::istream& operator>>(std::istream& is, STUDENT& student);
};
