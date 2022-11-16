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
    void set_accountID(int);
    void set_balance(float balance);

    int get_accountID();
    float get_balance();

    void deposit(float amount);
    void withdraw(float amount);

    void display();
};


#endif // BASICACCOUNT_H_INCLUDED
