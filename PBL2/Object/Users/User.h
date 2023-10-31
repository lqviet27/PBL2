#pragma once
#include"../Date_Time/Date.cpp"
#include"../Account/Account.h"
#include"../../Data_structer/Link_list.cpp"
#include"../../Data_structer/Node.cpp"
class User
{
private:
    string _Name;
    Date _Birthday;
    string _PhoneNumber;
    string _Address;
    bool _Gender;
    Link_list<Account> userAccount;

public:
    User();
    User(string, Date, string, string, bool);
    User(const User &);
    ~User();
    void Show();
    void Name(string);
    void Birthday(Date);
    void PhoneNumber(string);
    void Address(string);
    void Gender(bool);
    void addAccount(const Account&);
    void showAccount();

    friend istream &operator>>(istream &, User &);
    void InsertObjecttoFile(ofstream &);
    
};