#pragma once
#include"../../Object/Account/Account.cpp"
#include"../../Data_structer/Link_list.cpp"
#include"../../Data_structer/Node.cpp"
#include"../Users/QLKH.cpp"
// #include"../Bank/QLNH.cpp"

using namespace std;
class QLTK
{
private:
    Link_list<Account> parAccount;
public:
    QLTK();
    QLTK(Link_list<Account>);
    QLTK(const QLTK&);
    ~QLTK();
    void addAccount(const Account&);
    void Sort();
    void showAccount();
    Link_list<Account> *getLinkListAccount();
    Node<Account> * SearchAccount(const string&);
};

