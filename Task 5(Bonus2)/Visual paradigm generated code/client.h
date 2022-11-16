#ifndef CLIENT_H
#define CLIENT_H

class client {

private:
	string name;
	string address;
	string phone;
	savingAccount savingsAccount;
	bankAccount basicAccount;
	bankAccount* pBasicAccount;
	savingAccount* pSavingAccount;
	bool is_savings;

public:
	string get_name();

	void set_name(int name);

	string get_address();

	void set_address(int address);

	string get_phone();

	void set_phone(int phone);

	bool get_saving_flag();
};

#endif
