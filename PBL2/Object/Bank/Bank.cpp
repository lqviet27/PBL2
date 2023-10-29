
#include"Bank.h"
// int Bank::countAccount = 0;
Bank::Bank(){

}
Bank::Bank(string nameBank, string IDBank)
{
    this->nameBank = nameBank;
    this->IDBank = IDBank;
    
}


Bank::~Bank()
{

}

string Bank::getIdBank()
{
    return this->IDBank;
}

void Bank::addAccount(Account ac)
{
    parAccount.Add(ac);
}
// int Bank::getCountAccount()
// {
//     return countAccount;
// }
// void Bank::show_User()
// {
//     cout<<"DANH SACH NGUOI DUNG CUA NGAN HANG "<<this->nameBank<<" LA:"<<endl;
//     parUser.Show();
// }
void Bank::show_Account()
{
    cout<<"DANH SACH TAI KHOAN CUA NGAN HANG "<<this->nameBank<<" LA:"<<endl;
    parAccount.Show();
}

