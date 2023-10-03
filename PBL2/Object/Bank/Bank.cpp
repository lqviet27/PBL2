#include"Bank.h"

Bank::Bank()
{}

Bank::~Bank()
{}

void Bank::show_User()
{
    cout<<"DANH SACH NGUOI DUNG CUA NGAN HANG "<<this->nameBank<<" LA:"<<endl;
    while(this->parUser != nullptr) 
    {
         parUser->next.show_User();
    }
}

