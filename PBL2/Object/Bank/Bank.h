// #include"../Account/Account.cpp"
#include"../Users/User.cpp"
#include"../../Data_structer/Link_list.cpp"
#include"../../Data_structer/Node.cpp"

class Bank{
    private:
        int countAccount;
        string nameBank;
        string IDBank;
        Link_list<User> parUser;
        Link_list<Account> parAccount;
    public:
        Bank();
        Bank(string,string);
        ~Bank();
        string getIdBank();
        string getCountAccount();
        void show_User();
        void show_Account();
        void Show();
        void addAccount(Account&);
        string getNameBank();
        //void addAccounttoFile(Account&);
        void addUser(const User&);
        bool operator==(const Bank&);
        Account searchAcc(const string&);
        void InsertObjecttoFile(ofstream &);
};

