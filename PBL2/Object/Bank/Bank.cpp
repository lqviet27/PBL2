#pragma once
#include"Bank.h"
#include<iostream>
#include<fstream>
using namespace std;

Bank::Bank(){
    this->nameBank = "";
    this->IDBank = "";
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

void Bank::addAccount(Account & ac)
{
    if(this->searchAccount(ac)==false)
    {
        parAccount.Add(ac);
        return ;
    }
    else {
        cout<<"Ngan Hang "<<this->getIdBank()<<" Da Co Tai Khoan "<<ac.getNumAccount()<<endl;
    }
}

void Bank::addUser(User& us)
{
     if(this->searchUser(us)==false)
    {   
        parUser.Add(us);
        return ;
    }
    else {
        cout<<"Ngan Hang "<<this->getNameBank()<<" Da Ton Tai Nguoi Dung "<<us.getCCCD()<<endl;
    }
}

bool Bank::searchAccount(const Account& AC)
{
    Node<Account> *tail=parAccount.head;
    while(tail!=nullptr)
    {
        if(tail->data==AC) return true;
        tail = tail->next;
    }
    return false;
}

bool Bank::searchUser( User& US)
{
    Node<User> *tail=parUser.head;
    while(tail!=nullptr)
    {
        if(tail->data==US)
             return true;
        tail = tail->next;
    }
    return false;
}


string Bank::getNameBank()
{
    return this->nameBank;
}

void Bank::setNameBank(string nameBank)
{
    this->nameBank = nameBank;
}
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
    cout<<"\t\t\t\t\t";
    cout <<"| "<< this->IDBank << " |          " << left << setw(22) << this->nameBank << " |" << endl;
}
bool Bank::operator==(const Bank& B)
{
    return (this->IDBank == B.IDBank);
}

long long Bank::TotalAmount()
{
    long long total=0;
    Node<Account> *NA=this->getLinkListAccount()->head;
    while(NA!=nullptr)
    {
        total+=NA->data.getAmount();
        NA=NA->next;
    }
    return total;
}

bool Bank::operator>(Bank& B)
{

    long long a = (this->TotalAmount());
    long long b = B.TotalAmount();
    return (a > b);
}
Node<Account>* Bank::searchAccount(const string& numAcc){
    Account A("",numAcc,"",0,0);
    Node<Account> *b = this->parAccount.Search(A);
    return b;  
}

Node<User>* Bank::searchUser(const string& CCCD)
{
    User A(CCCD,"",Date(0,0,0),"","",false);
    Node<User> *b = this->parUser.Search(A);
    return b;
}

void Bank::InsertObjecttoFile(ofstream &FileOut,int ok){
    if(ok==0)
        FileOut<<this->IDBank<<"|"<<this->nameBank<<endl;
    else    FileOut<<this->IDBank<<"|"<<this->nameBank;
}

Link_list<User>* Bank::getLinkListUser(){
    return &(this->parUser);
}

Link_list<Account>* Bank::getLinkListAccount(){
    return &(this->parAccount);
}

