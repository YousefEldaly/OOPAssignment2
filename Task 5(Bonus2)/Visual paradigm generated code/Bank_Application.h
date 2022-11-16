#ifndef BANK_APPLICATION_H
#define BANK_APPLICATION_H

class Bank_Application {

private:
	int choice;
	client clients[];

public:
	Bank_Application();

	void displayMenu();

	void createAccount();

	void deposit();

	void withdraw();

	void listClients();
};

#endif
