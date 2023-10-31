
#include"Bank.h"

Bank::Bank(){

}
Bank::Bank(string nameBank, string IDBank)
{   
    
    this->countAccount = 0;
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

void Bank::addAccount(Account& ac)
{
    this->countAccount++;
    parAccount.Add(ac);
    // parAccount.Search(ac)->data.setNumAccount(this->IDBank + to_string(this->countAccount));
}

void Bank::addUser(const User& us)
{
    parUser.Add(us);
}

string Bank::getCountAccount()
{
    string tmp = to_string(this->countAccount);
    return tmp;
}

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
void Bank::show_User(){
    cout<<"DANH SACH KHACH HANG CUA NGAN HANG "<<this->nameBank<<" LA:"<<endl;
    parUser.Show();
}
void Bank::Show(){
    
}


