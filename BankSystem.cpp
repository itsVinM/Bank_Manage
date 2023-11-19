// BankSystem.cpp
#include "BankSystem.h"


#include <iostream>
#include <algorithm>



using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;

const std::string ACCOUNTS_FILE = "accounts.txt";

BankManager::BankManager(){
	loadAccounts();
}

void BankManager::start() {
        while (true) {
            cout << "\n\n";
            cout << "\n\t 1. Create Account" << endl;
            cout << "\n\t 2. View Accounts" << endl;
            cout << "\n\t 3. Make Deposit" << endl;
            cout << "\n\t 4. Make Withdrawal" << endl;
            cout << "\n\t 5. Exit" << endl;

            int choice;
            cout << "\n Select option: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    createAccount();
                    break;
                case 2:
                    viewAccounts();
                    break;
                case 3:
                    makeDeposit();
                    break;
                case 4:
                    makeWithdrawal();
                    break;
                case 5:
                    saveAccounts();
                    cout << "Exiting Bank Management System.\n";
                    return;
            }
        }
}



void BankManager::createAccount() {
        int accNumber;
        string accHolder;
        double initialBalance;

        cout << "\n Enter Account Number: ";
        cin >> accNumber;

        cout << "\n Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, accHolder);

        cout << "\n Enter Initial Balance: $";
        cin >> initialBalance;

        BankAccount newAccount(accNumber, accHolder, initialBalance);
        accounts.push_back(newAccount);

        cout << "\n Account created successfully.\n";
}

void BankManager::viewAccounts() const {
        cout << "\n\t Bank Accounts \t\n";

        for (const auto& account : accounts) {
            account.displayAccountInfo();
            cout << "-------------------------\n";
        }
}

void BankManager::makeDeposit() {
        int accNumber;
        double amount;

        cout << "\n Enter Account Number: ";
        cin >> accNumber;

        auto it = findAccount(accNumber);

        if (it != accounts.end()) {
            cout << "\n Enter Deposit Amount: $";
            cin >> amount;
            it->balance += amount;
            cout << "\n Deposit successful.\n";
        } else {
            cout << "\n Account not found.\n";
        }
}

void BankManager::makeWithdrawal() {
        int accNumber;
        double amount;

        cout << "\n Enter Account Number: ";
        cin >> accNumber;

        auto it = findAccount(accNumber);

        if (it != accounts.end()) {
            cout << "\n Enter Withdrawal Amount: $";
            cin >> amount;

            if (amount <= it->balance) {
                it->balance -= amount;
                cout << "\n Withdrawal successful.\n";
            } else {
                cout << "\n Insufficient funds.\n";
            }
        } else {
            cout << "\n Account not found.\n";
        }
}

std::vector<BankAccount>::iterator BankManager::findAccount(int accNumber) {
        return find_if(accounts.begin(), accounts.end(), [accNumber](const BankAccount& acc) {
            return acc.accountNumber == accNumber;
        });
}

void BankManager::loadAccounts() {
        std::ifstream file(ACCOUNTS_FILE);
        if (file.is_open()) {
            BankAccount account(0, "", 0.0);
            while (file >> account.accountNumber >> account.accountHolder >> account.balance) {
                accounts.push_back(account);
            }
            file.close();
        }
}

void BankManager::saveAccounts() const {
        std::ofstream file(ACCOUNTS_FILE);
        if (file.is_open()) {
            for (const auto& account : accounts) {
                file << account.accountNumber << " " << account.accountHolder << " " << account.balance << endl;
            }
            file.close();
        }
}


