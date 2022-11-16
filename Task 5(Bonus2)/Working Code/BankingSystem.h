//
// Created by Youssef on 11/10/2022.
//

#ifndef BANKING_SYSTEM_BANKINGSYSTEM_H
#define BANKING_SYSTEM_BANKINGSYSTEM_H
#include "clientClass.h"
#include <iostream>
#include <vector>

using namespace std;


class Bank_Application
{
private:
    int choice;
    vector<client> clients;

public:
    Bank_Application();
    void displayMenu();
    void createAccount();
    void deposit();
    void withdraw();
    void listClients();
};

#endif // BANKING_SYSTEM_BANKINGSYSTEM_H
