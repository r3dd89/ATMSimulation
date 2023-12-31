#include "Bank.h"
#include <random>

int Bank::_newAccountNumber;

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
	

	// Generates random account number
	std::random_device rd; // Used to obtain a seed for the random number
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1000, 9999); // Generates a number in this range
	int accountNumber = dis(gen);

	// Check if the account number already exist
	auto checkNumberExist = std::find_if(_accounts.begin(), _accounts.end(), [accountNumber] (const Account & acc)
	{
		return acc.getAccountNumber() == accountNumber;
	});

	// If the account number already exists, generate a new number
	while (checkNumberExist != _accounts.end())
	{
		accountNumber = dis(gen);
		auto checkNumberExist = std::find_if(_accounts.begin(), _accounts.end(), [accountNumber](const Account& acc)
			{
				return acc.getAccountNumber() == accountNumber;
			});
	}
_accounts.emplace_back(accountNumber, name, pin, initialDeposit);

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


