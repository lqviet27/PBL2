#include "User.h"
#include <fstream>
#include <iomanip>

User::User() {}

User::User(string name, Date bi, string pn, string address, bool g)
{
    this->_Name = name;
    this->_Birthday = bi;
    this->_PhoneNumber = pn;
    this->_Address = address;
    this->_Gender = g;
}

User::User(const User &nv)
{
    this->_Name = nv._Name;
    this->_Birthday = nv._Birthday;
    this->_PhoneNumber = nv._PhoneNumber;
    this->_Address = nv._Address;
    this->_Gender = nv._Gender;
}

User::~User() {}

void User::ShowUser()
{
    cout << " " << setw(28) << left << _Name << " |";
    cout << " ";
    _Birthday.ShowDate();
    cout << " | " << setw(12) << left << _PhoneNumber;
    cout << "| " << setw(24) << left << _Address;
    cout << "|     ";
    if (_Gender)
        cout << setw(9) << left << " Nu";
    else
        cout << setw(9) << left << " Nam";
    cout << "|" << endl;
}


void User::Name(string value)
{
    this->_Name = value;
}

void User::Birthday(Date value)
{
    this->_Birthday = value;
}

void User::PhoneNumber(string value)
{
    this->_PhoneNumber = value;
}

void User::Address(string value)
{
    this->_Address = value;
}

void User::Gender(bool value)
{
    this->_Gender = value;
}

istream &operator>>(istream &in, User &nv)
{
    int check;
    cout << "Nhap ten khach hang: ";
    char str[100];
    fflush(stdin);
    in.getline(str, sizeof(str)); // Trường hợp đặc biệt
    nv._Name = str;
    cout << "Nhap ngay sinh: ";
    in >> nv._Birthday;
    cout << "Nhap so dien thoai: ";
    in >> nv._PhoneNumber;
    cout << "Nhap dia chi: "; // Trường hợp đặc biệt
    fflush(stdin);
    in.getline(str, sizeof(str));
    nv._Address = str;
    cout << "Nhap gioi tinh: ";
    string gender;
    do
    {
        if (check == 1)
            cout << "Sai cu phap gioi tinh, moi ban nhap lai :";
        check = 1;
        in >> gender;
        if (gender == "nam" || gender == "Nam" || gender == "0")
        {
            nv._Gender = 0;
            check = 0;
        }
        else if (gender == "Nu" || gender == "nu" || gender == "1")
        {
            nv._Gender = 1;
            check = 0;
        }
    } while (check);
    return in;
}

void User::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _Name << '|';
    FileOut << _Birthday << '|';
    FileOut << _PhoneNumber << '|';
    FileOut << _Address << '|';
    FileOut << _Gender;
}

int main()
{
    User X("viet",02/01/2000,"038407443","so 2 le van thiem",1);
    X.ShowUser();
}