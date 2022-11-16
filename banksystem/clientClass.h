#ifndef CLIENTCLASS_H_INCLUDED
#define CLIENTCLASS_H_INCLUDED

#include "basicAccount.h"
#include "savingsAccountClass.h"
#include <iostream>
using namespace std;

class client
{
private:
    string name;
    string address;
    string phone;
    savingsAccount savingAccount;
    bankAccount basicAccount;

    bankAccount *pBankAccount;

public:
    client();
    client(string &, string &, string &);

    void setAccount();
    void setName(string &);
    void setAddress(string &);
    void setPhone(string &);

    string getName() const;
    string getAddress() const;
    string getPhone() const;
    int getAccountID() const;

    void deposit(float amount);
    void withdraw(float amount);

    void displayAccount() const;
    void displayClient() const;

    void is_savings_flag();
};

#endif // CLIENTCLASS_H_INCLUDED
