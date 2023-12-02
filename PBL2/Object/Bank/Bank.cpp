#pragma once
#include"Bank.h"
#include<iostream>
#include<fstream>
//#include <filesystem>
using namespace std;
// namespace fs = std::filesystem;

Bank::Bank(){
    // this->countAccount=0;
}
Bank::Bank(string nameBank, string IDBank)
{   
    // this->countAccount = 0;
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
/*
void Bank::addAccounttoFile(Account& acc){
    ifstream file;
    string directory = "DataBase/Account";
    string fileName = directory+ "/Bank_" + this->IDBank + ".txt";
    // string fileName = directory+ "/Account" + ".txt";
    file.open(fileName);
    if(!fs::is_directory(directory)){
        fs::create_directory(directory);
    };
    if(!file){
       ofstream outFile(fileName); 
       outFile.close();
    }
    ofstream outFile(fileName, ios_base::app);
    if (!outFile.is_open()) {
            // Nếu không thể mở file, xuất thông báo lỗi và thoát khỏi phương thức
            cerr << "Error: Unable to open file " << fileName << endl;
            return;
        }
    acc.InsertObjecttoFile(outFile);
    outFile.close();
}
*/
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

// string Bank::getCountAccount()
// {
//     string tmp = to_string(this->countAccount);
//     return tmp;
// }
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

// void Bank::show_User()
// {
//     cout<<"DANH SACH NGUOI DUNG CUA NGAN HANG "<<this->nameBank<<" LA:"<<endl;
//     parUser.Show();
// }

string Bank::getNameBank()
{
    return this->nameBank;
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
    cout<<"\t\t\t";
    cout<<"|  "<<this->IDBank<<" |"<<"\t"<<this->nameBank<<setw(12)<<"\t |"<<endl;
    
}
bool Bank::operator==(const Bank& B)
{
    return (this->IDBank == B.IDBank);
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

void Bank::InsertObjecttoFile(ofstream &FileOut){
    FileOut<<this->IDBank<<"|"<<this->nameBank<<endl;
}

Link_list<User>* Bank::getLinkListUser(){
    return &(this->parUser);
}

Link_list<Account>* Bank::getLinkListAccount(){
    return &(this->parAccount);
}

// void Bank::operator=(const Bank& B)
// {
    
// }

