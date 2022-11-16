#include "savingsAccountClass.h"
#include <iostream>

savingsAccount::savingsAccount() : bankAccount()
{
    minimumBalance = 1000;
    bankAccount::set_balance(minimumBalance);
}

void savingsAccount::set_balance(float balance)
{
    if (balance >= minimumBalance)
    {
        bankAccount::set_balance(balance);
    }
    while (balance < minimumBalance)
    {
        cout << "Balance must be greater than " << minimumBalance << endl;
        cin >> balance;
        bankAccount::set_balance(balance);
    }
}


void savingsAccount::withdraw(float amount)
{
    if (bankAccount::get_balance() - amount < minimumBalance)
    {
        cout << "Cannot withdraw more than minimum balance" << endl;
    }
    else
    {
        bankAccount::set_balance(get_balance() - amount);
    }
}

void savingsAccount::deposit(float amount)
{
    if (amount >= 100)
    {
        bankAccount::deposit(amount);
    }
    else
    {
        cout << "Cannot deposit less than 100" << endl;
    }
}

void savingsAccount::display()
{
    cout << "Account ID: " << get_accountID() << endl;
    cout << "Balance: " << get_balance() << endl;
}
