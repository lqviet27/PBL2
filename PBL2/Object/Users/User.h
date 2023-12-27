#pragma once
#include "../Date_Time/Date.cpp"
#include "../Account/Account.cpp"
#include "../../Data_structer/Link_list.cpp"
#include "../../Data_structer/Node.cpp"
class User
{
private:
    string CCCD;
    string _Name;
    Date _Birthday;
    string _PhoneNumber;
    string _Address;
    bool _Gender;
    Link_list<Account> userAccount;
public:
    User();
    User(string, string, Date, string, string, bool);
    User(const User &);
    ~User();
    void Show();
    void setName(string);
    void setBirthday(Date);
    void setPhoneNumber(string);
    void setAddress(string);
    void setGender(bool);
    void setCCCD(string);
    string getAddress();
    string getPhoneNumber();
    Date getBirthday();
    bool getGender();
    string getName();
    string getCCCD();
    bool SearchAccount(const Account &);
    Link_list<Account>* getUserAccount();
    void addAccount(Account &);
    void showAccount();
    bool operator==(const User &);
    bool operator>(const User &);
    void operator=(const User &);
    friend istream &operator>>(istream &, User &);
    void InsertObjecttoFile(ofstream &,int);
    void setEmptyLinkList();
    void copyUser(User);
    bool CheckUser(User &);
};