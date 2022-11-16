//
// Created by Youssef on 11/10/2022.
//
#include "BankingSystem.h"
#include <iostream>
using namespace std;

void Bank_Application::displayMenu()
{
    cout << "**************************************************" << endl;
    cout << "1. Create a new account" << endl;
    cout << "2. list Clients and accounts" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    while (choice != 5)
    {
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
        displayMenu();
    }
}

void Bank_Application::createAccount()
{
    client newClient;
    cout << "Enter client name: ";
    string client_name;
    cin >> client_name;
    newClient.set_name(client_name);

    cout << "Enter client address: ";
    string client_address;
    cin >> client_address;
    newClient.set_address(client_address);

    cout << "Enter client phone: ";
    string client_phone;
    cin >> client_phone;
    newClient.set_phone(client_phone);

    cout << "What type of account do you want to create?" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Basic Account" << endl;
    int accountType;
    cin >> accountType;
    if (accountType == 1)
    {
        newClient.is_savings_flag();
        cout << "Enter starting balance: ";
        float balance;
        cin >> balance;
        newClient.set_balance(balance);
        newClient.set_accountID();
        cout << "**************************************************\n";
        cout << "An account has been created with the following details: " << endl;
        newClient.displayAccount();
        clients.push_back(newClient);
    }
    else if (accountType == 2)
    {

        cout << "Enter starting balance: ";
        float balance;
        cin >> balance;
        newClient.set_balance(balance);
        newClient.set_accountID();
        cout << "**************************************************\n";
        cout << "An account has been created with the following details: " << endl;
        newClient.displayAccount();
        clients.push_back(newClient);
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}

void Bank_Application::listClients()
{
    for (int i = 0; i < clients.size(); i++)
    {
        cout << "*********************";
        cout << "Client " << i + 1;
        cout << "*********************" << endl << endl;
        clients[i].display();
        cout << "Accounts: " << endl;
        clients[i].displayAccount();
        cout << endl;
    }
}

void Bank_Application::deposit()
{
    cout << "Enter account ID: ";
    int accountID;
    cin >> accountID;
    cout << "Enter amount: ";
    float amount;
    cin >> amount;

    for (int i = 0; i < clients.size(); i++)
    {
        if (clients[i].get_accountID() == accountID)
        {
            clients[i].deposit(amount);
        }
    }
}

void Bank_Application::withdraw()
{
    cout << "Enter account ID: ";
    int accountID;
    cin >> accountID;
    cout << "Enter amount: ";
    float amount;
    cin >> amount;
    for (int i = 0; i < clients.size(); i++)
    {
        if (clients[i].get_accountID() == accountID)
        {
            clients[i].withdraw(amount);
        }
    }
}
