// Section 17
// Unique Pointers
#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Savings_Account.h"

class Test
{
private:
    int data;

public:
    // No args constructor - delegating
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    // args constructor
    Test(int data) : data{data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    // getter
    int get_data() const { return data; }
    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

using namespace std;

int main()
{

    // Test t1{1000};
    //  Test *t1 = new Test{1000};
    //  delete[] t1;

    // std::unique_ptr<Test> t1{new Test{100}};                 // unique pointer to Test object
    // std::unique_ptr<Test> t2 = std::make_unique<Test>(1000); // using make_unique function

    // std::unique_ptr<Test> t3;
    // // t3 = t1; cannot copy or assign unique pointer
    // t3 = std::move(t1); // move is possible
    // if (!t1)// Since t1 ptr is moved to t3, t1 is nullptr
    //     std::cout << "t1 is nullptr" << std::endl;

    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Minho", 5000);
    std::cout << *a1 << std::endl;
    a1->deposit(5000);
    std::cout << *a1 << std::endl;

    std::vector<std::unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Checking_Account>("Minho", 1000));
    accounts.push_back(make_unique<Savings_Account>("Sunha", 4000, 5.2));
    accounts.push_back(make_unique<Trust_Account>("Jianjun", 5000, 4.5));

    for (const auto &acc : accounts)
        std::cout << *acc << std::endl;

    return 0;
}
