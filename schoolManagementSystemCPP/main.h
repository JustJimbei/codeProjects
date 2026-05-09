#ifndef MAIN_H
#define MAIN_H

#include <iomanip>
#include "authenticationSystem.h"

class interface
{
private:
    std::string allManagement[8] = {"Student Management", "Teacher Management", "Subject Management", "Grade Management",
                                   "Attendance", "Report", "Login System", "Exit"};
    std::vector<std::string> activeAccount;
public:
    authenticationSystem authenticate;

    void headerTitle(void);
    void loginAccount (void);
    void optionPrint(void);
    //void chooseInput(void);
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
    activeAccount = authenticate.getLoggedAccount()[0];

    if (activeAccount[1] == "ADMIN") {
        std::cout << "hello admin"; 
        return;
    }

    else if (activeAccount[1] == "TEACHER") {
        std::cout << "hello teacher";
        return;
    }
    else if (activeAccount[1] == "STAFF") {
       std::cout << "hello staff";
       return;
    }

    else {
        std::cout << "hello student";
        return;
    } 
}

void interface::optionPrint(void) {
    for (std::string i:this->allManagement)
    {
        static int count = 1;
        std::cout << count++ << ". " << i << std::endl;
    }
}

/* void interface::chooseInput(void) {
    try {
        int choice;
        std::cout << "Enter: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: break;
        case 8: break;
        default:
            throw std::out_of_range("Invalid input!");
        }
         
    } catch (std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Invalid input!" << std::endl;
    }
}*/

#endif