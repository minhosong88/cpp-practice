#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include <string>
#include "Account.h"
#include "Trust_Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"

// Utility helper functions Using Base Class Pointer
void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);

#endif