#ifndef AUTHENTICATIONSYSTEM_H
#define AUTHENTICATIONSYSTEM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct User {
    std::string username;
    std::string password;
    std::string role;
};

class authenticationSystem
{
private:
    std::vector<User> accounts;
    std::vector<std::vector<std::string>> loggedInAccount;

public:
    void userlogin(void);
    void getAccounts(void);
    std::vector<std::string> evaluate(std::string userName, std::string password);

    std::vector<std::vector<std::string>>& getLoggedAccount() { return loggedInAccount; }
};

inline void authenticationSystem::userlogin(void)
{
    std::string user, pass;
    std::cout << "User Name: ";
    std::cin >> user;
    std::cout <<"Password: ";
    std::cin >> pass;

    std::vector<std::string> activeAccount = evaluate(user, pass);
    if (activeAccount.empty()){
        std::cerr << "Account not found" << std::endl;
        return;
    } else {
        std::cout << "Succesfully Login" << std::endl;
    }
    this->loggedInAccount.push_back(activeAccount);
}

inline void authenticationSystem::getAccounts(void)
{
    std::ifstream accounts("data/accounts.csv");
    if (!accounts.is_open()) {
        std::cerr << "error" << std::endl;
        return;
    }
    
    std::string line;
    std::getline(accounts, line);
    while(getline(accounts, line)) {
       std::stringstream sStream(line);
       User accs;

       std::getline(sStream, accs.username, ',');
       std::getline(sStream, accs.password, ',');
       std::getline(sStream, accs.role, ',');

       this->accounts.push_back(accs);
    }
    accounts.close();
    return;
}

inline std::vector<std::string> authenticationSystem::evaluate(std::string userName, std::string password) {
    getAccounts();
    std::vector<std::string> resultAcc;
    for(const auto& accs : this->accounts) {
        if(userName == accs.username && password == accs.password) {
            resultAcc.push_back(accs.username);
            resultAcc.push_back(accs.role);
        }
    }
    return resultAcc;
}

#endif