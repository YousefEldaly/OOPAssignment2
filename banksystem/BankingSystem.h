//
// Created by Youssef on 11/10/2022.
//

#ifndef BANKING_SYSTEM_BANKINGSYSTEM_H
#define BANKING_SYSTEM_BANKINGSYSTEM_H
#include "clientClass.h"
#include <iostream>
#include <vector>

using namespace std;

class bankApplication
{
private:
    int choice;
    vector<client> clients;

public:
    bankApplication();
    void displayMenu();
    void createAccount();
    void listClients();
    void deposit();
    void withdraw();
};

#endif // BANKING_SYSTEM_BANKINGSYSTEM_H
