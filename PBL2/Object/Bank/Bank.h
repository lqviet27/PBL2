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
        string getNameBank();
        bool searchAccount(const Account&);
        bool searchUser(const User&);
        // Link_list<User> get 
        //void addAccounttoFile(Account&);
        void addAccount(Account&);
        void addUser(User&);
        bool operator==(const Bank&);
        Account searchAccount(const string&);
        User searchUser(const string&);
        void InsertObjecttoFile(ofstream &);
};

