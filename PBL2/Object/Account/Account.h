#pragma once
// #include"../Bank/Bank.cpp"
#include<iostream>
#include<string.h>
using namespace std;


class Account{
    private:
        string CCCD;
        string numAccount;
        string password;
        long long amount;
        bool typeAccount;
    public:
        Account();
        Account(string,string,string,string ,bool,long long);
        Account(string,string,string ,bool,long long);
        Account(const Account &);
        ~Account();
        string getNumAccount();
        string getPassword();
        string getCCCD();
        bool getTypeAccount();
        void setNumAccount(string);
        void setPassword(string);
        void setAmount(long long);
        long long getAmount();
        friend istream &operator>>(istream &, Account &);
        bool operator==(const Account &);
        void operator=(const Account &);
        void InsertObjecttoFile(ofstream &);
        void Show();
};