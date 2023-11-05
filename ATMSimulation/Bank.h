#pragma once
#include <vector>
#include <algorithm>
#include "Account.h"

class Bank
{
private:
	// Stores a list of accounts
	std::vector<Account> _accounts;

	// Static variable for account numbers
	static int _newAccountNumber;

public:
	// Constructor for the Bank class
	Bank();
	
	// Method to create an account
	Account* createAccount(const std::string& name, int pin, double initialDeposit);

	// Method to find an account by account number
	Account* findAccount(int accountNumber);

	void printAllAccounts() const;
};

