#pragma once
#include"QLTK.h"
#include<fstream>
#include <conio.h>


QLTK::QLTK()
{
    ifstream FileIn("Database/Account/Account.txt", ios_base::in);
    if(FileIn.fail()){
        cout<<"Khong tim thay file Bank.txt! Import khong thanh cong"<<endl;
    }
    else{
        while(!FileIn.eof()){
            string CCCD,numAccount, password;
            long long amount;
            bool typeAccount;
            char separator;
            getline(FileIn, CCCD,'|');
            getline(FileIn, numAccount, '|');
            FileIn >> amount >> separator;
            FileIn >> typeAccount >> separator;
            getline(FileIn, password, '\n');
            Account A(CCCD,numAccount, password, typeAccount, amount); 
            addAccount(A);
        }
    }
    FileIn.close();
}

QLTK::QLTK(Link_list<Account> parAccount){
    this->parAccount=parAccount;
}
QLTK::QLTK(const QLTK& q){
    this->parAccount=q.parAccount;
}
QLTK::~QLTK()
{
    this->parAccount.~Link_list();
}
void QLTK::addAccount(const Account& b){
    parAccount.Add(b);
}
void QLTK::Sort(){
    this->parAccount.Sort();
}
void QLTK::showAccount()
{
    // cout << "\t\t\t+===============================================================+" << endl;
    // cout << "\t\t\t|                    ** DANH SACH TAI KHOAN **                  |" << endl;
    // cout << "\t\t\t+================+==================+============+==============+" << endl;
    // cout << "\t\t\t|  So Tai Khoan  |  Loai Tai Khoan  |    So Du   |   Mat Khau   |" << endl;
    // cout << "\t\t\t+================+==================+============+==============+" << endl;
    // this->parAccount.Show();
    // cout << "\t\t\t+================+==================+============+==============+" << endl;
    cout << "\t\t\t+=======================================================================================+" << endl;
    cout << "\t\t\t|                               ** THONG TIN TAI KHOAN **                               |" << endl;
    cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
    cout << "\t\t\t|      CCCD      |   So Tai Khoan   |  Loai Tai Khoan  |      So Du      |   Mat Khau   |" << endl;
    cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
    this->parAccount.Show();
    cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
}

Link_list<Account> *QLTK::getLinkListAccount()
{
    return &this->parAccount;
}


Node<Account> * QLTK::SearchAccount(const string& numAcc){
    Account A("",numAcc,"",0,0);
    Node<Account> *b = this->parAccount.Search(A);
    return b;
}

