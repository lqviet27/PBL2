#include"../Users/User.h"
#include"../Account/Account.h"
#include"../../Data_structer/Link_list.cpp"
#include"../..//Data_structer/Node.cpp"
class Bank{
    private:
        static int countAccount;
        string nameBank;
        string IDBank;
        Link_list<User> parUser;
        Link_list<Account> parAccount;
    public:
        Bank();
        Bank(string,string);
        ~Bank();
        string getIdBank();
        // static int getCountAccount();
        void show_User();
        void show_Account();
        void addAccount(Account);
};

