//bank_account.h
#include<stdlib.h>
#include<iostream>

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class BankAccount//Abstract class
{
friend void show_balance(const BankAccount &account);
friend std::ostream& operator<<(std::ostream& out, const BankAccount &account);

public:
    BankAccount(){get_balance_from_db();}//default constructor
    BankAccount(int b) : balance(b){/*empty code block*/}
    virtual int get_balance() const = 0;//pure virtual function
    void deposit(int amount);
    void withdraw(int amount);

protected:
    int balance{0};//initialize to 0

private:
    void get_balance_from_db();
};

#endif

