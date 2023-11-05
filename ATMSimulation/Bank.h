#pragma once
#include <vector>
#include <algorithm>
#include "Account.h"

class Bank
{
private:
	// Stores a list of accounts
	std::vector<Account> _accounts;

	// Generates a unique account number for each new account
	int _accountNumber;

public:
	// Start account numbering at 9999
	Bank() : _accountNumber(9999){}

	// Creates a new account and adds it to the accounts vector
	Account createAccount(const std::string& name, int pin, double initialDeposit)
	{
		// Ensures the initial deposit meets the minimum requirements

	}

};

