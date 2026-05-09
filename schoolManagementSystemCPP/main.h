#ifndef MAIN_H
#define MAIN_H

#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "authenticationSystem.h"
#include "studentManagement.h"

class interface
{
private:
    std::string allManagement[8] = {"Student Management", "Teacher Management", "Subject Management", "Grade Management",
                                   "Attendance", "Report", "Login System", "Exit"};
    std::vector<std::string> activeAccount;
public:
    authenticationSystem authenticate;
    studentManagement studentManage;

    void headerTitle(void);
    void loginAccount(void);
    void roleOptions(std::vector <std::string> role);
};

void interface::headerTitle(void) {
    std::string header = "Pitipiwpiw National Highschool";
    int totalWidth = 40;
    int leftPad = (totalWidth - (int)header.size()) / 2;
    int rightPad = totalWidth - (int)header.size() - leftPad;

    std::cout << std::string(leftPad, '-') << header << std::string(rightPad, '-') << std::endl;
}

void interface::loginAccount(void) {
    authenticate.userlogin();

    if (authenticate.getLoggedAccount().empty()) {  
        std::cerr << "Login failed" << std::endl;
        return;
    }
    activeAccount = authenticate.getLoggedAccount()[0];
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::system("cls");
    roleOptions(activeAccount);
}

void interface::roleOptions(std::vector <std::string> role) {
    std::cout << "Hello! " << role[0] << std::endl << std::endl;

    if (role[1] == "ADMIN") {
        studentManage.getStudentData();
    } 
    
    else if (role[1] == "TEACHER") {
        std::cout << "Teacher Menu" << std::endl;
    }

    else if (role[1] == "STAFF") {
        std::cout << "Staff Menu" << std::endl;
    }

    else {
        std::cout << "Student Menu" << std::endl;
    }
    
}

#endif