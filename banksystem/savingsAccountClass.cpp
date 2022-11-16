#include "savingsAccountClass.h"
#include <iostream>

savingsAccount::savingsAccount()
    : minimumBalance(1000)
{
    bankAccount::setBalance(minimumBalance);
}

void savingsAccount::setBalance(float new_balance)
{
    if (new_balance >= minimumBalance)
    {
        bankAccount::setBalance(new_balance);
    }
    while (new_balance < minimumBalance)
    {
        cout << "Balance must be greater than " << minimumBalance << endl;
        cin >> new_balance;
        bankAccount::setBalance(new_balance);
    }
}

void savingsAccount::withdraw(float amount)
{
    if (getBalance() - amount < minimumBalance)
    {
        cout << "Cannot withdraw more than minimum balance" << endl;
    }
    else
    {
        bankAccount::setBalance(getBalance() - amount);
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
