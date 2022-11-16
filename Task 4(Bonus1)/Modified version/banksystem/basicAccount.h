#ifndef BASICACCOUNT_H_INCLUDED
#define BASICACCOUNT_H_INCLUDED
//#include"clientClass.h"
#include <iostream>

using namespace std;

class bankAccount
{
private:
    int accountID;
    float balance;

public:
    bankAccount();
    void setAccount();
    void setAccountID();
    virtual void setBalance(float = 0.0);

    int getAccountID() const;
    float getBalance() const;

    virtual void deposit(float);
    virtual void withdraw(float);

    void display() const;
};

#endif // BASICACCOUNT_H_INCLUDED
