#ifndef SAVINGSACCOUNTCLASS_H_INCLUDED
#define SAVINGSACCOUNTCLASS_H_INCLUDED

#include "basicAccount.h"

using namespace std;
class savingsAccount : public bankAccount
{
private:
    double minimumBalance;

public:
    savingsAccount();
    savingsAccount(int, float);

    virtual void setBalance(float) override;
    virtual void withdraw(float) override;
    virtual void deposit(float) override;

    // virtual void display() const override;
};

#endif // SAVINGSACCOUNTCLASS_H_INCLUDED
