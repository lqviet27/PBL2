#include<iostream>
using namespace std;

class Account{
    private:
        string numAccount;
        string password;
        double amount;
        bool typeAccount;
    public:
        Account();
        Account(string, string ,bool);
        Account(const Account &);
        ~Account();
        string getNumAccout();
        string getPassword();
        void setNumAccount(string);
        void setPassword(string);
        friend istream &operator>>(istream &, Account &);
        void InsertObjecttoFile(ofstream &);
};