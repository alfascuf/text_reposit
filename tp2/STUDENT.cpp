#include "STUDENT.h"

using namespace std;

STUDENT::STUDENT() {
    cout << "STUDENT: пустой конструктор" << endl;
    name = "tmp";
    group = 1;

    for (int i = 0; i < scoresCount; i++)
        scores[i] = 5;
}

STUDENT::STUDENT(const STUDENT& student) {
    cout << "STUDENT: конструктор копирования" << endl;
    name = student.name;
    group = student.group;

    for (int i = 0; i < scoresCount; i++)
        scores[i] = student.scores[i];
}

STUDENT::STUDENT(string name, int group, int scores[]) {
    cout << "STUDENT: конструктор с параметрами" << endl;
    this->name = name;
    this->group = group;

    for (int i = 0; i < scoresCount; i++)
        this->scores[i] = scores[i];
}

string STUDENT::GetName() {
    return name;
}

int STUDENT::GetGroup() {
    return group;
}

const int* STUDENT::GetScores() const {
    return scores;
}


double STUDENT::GetAverage() {
    double average = 0;

    for (int i = 0; i < scoresCount; i++)
        average += scores[i];

    return average / 5.0;
}

void STUDENT::SetName(string name) {
    this->name = name;
}

void STUDENT::SetGroup(int group) {
    this->group = group;
}

void STUDENT::SetScores(const int* scores) {
    for (int i = 0; i < scoresCount; i++)
        this->scores[i] = scores[i];
}



STUDENT& STUDENT::operator=(const STUDENT& student) {
    if (this == &student)
        return *this;

    name = student.name;
    group = student.group;

    for (int i = 0; i < scoresCount; i++)
        scores[i] = student.scores[i];

    return *this;
}

STUDENT::~STUDENT() {
    cout << "STUDENT: деструктор" << endl;
}

ostream& operator<<(ostream& os, const STUDENT& student) {
    os << "Имя: " << student.name << endl;
    os << "Группа: " << student.group << endl;
    os << "Оценки: ";

    for (int i = 0; i < scoresCount; i++)
        os << student.scores[i] << " ";

    os << endl;

    return os;
}

istream& operator>>(istream& is, STUDENT& student) {
    cout << "Введите имя: ";
    cin.ignore();
    getline(is, student.name);

    cout << "Введите номер группы: ";
    is >> student.group;

    if (student.group < 1)
        throw string("Номер группы должен быть положительным");

    cout << "Введите оценки: ";
    bool crash = false;

    for (int i = 0; i < scoresCount; i++) {
        is >> student.scores[i];

        if (student.scores[i] < 1 || student.scores[i] > 5)
            crash = true;
    }

    if (crash)
        throw string("Оценка должна быть от 1 до 5");

    return is;
}


void STUDENT::DisplayInfo() const {
    cout << "Имя: " << name << endl;
    cout << "Группа: " << group << endl;
    cout << "Оценки: ";

    for (int i = 0; i < scoresCount; i++)
        cout << scores[i] << " ";

    cout << endl;
}


void STUDENT::DisplayAllSortedByAverage(STUDENT arr[], int n) {
    // Сортировка студентов по средней оценке
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].GetAverage() > arr[j + 1].GetAverage()) {
                // Обмен
                STUDENT temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Вывод информации
    std::cout << std::endl << "Студенты отсортированные по средней оценке:" << std::endl << std::endl;

    for (int i = 0; i < n; i++) {
        arr[i].DisplayInfo();
        std::cout << "Средний балл: " << arr[i].GetAverage() << std::endl << std::endl;
    }
}


void STUDENT::RemoveStudentByName(STUDENT arr[], int& n, const std::string& name) {
    // Поиск студента по имени
    for (int i = 0; i < n; ++i) {
        if (arr[i].GetName() == name) {
            // Перемещение всех студентов справа от удаляемого на одну позицию влево
            for (int j = i; j < n - 1; ++j) {
                arr[j] = arr[j + 1];
            }
            // Уменьшение количества студентов
            --n;
            std::cout << "Студент " << name << " удален." << std::endl;
            return;
        }
    }

    std::cout << "Студент " << name << " не найден." << std::endl;
}

void STUDENT::EditStudentByName(STUDENT arr[], int n, const std::string& name) {
    // Поиск студента по имени
    for (int i = 0; i < n; ++i) {
        if (arr[i].GetName() == name) {
            // Редактирование данных студента
            std::cin >> arr[i];
            std::cout << "Студент " << name << " отредактирован." << std::endl;
            return;
        }
    }

    std::cout << "Студент " << name << " не найден." << std::endl;
}