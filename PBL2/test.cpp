
// #include"Object/Account/Account.cpp"
#include"Object/Users/User.cpp"
// #include"QuanLy/Bank/QLNH.cpp"
#include"DangNhap_DangKy/SignIn.cpp"
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
    Bank b2("Dut bank","002");
    Bank b3("Dutytyt bank","003");
    QLNH admin;
    admin.addBank(b);
    admin.addBank(b2);
     b2.addAccount(a1);
    admin.addBank(b3);
     b3.addAccount(a1);
    admin.showBank();
    SignIn::DangNhap(admin);
}