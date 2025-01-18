#ifndef _INSUFFICIENTBALANCEEXCEPTION_H
#define _INSUFFICIENTBALANCEEXCEPTION_H
#include <vector>
#include <string>

class InsufficientBalanceException
    : public std::exception
{

public:
    InsufficientBalanceException() = default;
    ~InsufficientBalanceException() = default;

    virtual const char *what() const noexcept
    {
        return "Insufficient Balance Exception";
    }
};

#endif