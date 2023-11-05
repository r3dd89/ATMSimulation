#include <iostream>
#include "Account.h"
#include "ATM.h"
#include "Bank.h"
#include <string>


int main()
{
	// Creates instances of the Bank and ATM classes
	Bank myBank;
	ATM myATM;

	int accountNumber;
	int pin;
	int select;
	double amount;

	// Displays the welcome message
	std::cout << "=============================\n" << std::endl;
	std::cout << "Welcome to the Bank of Nerds\n" << std::endl;
	std::cout << "=============================\n\n" << std::endl;

	bool appRunning = true;

	// Main application loop
	while (appRunning)
	{
		std::cout << "Select an option:\n";
		std::cout << "1. Create Account\n";
		std::cout << "2. Use ATM\n";
		std::cout << "3. Exit\n";
		std::cin >> select;

		switch (select)
		{
		case 1:
		{
			// Gather information for new account creation
			std::string name;
			double initialDeposit;

			std::cout << "Enter your full name: ";
			std::cin.ignore(); // ignores newline character from previous input
			std::getline(std::cin, name);

			std::cout << "Enter a PIN number: ";
			std::cin >> pin;

			std::cout << "Enter an initial deposit (minimum $25): ";
			std::cin >> initialDeposit;

			try
			{
				Account* newAccount = myBank.createAccount(name, pin, initialDeposit);
				std::cout << "Account created successfully. You account number is: " << newAccount->getAccountNumber() << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << "Error creating account: " << e.what() << std::endl;
			}
			break;
		}

		case 2:
		{
			// Keeps track of when the user wants to finish using the ATM
			bool userFinished = false;

			// Main application loop
			while (!userFinished)
			{
				// Asks the user to "Insert card" a.k.a account number
				std::cout << "Please insert card (enter account number): ";
				std::cin >> accountNumber;

				// Ask user of input
				std::cout << "Enter PIN: ";
				std::cin >> pin;


				// Attempts to find the account in the bank and verifies the PIN #
				Account* userAccount = myBank.findAccount(accountNumber);
				if (userAccount != nullptr && userAccount->validatePIN(pin))
				{
					// If the account is found and PIN is correct, proceed with ATM operations.
					myATM.insertCard(*userAccount, pin);
					bool sessionActive = true;

					// Session loop for ATM operations
					while (sessionActive)
					{
						// Display menu options for user
						std::cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\nSelect an option: ";
						std::cin >> select;
						// Handle user's menu selection
						switch (select)
						{
						case 1:
							// Show's the user's balance
							myATM.showBalance();
							break;

						case 2:
							// Handles deposit operation
							std::cout << "Enter amount to deposit: ";
							std::cin >> amount;
							myATM.deposit(amount);
							break;

						case 3:
							// Handles withdraw operation
							std::cout << "Enter withdrawal amount: ";
							std::cin >> amount;
							myATM.withdraw(amount);
							break;

						case 4:
							// Exit the session and eject the card
							sessionActive = false;
							myATM.ejectCard();
							break;

						default:
							// Handles invalid entry
							std::cout << "Invalid option." << std::endl;
							break;
						}
					}
				}
				else
				{
					// Informs the user the account number or the PIN number is incorrect
					std::cout << "Invalid account number or PIN number." << std::endl;
				}

				// Ask user if they want to perform another transaction
				std::cout << " Would you like to perform another transaction? (y/n): ";
				char continueTransaction;
				std::cin >> continueTransaction;

				// If user types n or N finish the loop
				userFinished = (continueTransaction == 'n' || continueTransaction == 'N');
			}
			break;
		}
		case 3:
		{
			// Display good by message
			std::cout << "Thank you for banking with Bank of Nerds. Goodbye!" << std::endl;
			appRunning = false;
			break;
		}

		default:
			std::cout << "Invalid option selected. Please try again.\n";
			break;
		}
	}
	return 0;
}