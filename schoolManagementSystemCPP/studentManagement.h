#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct studentInfo
{
    std::string studentID;
    std::string studentName;
    int age;
    std::string gender;
    int gradeLevel;
    std::string section;
    std::string phoneNumber;
    std::string studentStatus;
};

class studentManagement
{
private:
    std::vector<studentInfo> studentRawData;
public:
    void getStudentData(void);
    std::string trim(std::string text);
};

void studentManagement::getStudentData(void) {
    this->studentRawData.clear();
    std::ifstream studentAccount("data/students.csv");
    if (!studentAccount.is_open()) {
        std::cerr << "File not found" << std::endl;
        return;
    }

    std::string line;
    std::getline(studentAccount, line);
    while (std::getline(studentAccount, line)){
        std::stringstream sStream(line);
        studentInfo student;

        std::getline(sStream, student.studentID, ',');
        std::getline(sStream, student.studentName, ',');

        std::string ageTemp;                          
        std::getline(sStream, ageTemp, ',');
        student.age = std::stoi(ageTemp);            
        std::getline(sStream, student.gender, ',');

        std::string gradeLevelTemp;                  
        std::getline(sStream, gradeLevelTemp, ',');
        student.gradeLevel = std::stoi(gradeLevelTemp);

        std::getline(sStream, student.section, ',');
        std::getline(sStream, student.phoneNumber, ',');
        std::getline(sStream, student.studentStatus, ',');

        student.studentID     = trim(student.studentID);
        student.studentName   = trim(student.studentName);
        student.gender        = trim(student.gender);
        student.section       = trim(student.section);
        student.phoneNumber   = trim(student.phoneNumber);
        student.studentStatus = trim(student.studentStatus);

        this->studentRawData.push_back(student);
    }
    studentAccount.close();

    for (const auto& data : this->studentRawData) {
    std::cout << data.studentID     << " | "
              << data.studentName   << " | "
              << data.age           << " | "
              << data.gender        << " | "
              << data.gradeLevel    << " | "
              << data.section       << " | "
              << data.phoneNumber   << " | "
              << data.studentStatus << std::endl;
    }
    
    return;
}

std::string studentManagement::trim(std::string text) {
    std::string result = "";
    bool started = false;
    int lastChar = 0;

    for (int i = text.size() - 1; i >= 0; i--) {
        if (text[i] != ' ') {
            lastChar = i;
            break;
        }
    }

    for (int i = 0; i <= lastChar; i++) {
        if (text[i] != ' ' || started) {
            result += text[i];
            started = true;
        }
    }
    return result;
}

#endif