#include "clientClass.h"

client::client()
{
    name = "";
    address = "";
    phone = "";
}

client::client(string &newName, string &newAddress, string &newPhone)
    : name(newName), address(newAddress), phone(newPhone) {}

void client::setAccount()
{
    cout << "Enter client name: ";
    string client_name;
    cin >> client_name;
    setName(client_name);

    cout << "Enter client address: ";
    string client_address;
    cin >> client_address;
    setAddress(client_address);

    cout << "Enter client phone: ";
    string client_phone;
    cin >> client_phone;
    setPhone(client_phone);

    cout << "What type of account do you want to create?" << endl;
    cout << "1. Savings Account" << endl;
    cout << "2. Basic Account" << endl;

    int account_type;
    cin >> account_type;
    if (account_type == 1)
    {
        pBankAccount = &savingAccount;
        pBankAccount->setAccount();
    }
    else if (account_type == 2)
    {
        pBankAccount = &basicAccount;
        pBankAccount->setAccount();
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}
void client::setName(string &newName)
{
    name = newName;
}

void client::setAddress(string &newAddress)
{
    address = newAddress;
}

void client::setPhone(string &newPhone)
{
    phone = newPhone;
}

string client::getName() const
{
    return name;
}

string client::getAddress() const
{
    return address;
}

string client::getPhone() const
{
    return phone;
}

int client::getAccountID() const
{
    return pBankAccount->getAccountID();
}

void client::deposit(float amount)
{
    pBankAccount->deposit(amount);
}

void client::withdraw(float amount)
{
    pBankAccount->withdraw(amount);
}


void client::displayAccount()const{
    cout << "Name: " << getName() << endl;
    cout << "Address: " << getAddress() << endl;
    cout << "Phone: " << getPhone() << endl;
    pBankAccount->display();
}

