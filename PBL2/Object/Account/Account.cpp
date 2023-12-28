#pragma once
#include "Account.h"
#include <fstream>
#include <iomanip>
#include <iostream>

Account::Account() {
    this->typeAccount=0;
}

Account::Account(string CCCD,string idBank,string numAcc,string password, bool typeAccount,long long amount)
{
    // this->numAccount = b.getIdBank() + to_string(b.getCountAccount());
    // this->numAccount = idBank + numAcc_bank + Numaccount;
    this->CCCD = CCCD;
    this->numAccount = idBank + numAcc;
    this->password = password;
    this->amount = amount;
    this->typeAccount = typeAccount;
}
string Account::getCCCD() {
    return this->CCCD;
}

Account::Account(string CCCD,string numAcc,string password, bool typeAccount,long long amount)
{
    this->CCCD=CCCD;
    this->numAccount = numAcc;
    this->password = password;
    this->amount = amount;
    this->typeAccount = typeAccount;
}

Account::Account(const Account &d)
{
    this->CCCD = d.CCCD;
    this->numAccount = d.numAccount;
    this->amount = d.amount;
    this->typeAccount = d.typeAccount;
    this->password = d.password;
}

Account::~Account() {}

string Account::getNumAccount()
{
    return this->numAccount;
}

string Account::getPassword()
{
    return this->password;
}

bool Account::getTypeAccount()
{
    return this->typeAccount;
}

void Account::setNumAccount(string numAccount)
{
    this->numAccount = numAccount;
}

void Account::setPassword(string password)
{
    this->password = password;
}
void Account::setAmount(long long amount)
{
    this->amount += amount;
}
long long Account::getAmount(){
    return this->amount;
}
bool Account::operator==(const Account& ac)
{
    return (this->numAccount == ac.numAccount);
} 
bool Account::operator<(const Account& x)
{
    long long a = (this->amount);
    long long b = (x.amount);
    return (a < b);
}
bool Account::operator>(const Account& x)
{
    long long a = (this->amount);
    long long b = (x.amount);
    return (a > b);
}
istream &operator>>(istream &in, Account &acc)
{
    string a, b;
    while (1)
    {
        in >> a;
        cout << "\t\t\t\t\t\tXac nhan password ban vua nhap: ";
        in >> b;
        if (a == b)
        {
            cout << "\t\t\t\t\t\tMat khau da duoc xac nhan!";
            break;
        }
        else
            cout << "\t\t\t\t\t\tMat khau khong trung khop!!Moi ban nhap lai mat khau: ";
    }
    acc.password = a;
    return in;
}

void Account::InsertObjecttoFile(ofstream &FileOut,int ok)
{   
    if(ok == 0)
    {
        FileOut << CCCD << "|";
        FileOut << numAccount << "|";
        FileOut << amount << "|";
        FileOut << typeAccount << "|";
        FileOut << password<<"\n";
    }
    else 
    {
        FileOut << CCCD << "|";
        FileOut << numAccount << "|";
        FileOut << amount << "|";
        FileOut << typeAccount << "|";
        FileOut << password;
    } 
}

void Account::Show(){
    string type = (this->typeAccount) ? "Thanh Toan" : "Tiet Kiem";
    cout << "\t\t\t|  " << setw(12)<<this->CCCD<<"  |   "<<setw(11) << left << this->numAccount << "    |  " << setw(11) << left << type << "     | " << setw(11) << left << this->amount <<" VND"<< " |   " << setw(10) << this->password << " |" << endl;
}
void Account::operator=(const Account& x)
{
    this->CCCD=x.CCCD;
    this->numAccount= x.numAccount;
    this->typeAccount = x.typeAccount;
    this->amount = x.amount;
    this->password = x.password;
}

