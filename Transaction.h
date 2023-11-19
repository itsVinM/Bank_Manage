// Transaction.h
#pragma once

#include <ctime>

class Transaction {
public:
    enum TransactionType { DEPOSIT, WITHDRAWAL };

    time_t timestamp;
    TransactionType type;
    double amount;

    Transaction(TransactionType transactionType, double transactionAmount);
};

