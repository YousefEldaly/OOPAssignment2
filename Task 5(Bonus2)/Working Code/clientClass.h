#ifndef CLIENTCLASS_H_INCLUDED
#define CLIENTCLASS_H_INCLUDED

#include "basicAccount.h"
#include "savingsAccountClass.h"
#include <iostream>
using namespace std;

class client
{
private:
    bool is_saving;
    string name;
    string address;
    string phone;
    savingsAccount savingAccount;
    bankAccount basicAccount;
    bankAccount* pBasicAccount = &basicAccount;
    savingsAccount* pSavingAccount= &savingAccount;


public:

    client();
    client(string name, string address, string phone);

    void set_name(string name);
    void set_address(string address);
    void set_phone(string phone);
    void set_balance(float balance);
    void set_accountID();

    string get_name();
    string get_address();
    string get_phone();
    int get_accountID();
    bool get_saving_flag();

    void deposit(float amount);
    void withdraw(float amount);

    void displayAccount();
    void display();

    void is_savings_flag();
};


#endif // CLIENTCLASS_H_INCLUDED
