#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Account.h"

class ATM
{
private:
	Account* currentAccount; // Pointer to the current account being accessed

public:
	// Constructor initializing the ATM with no account selected
	ATM() : currentAccount(nullptr){}
	
	// Method that simulates card being inserted into the ATM
	void insertCard(const Account& account, int pin);

	// Method that simulates card being ejected out of the ATM
	void ejectCard();

	// Method that displays the user's balance
	void showBalance();

	// Method to deposit money into the ATM
	void deposit(double amount);

	// Method to withdraw money using the ATM
	void withdraw(double amount);
};

