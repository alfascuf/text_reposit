#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// ������� ��� ���������� ������ �� �����������
void printSentencesWithWord(const std::string& text, const std::string& wordToFind) {
    std::istringstream iss(text);
    std::string sentence;

    while (std::getline(iss, sentence, '.')) {
        // ��������� ������� ����������� �� ������� ��������� �����
        if (sentence.find(wordToFind) != std::string::npos) {
            std::cout << sentence << '.' << std::endl;
        }
    }
}

int partTwo() {
    std::string wordToFind;

    std::cout << "Enter the aim word: ";
    std::cin >> wordToFind;

    std::ifstream file("file.txt");

    if (!file.is_open()) {
        std::cout << "Error open file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string fileContent = buffer.str();
    file.close();

    printSentencesWithWord(fileContent, wordToFind);

    return 0;
}