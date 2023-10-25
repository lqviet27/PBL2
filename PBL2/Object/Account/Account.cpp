
#include "Account.h"
#include <fstream>
#include <iomanip>

Account::Account() {}

Account::Account(string numAccount, string password, bool typeAccount,double amount)
{
    this->numAccount = numAccount;
    this->password = password;
    this->amount = amount;
    this->typeAccount = typeAccount;
}

Account::Account(const Account &d)
{
    this->numAccount = d.numAccount;
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
// istream &operator>>(istream &in, Account &acc)
// {
//     string in,b,c;
//     menu(in,in,in);
//     Account(a,b,c);
    
//     string a, b;
//     while (1)
//     {
//         in >> a;
//         cout << "\t\t\t\t\t\tXac nhan password ban vua nhap: ";
//         in >> b;
//         if (a == b)
//         {
//             cout << "\t\t\t\t\t\tMat khau da duoc xac nhan!";
//             break;
//         }
//         else
//             cout << "\t\t\t\t\t\tMat khau khong trung khop!!Moi ban nhap lai mat khau: ";
//     }
//     acc.password = a;
//     return in;
// }

void Account::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << numAccount << "|";
    FileOut << amount << "|";
    FileOut << password; 
}

void Account::Show(){
    cout<<this->numAccount<<"|"<<fixed<<setprecision(2)<<this->amount<<"|"<<this->password<<endl;
}

