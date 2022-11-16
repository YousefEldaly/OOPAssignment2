#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class bankAccount {

private:
	int accountID;
	float balance;

public:
	int get_accountID();

	void set_accountID(int accountID);

	float get_balance();

	void set_balance(float balance);

	void deposit(int float_amount);

	void withdraw(int float_amount);

	void display();
};

#endif
