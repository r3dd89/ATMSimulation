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
		if (initialDeposit < 25)
		{
			throw std::invalid_argument("Initial deposit must be at least $25");
		}

		int accountNumber = _accountNumber++;
		Account newAccount(accountNumber, name, pin, initialDeposit);
		_accounts.push_back(newAccount);
		return newAccount;
	}

	// Finds an account by the account number
	Account* findAccount(int accountNumber)
	{
		auto it = std::find_if(_accounts.begin(), _accounts.end(), [accountNumber](const Account& account)
			{
				return account.getAccountNumber() == accountNumber;
			});
		if (it != _accounts.end())
		{
			return &(*it);
		}
		else
		{
			return nullptr;
		}
	}

};

