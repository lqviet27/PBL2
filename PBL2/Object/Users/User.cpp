#pragma once
#include "User.h"
#include <fstream>
#include <iomanip>

User::User() {}

User::User(string CCCD, string name, Date bi, string pn, string address, bool g)
{
    this->CCCD = CCCD;
    this->_Name = name;
    this->_Birthday = bi;
    this->_PhoneNumber = pn;
    this->_Address = address;
    this->_Gender = g;
}

User::User(const User &nv)
{
    this->CCCD = nv.CCCD;
    this->_Name = nv._Name;
    this->_Birthday = nv._Birthday;
    this->_PhoneNumber = nv._PhoneNumber;
    this->_Address = nv._Address;
    this->_Gender = nv._Gender;
}

User::~User() {}

void User::Show()
{
    cout << "\t\t\t|  " << this->CCCD << "  | " << setw(20) << this->_Name << " | ";
    cout << setw(4) << this->_Birthday << "   |";
    cout << setw(15) << this->_PhoneNumber << "     | " << setw(25) << this->_Address << "    | " ;
    if(this->_Gender){
        cout << setw(7) << "Nu" << "       |" << endl;
    }
    else{
        cout << setw(7) << "Nam" << "       |" << endl;
    }
}

void User::setName(string value)
{
    this->_Name = value;
}

void User::setBirthday(Date value)
{
    this->_Birthday = value;
}

void User::setPhoneNumber(string value)
{
    this->_PhoneNumber = value;
}

void User::setAddress(string value)
{
    this->_Address = value;
}

void User::setGender(bool value)
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
bool User::operator==(const User &us)
{
    return (this->CCCD == us.CCCD);
}
void User::operator=(const User &us)
{
    this->CCCD = us.CCCD;
    this->_Name = us._Name;
    this->_Address = us._Address;
    this->_Birthday = us._Birthday;
    this->_Gender = us._Gender;
    this->_PhoneNumber = us._PhoneNumber;
}

void User::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _Name << '|';
    FileOut << _Birthday << '|';
    FileOut << _PhoneNumber << '|';
    FileOut << _Address << '|';
    FileOut << _Gender;
}

void User::addAccount(const Account &ac)
{
    userAccount.Add(ac);
}

void User::showAccount()
{
    cout << "DANH SACH TAI KHOAN CUA KHACH HANG " << this->_Name << " LA:" << endl;
    userAccount.Show();
}
