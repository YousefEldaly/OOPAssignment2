#include "basicAccount.h"
#include "savingsAccountClass.h"
#include <iostream>
using namespace std;

bankAccount::bankAccount() : accountID(0), balance(0.0)
{
}

void bankAccount::setAccount()
{
    cout << "Enter starting balance: ";
    float new_balance;
    cin >> new_balance;
    setBalance(new_balance);
    setAccountID();
}

void bankAccount::setAccountID()
{
    static long int newID = 2021000;
    accountID = newID++;
}

void bankAccount::setBalance(float new_balance)
{
    balance = new_balance;
}
int bankAccount::getAccountID() const
{
    return accountID;
}

float bankAccount::getBalance() const
{
    return balance;
}

void bankAccount::deposit(float amount)
{
    balance += amount;
}

void bankAccount::withdraw(float amount)
{
    balance -= amount;
}

void bankAccount::display() const
{
    cout << "Account ID: " << to_string(getAccountID()) << endl;
    cout << "Balance: " << getBalance() << endl;
}
