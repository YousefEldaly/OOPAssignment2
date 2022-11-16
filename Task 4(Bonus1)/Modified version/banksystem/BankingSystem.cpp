//
// Created by Youssef on 11/10/2022.
//
#include "BankingSystem.h"
#include <iostream>
using namespace std;

bankApplication::bankApplication(){
    clients.reserve(clients.size() + 1000);
}

void bankApplication::displayMenu()
{
    while(choice != 5){
        cout << "**************************************************" << endl;
        cout << "1. Create a new account" << endl;
        cout << "2. list Clients and accounts" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            listClients();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

void bankApplication::createAccount()
{
    static bool first = true;
    if(first){
        client trashObject;
        clients.push_back(trashObject);
        first = false;
    }
    client newClient;
    clients.push_back(newClient);
    static int i = 1;
    clients[i].setAccount();
    cout << "**************************************************\n";
    cout << "An account has been created with the following details: \n\n";
    clients[i++].displayAccount();
}

void bankApplication::listClients()
{
    for (int i = 1; i < (int)clients.size(); i++)
    {
        cout << "*********************";
        cout << "Client " << i;
        cout << "*********************\n\n";
        clients[i].displayAccount();
    }
}

void bankApplication::deposit()
{
    cout << "Enter account ID: ";
    int accountID;
    cin >> accountID;

    cout << "Enter amount: ";
    float amount;
    cin >> amount;

    for (int i = 1; i < (int)clients.size(); i++)
    {
        if (clients[i].getAccountID() == accountID)
        {
            clients[i].deposit(amount);
            return;
        }
    }
    cout << "No Matching ID\n";
}

void bankApplication::withdraw()
{
    cout << "Enter account ID: ";
    int accountID;
    cin >> accountID;

    cout << "Enter amount: ";
    float amount;
    cin >> amount;

    for (int i = 1; i < (int)clients.size(); i++)
    {
        if (clients[i].getAccountID() == accountID)
        {
            clients[i].withdraw(amount);
            return;
        }
    }
    cout << "No matching ID\n";
}
