// BankSystem.h
#pragma once

#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"

using std::cout;

class BankAccount {
public:
    std::string accountHolder;
    int accountNumber;
    double balance;
    std::vector<Transaction> transactions;

    BankAccount(int accNumber, const std::string& accHolder, double initialBalance):
    	accountNumber(accNumber), accountHolder(accHolder), balance(balance) {}
    	
    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << std::endl;
        cout << "Account Holder: " << accountHolder << std::endl;
        cout << "Balance: $" << balance << std::endl;
	}

    void displayTransaction(const Transaction& transaction) const;
};

class BankManager {
private:
    std::vector<BankAccount> accounts;

public:
    BankManager();
    void start();
    void createAccount();
    void viewAccounts() const;
    void makeDeposit();
    void makeWithdrawal();
    std::vector<BankAccount>::iterator findAccount(int accNumber);
    void loadAccounts();
    void saveAccounts() const;
};

