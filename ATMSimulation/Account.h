#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Account
{
private:
	int _accountNumber; // Indentifier for the account number
	std::string _accountHolderName; // Name of the account holder
	int _pin; // Pin number
	double _balance; // current balance of the account

public:
	// Constructor for the account class initializing an account with given parameters to the current account being accessed
	Account(int accNum, std::string name, int pinCode, double initialDeposit) : _accountNumber(accNum), _accountHolderName(name), _pin(pinCode), _balance(initialDeposit){}

	// Method to withdraw money from the account
	bool withdraw(double amount);

	// Method to deposit money into the account
	void deposit(double amount);

	// Getter method for the account holder's name
	std::string getAccountHolderName() const;

	// Getter method for account balance
	double getBalance() const;

	// Getter method for account number
	int getAccountNumber() const;

	//Method to validate the PIN entered by user
	bool validatePIN(int pinCode) const;
};

