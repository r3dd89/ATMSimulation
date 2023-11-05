#include "Account.h"


// Withdraw money from the account
bool Account::withdraw(double amount)
{
    // If there are insufficient funds return false
    if (amount > _balance)
    {
        return false;
    }
    // Deducts the amount from the balance and returns true
    _balance -= amount;
    return true;
}

// Deposits money into the account
void Account::deposit(double amount)
{
    // Adds amount to balance
    _balance += amount;
}

std::string Account::getAccountHolderName() const
{
    return _accountHolderName;
}

// Gets the account balance
double Account::getBalance() const
{
    return _balance;
}

// Gets the account number
int Account::getAccountNumber() const
{
    return _accountNumber;
}

// Validates the PIN entered by the user
bool Account::validatePIN(int pinCode) const
{
    return _pin == pinCode;
}
