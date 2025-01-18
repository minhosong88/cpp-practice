#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main()
{
    unique_ptr<Account> chk;
    unique_ptr<Account> ill_chk;
    unique_ptr<Account> svs;
    unique_ptr<Account> trst;
    try
    {
        chk = make_unique<Checking_Account>("Minho", 5000);

        svs = make_unique<Savings_Account>("Sunha", 2000);
        trst = make_unique<Trust_Account>("Jianjun", 1000);
    }
    catch (IllegalBalanceException &ex)
    {
        cerr << ex.what() << endl;
    }

    try
    {
        chk->deposit(5000);
        chk->withdraw(10001);
    }
    catch (IllegalBalanceException &ex)
    {
        cerr << ex.what() << endl;
    }
    catch (InsufficientBalanceException &ex)
    {
        cerr << ex.what() << endl;
    }

    // test your code here
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}
