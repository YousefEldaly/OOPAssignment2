#include "basicAccount.h"
#include "savingsAccountClass.h"
#include <iostream>
using namespace std;

bankAccount::bankAccount() : accountID(0), balance(0.0)
{
}

void bankAccount::set_accountID(int newID)
{
    accountID = newID;
}

void bankAccount::set_balance(float balance)
{
    this->balance = balance;
}
int bankAccount::get_accountID()
{
    return accountID;
}
float bankAccount::get_balance()
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

void bankAccount::display()
{
    cout << "Account ID: " << get_accountID() << endl;
    cout << "Balance: " << get_balance() << endl;
}


