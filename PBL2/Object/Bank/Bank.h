#include"../Users/User.h"
#include"../Account/Account.h"
class Bank{
    private:
        string nameBank;
        string IDBank;
        User *parUser;
        Account *ParAccount;
    public:
        Bank();
        ~Bank();
        void show_User();
        void show_Account();
};

