#pragma once
// #include"../Bank/Bank.cpp"
#include<iostream>
#include<string.h>
using namespace std;

class Account{
    private:
        string numAccount;
        string password;
        double amount;
        bool typeAccount;
    public:
        Account();
        Account(string, string ,bool,double =0);
        // Account(Bank, string, string ,bool,double =0); //* bị lỗi nếu muốn thêm một tham số là bank để lấy idbank + numaccount
        Account(const Account &);
        ~Account();
        string getNumAccout();
        string getPassword();
        void setNumAccount(string);
        void setPassword(string);
        void setAmount(double);
        double getAmount();
        friend istream &operator>>(istream &, Account &);
        bool operator==(const Account &);
        void InsertObjecttoFile(ofstream &);
        void Show();  
};