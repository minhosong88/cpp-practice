#include <iostream>
#include "Account_Util.h"

// Helper functions for Account Class
void display(const std::vector<Account> &accounts)
{
  std::cout << "\n=====Accounts ====================" << std::endl;
  for (const auto &acc : accounts)
    std::cout << acc << std::endl;
}

void deposit(std::vector<Account> &accounts, double amount)
{
  std::cout << "\n=====Deposit to Accounts ====================" << std::endl;
  for (auto &acc : accounts)
  {
    if (acc.deposit(amount))
      std::cout << "Deposited " << amount << " to " << acc << std::endl;
    else
      std::cout << "Failed Deposited of " << amount << " to " << acc << std::endl;
  }
}

void withdraw(std::vector<Account> &accounts, double amount)
{
  std::cout << "\n=====Withdraw from Accounts ====================" << std::endl;
  for (auto &acc : accounts)
  {
    if (acc.withdraw(amount))
      std::cout << "Withdrew " << amount << " from " << acc << std::endl;
    else
      std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
  }
}

// Helper functions for Savings_Account Class
void display(const std::vector<Savings_Account> &accounts)
{
  std::cout << "\n=====Savings_Account ====================" << std::endl;
  for (const auto &acc : accounts)
    std::cout << acc << std::endl;
}

void deposit(std::vector<Savings_Account> &accounts, double amount)
{
  std::cout << "\n=====Deposit to Savings_Account ====================" << std::endl;
  for (auto &acc : accounts)
  {
    if (acc.deposit(amount))
      std::cout << "Deposited " << amount << " to " << acc << std::endl;
    else
      std::cout << "Failed Deposited of " << amount << " to " << acc << std::endl;
  }
}

void withdraw(std::vector<Savings_Account> &accounts, double amount)
{
  std::cout << "\n=====Withdraw from Savings_Account ====================" << std::endl;
  for (auto &acc : accounts)
  {
    if (acc.withdraw(amount))
      std::cout << "Withdrew " << amount << " from " << acc << std::endl;
    else
      std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
  }
}

// Helper functions for Checking_Account Class
void display(const std::vector<Checking_Account> &accounts)
{
  std::cout << "\n=====Checking_Account ====================" << std::endl;
  for (const auto &acc : accounts)
    std::cout << acc << std::endl;
}

void deposit(std::vector<Checking_Account> &accounts, double amount)
{
  std::cout << "\n=====Deposit to Checking_Account ====================" << std::endl;
  for (auto &acc : accounts)
  {
    if (acc.deposit(amount))
      std::cout << "Deposited " << amount << " to " << acc << std::endl;
    else
      std::cout << "Failed Deposited of " << amount << " to " << acc << std::endl;
  }
}

void withdraw(std::vector<Checking_Account> &accounts, double amount)
{
  std::cout << "\n=====Withdraw from Checking_Account ====================" << std::endl;
  for (auto &acc : accounts)
  {
    if (acc.withdraw(amount))
      std::cout << "Withdrew " << amount << " from " << acc << std::endl;
    else
      std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
  }
}

// Helper functions for Trust_Account Class
void display(const std::vector<Trust_Account> &accounts)
{
  std::cout << "\n=====Trust_Account ====================" << std::endl;
  for (const auto &acc : accounts)
    std::cout << acc << std::endl;
}

void deposit(std::vector<Trust_Account> &accounts, double amount)
{
  std::cout << "\n=====Deposit to Trust_Account ====================" << std::endl;
  for (auto &acc : accounts)
  {
    if (acc.deposit(amount))
      std::cout << "Deposited " << amount << " to " << acc << std::endl;
    else
      std::cout << "Failed Deposited of " << amount << " to " << acc << std::endl;
  }
}

void withdraw(std::vector<Trust_Account> &accounts, double amount)
{
  std::cout << "\n=====Withdraw from Trust_Account ====================" << std::endl;
  for (auto &acc : accounts)
  {
    if (acc.withdraw(amount))
      std::cout << "Withdrew " << amount << " from " << acc << std::endl;
    else
      std::cout << "Failed Withdrawal of " << amount << " from " << acc << std::endl;
  }
}