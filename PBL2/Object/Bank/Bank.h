#pragma once
#include"../Users/User.cpp"
#include"../../Data_structer/Link_list.cpp"
#include"../../Data_structer/Node.cpp"

class Bank{
    private:
        string nameBank;
        string IDBank;
        Link_list<User> parUser;
        Link_list<Account> parAccount;
    public:
        Bank();
        Bank(string,string);
        ~Bank();
        string getIdBank();
        string getNameBank();
        void setNameBank(string);
        void show_User();
        void show_Account();
        void Show();
        bool searchAccount(const Account&);
        bool searchUser( User&);
        void addAccount(Account&);
        void addUser(User&);
        bool operator==(const Bank&);
        bool operator>( Bank&);
        Node<Account>* searchAccount(const string&);
        Node<User>* searchUser(const string&);
        void InsertObjecttoFile(ofstream &,int);
        Link_list<Account>* getLinkListAccount();
        Link_list<User>* getLinkListUser();
        long long TotalAmount();
};

