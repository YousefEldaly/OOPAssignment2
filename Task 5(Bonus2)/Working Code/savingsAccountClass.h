#ifndef SAVINGSACCOUNTCLASS_H_INCLUDED
#define SAVINGSACCOUNTCLASS_H_INCLUDED

#include "basicAccount.h"

using namespace std;
class savingsAccount : public bankAccount{
private:
    double minimumBalance;

public:
    savingsAccount();
    savingsAccount(int accountID, float balance);
    void set_balance(float balance);
    void withdraw(float amount);
    void deposit(float amount);
    void display();
};


#endif // SAVINGSACCOUNTCLASS_H_INCLUDED
