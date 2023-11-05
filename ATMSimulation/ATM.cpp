#include "ATM.h"

// Simulates inserting the card into the ATM
void ATM::insertCard(const Account& account, int pin)
{
	// If the pin is correct, set currentAccount to point to this account
	if (account.validatePIN(pin))
	{
		// Used const_cast to cast away const-ness (bad habit, but I'm a beginner and it's the only way I know how)
		currentAccount = const_cast<Account*>(&account);

		std::cout << "Card inserted successfully.\n";
	}
	else
	{
		std::cout << "Incorrect PIN.\n";
	}
}

// Simulates the card being ejected
void ATM::ejectCard()
{
	// Indicates no account being accessed
	currentAccount = nullptr;
	std::cout << "Card has been ejected.\n";

}

// Shows the balance
void ATM::showBalance()
{
	// If the account is selected show the balance
	if (currentAccount)
	{
		std::cout << "Current balance: $" << currentAccount->getBalance() << "\n";
	}
	else
	{
		std::cout << "No account selected.\n";
	}

}

// Deposit money using ATM
void ATM::deposit(double amount)
{
	// If account is selected deposit amount using ATM
	if (currentAccount)
	{
		currentAccount->deposit(amount);
		std::cout << "Deposited: $" << amount << "\n";
	}
	else
	{
		std::cout << "No account selected.\n";
	}
}

// Withdraws money using ATM
void ATM::withdraw(double amount)
{
	// If the withdrawal is successful display the amount withdrawn
	if (currentAccount)
	{
		if (currentAccount->withdraw(amount))
		{
			std::cout << "Withdrawn: $" << amount << "\n";
		}
		else
		{
			// If the funds are insufficient inform the user
			std::cout << "Insufficient funds.\n";
		}
	}
	else
	{
		std::cout << "No account selected.\n";
	}
}

