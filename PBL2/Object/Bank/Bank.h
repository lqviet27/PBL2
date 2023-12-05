// #include"../Account/Account.cpp"
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
        void show_User();
        void show_Account();
        void Show();
        string getNameBank();
        bool searchAccount(const Account&);
        bool searchUser( User&);
        // Link_list<User> get 
        //void addAccounttoFile(Account&);
        void addAccount(Account&);
        void addUser(User&);
        bool operator==(const Bank&);
        bool operator>(const Bank&);
        Node<Account>* searchAccount(const string&);
        Node<User>* searchUser(const string&);
        void InsertObjecttoFile(ofstream &);
        Link_list<Account>* getLinkListAccount();
        Link_list<User>* getLinkListUser();
        //void operator=(const Bank&); 
};

