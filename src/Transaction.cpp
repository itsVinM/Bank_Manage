// Transaction.cpp
#include "Transaction.h"

Transaction::Transaction(TransactionType transactionType, double transactionAmount)
    : type(transactionType), amount(transactionAmount) {
    timestamp = time(nullptr);
}
