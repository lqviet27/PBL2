#include"Object/Bank/Bank.cpp"
#include"Object/Account/Account.cpp"
#include"Object/Users/User.cpp"
#include<iostream>
using namespace std;

int main(){
    Date d1(1,1,2000);
    Bank b("techcombank","001");
    User u1("Le Quoc Viet",d1,"0123456789","DA NANG",false);
    Account a1("001","123456","2705",true,100000);
    b.addUser(u1);
    b.addAccount(a1);
    b.show_Account();
    u1.addAccount(a1);
    u1.showAccount();
    b.show_User();
    cout<<endl;
    cout<<b.getCountAccount()<<endl;
}