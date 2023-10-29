#include"Object/Bank/Bank.cpp"
#include"Object/Account/Account.cpp"
#include<iostream>
using namespace std;

int main(){
    Bank b("techcombank","001");
    Account a1("22","2705",true,100000);
    b.addAccount(a1);
    b.show_Account();
}