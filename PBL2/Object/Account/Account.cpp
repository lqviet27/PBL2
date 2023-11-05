
#include "Account.h"
#include <fstream>
#include <iomanip>
#include <iostream>
Account::Account() {
    this->typeAccount=0;
}

Account::Account(string idBank,string numAcc,string password, bool typeAccount,double amount)
{
    // this->numAccount = b.getIdBank() + to_string(b.getCountAccount());
    // this->numAccount = idBank + numAcc_bank + Numaccount;
    this->numAccount = idBank + numAcc;
    this->password = password;
    this->amount = amount;
    this->typeAccount = typeAccount;
}

Account::Account(string numAcc,string password, bool typeAccount,double amount)
{
    this->numAccount = numAcc;
    this->password = password;
    this->amount = amount;
    this->typeAccount = typeAccount;
}

Account::Account(const Account &d)
{
    this->numAccount = d.numAccount;
    this->amount = d.amount;
    this->typeAccount = d.typeAccount;
    this->password = d.password;
}

Account::~Account() {}

string Account::getNumAccout()
{
    return this->numAccount;
}

string Account::getPassword()
{
    return this->password;
}

void Account::setNumAccount(string numAccount)
{
    this->numAccount = numAccount;
}

void Account::setPassword(string password)
{
    this->password = password;
}
void Account::setAmount(double amount)
{
    this->amount += amount;
}
double Account::getAmount(){
    return this->amount;
}
bool Account::operator==(const Account& ac)
{
    return (this->numAccount == ac.numAccount);
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

void Account::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << numAccount << "|";
    FileOut << amount << "|";
    FileOut << password; 
}

void Account::Show(){
    string type = (this->typeAccount) ? "Tiet kiem" : "Thanh toan";
    cout << "\t\t\t|  " << setw(11) << this->numAccount << "   |  " << setw(11) << type << "     |  " << setw(9) << fixed << setprecision(2) << this->amount << "  |  " << setw(6) << this->password << "     |" << endl;
}
void Account::operator=(const Account& x)
{
    this->numAccount= x.numAccount;
    this->typeAccount = x.typeAccount;
    this->amount = x.amount;
    this->password = x.password;
}

