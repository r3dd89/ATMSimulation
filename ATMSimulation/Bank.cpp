#include "Bank.h"

int Bank::_newAccountNumber = 9999;

Bank::Bank()
{
}

// Creates a new account and adds the new account to the vector
Account* Bank::createAccount(const std::string& name, int pin, double initialDeposit)
{
	// Ensures the initial deposit meets the minimum requirement of $25
	if (initialDeposit < 25)
	{
		throw std::invalid_argument("Initial deposit must be at least $25");
	}

	_accounts.emplace_back(_newAccountNumber, name, pin, initialDeposit);

	// Returns a pointer to the new account
	return &_accounts.back();
}


// Finds the account by account number
Account* Bank::findAccount(int accountNumber)
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

// Utility function to print all accounts, I'm using this for debugging purposes
void Bank::printAllAccounts() const
{
	for (const auto& account : _accounts)
	{
		std::cout << "Account Number: " << account.getAccountNumber() << "," << "Account Holder: " << account.getAccountHolderName() << "," << "Balance: " << account.getBalance() << std::endl;
	}
}


