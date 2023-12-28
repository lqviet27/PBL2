#pragma once
#include "User.h"
#include <fstream>
#include <iomanip>

User::User() {
    this->CCCD = "";
    this->_Name = "";
    this->_Birthday = Date(0,0,0);
    this->_PhoneNumber = "";
    this->_Address = "";
    this->_Gender = 0;
}

User::User(string CCCD, string name, Date bi, string pn, string address, bool g)
{
    this->CCCD = CCCD;
    this->_Name = name;
    this->_Birthday = bi;
    this->_PhoneNumber = pn;
    this->_Address = address;
    this->_Gender = g;
}

User::User(const User &us)
{
    this->userAccount = us.userAccount;
    this->CCCD = us.CCCD;
    this->_Name = us._Name;
    this->_Birthday = us._Birthday;
    this->_PhoneNumber = us._PhoneNumber;
    this->_Address = us._Address;
    this->_Gender = us._Gender;
}

User::~User() {}

void User::Show()
{
    cout << "\t\t\t|  " << this->CCCD << "  | " << setw(19) << left << this->_Name << "      |    ";
    // cout << setw(5) ;
    this->_Birthday.ShowDate();
    cout<< "   |  ";
    cout << setw(14) << left << this->_PhoneNumber << "    |   " << setw(25) << left << this->_Address ;
    if(this->_Gender){
        cout << "  |      "  << "Nu" << "       |" << endl;
    }
    else{
        cout << "  |      " << "Nam" << "      |" << endl;
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

void User::setCCCD(string cccd)
{
    this->CCCD = cccd;
}

void User::setAddress(string value)
{
    this->_Address = value;
}

void User::setGender(bool value)
{
    this->_Gender = value;
}

string User::getAddress()
{
    return this->_Address;
}
string User::getPhoneNumber()
{
    return this->_PhoneNumber;
}
bool User::getGender()
{
    return this->_Gender;
}
Date User::getBirthday()
{
    return this->_Birthday;
}
istream &operator>>(istream &in, User &us)
{   
    int check;
    string CCCD;
    while(1)
    {
    cout<<"\t\t\t\tNhap Can Cuoc Cong Dan(Gom 12 Chu So Lien Tiep(Nhap 'Exit' de thoat)):  ";
    cin>>CCCD;
    if(CCCD=="Exit")
        {
            us.CCCD=CCCD;
            return in;
        }
    if (CCCD.length() == 12)
        {
            bool isAllDigits = true;
            for (char c : CCCD) {
                if (!isdigit(c)) {
                    isAllDigits = false;
                    break;
                }
            }

            if (isAllDigits) {
                us.CCCD=CCCD;
                break;
            }
            else {
                cout << "\t\t\t\tBan Phai Nhap Chu So!!!" <<endl;
                system("Pause");
            }
        }
        else {
            cout << "\t\t\t\tBan Phai Nhap Dung 12 Chu So!!!" <<endl;
            // system("Pause");
        }

    }
    cout << "\t\t\t\tNhap Ho Va Ten: ";
    char str[100];
    fflush(stdin);
    in.getline(str, sizeof(str)); // Trường hợp đặc biệt
    us._Name = str;
    cout << "\t\t\t\tNhap Ngay Sinh(dd/mm/yyyy): ";
    in >> us._Birthday;
    cout << "\t\t\t\tNhap So Dien Thoai(bao Gom 10 Chu so Lien Tiep): ";
    in >> us._PhoneNumber;
    cout << "\t\t\t\tNhap Dia Chi: "; // Trường hợp đặc biệt
    fflush(stdin);
    in.getline(str, sizeof(str));
    us._Address = str;
    cout << "\t\t\t\tNhap Gioi Tinh(Nam/Nu): ";
    string gender;
    do
    {
        if (check == 1)
            cout << "\t\t\t\tSai Cu Phap Gioi Tinh, Moi Ban Nhap Lai :";
        check = 1;
        in >> gender;
        if (gender == "nam" || gender == "Nam" || gender == "0")
        {
            us._Gender = 0;
            check = 0;
        }
        else if (gender == "Nu" || gender == "nu" || gender == "1")
        {
            us._Gender = 1;
            check = 0;
        }
    } while (check);
    return in;
}
string User::getName() 
{
    return this->_Name;
}
string User::getCCCD() 
{
    return this->CCCD;
}
Link_list<Account>* User::getUserAccount()
{
    return &this->userAccount;
}
bool User::SearchAccount(const Account&  AC)
{
    Node<Account> *tail=userAccount.head;
    while(tail!=nullptr)
    {
        if(tail->data==AC) return true;
        tail = tail->next;
    }
    return false;
}
bool User::operator==(const User &us)
{
    return (this->CCCD == us.CCCD);
}
bool User::operator>(const User &us)
{
    string lastName1, lastName2;
    string l1,l2;
    size_t lastSpace = this->getName().rfind(' ');
    size_t lastSpace2 = us._Name.rfind(' ');
    lastName1 = this->_Name.substr(lastSpace + 1);
    lastName2 = us._Name.substr(lastSpace2 + 1);
    l1=lastName1.substr(0,1);
    l2=lastName2.substr(0,1);
    return (l1 > l2);
}
void User::operator=(const User &us)
{   
    this->userAccount = us.userAccount;
    this->CCCD = us.CCCD;
    this->_Name = us._Name;
    this->_Address = us._Address;
    this->_Birthday = us._Birthday;
    this->_Gender = us._Gender;
    this->_PhoneNumber = us._PhoneNumber;
}

void User::InsertObjecttoFile(ofstream &FileOut,int ok)
{
    if(ok==0)
    {
    FileOut << CCCD << '|';
    FileOut << _Name << '|';
    FileOut << _Birthday << '|';
    FileOut << _PhoneNumber << '|';
    FileOut << _Address << '|';
    FileOut << _Gender <<endl;
    }
    else 
    {
    FileOut << CCCD << '|';
    FileOut << _Name << '|';
    FileOut << _Birthday << '|';
    FileOut << _PhoneNumber << '|';
    FileOut << _Address << '|';
    FileOut << _Gender ;
    }
}

void User::addAccount(Account &ac)
{
    if(this->SearchAccount(ac)==false)
    {
        userAccount.Add(ac);
        return ;
    }
    else {
        cout<<"Nguoi Dung "<<this->getCCCD()<<" Da Co Tai Khoan "<<ac.getNumAccount()<<endl;
    }
}

void User::copyUser(User us)
{
    this->CCCD = us.CCCD;
    this->_Name = us._Name;
    this->_Address = us._Address;
    this->_Birthday = us._Birthday;
    this->_Gender = us._Gender;
    this->_PhoneNumber = us._PhoneNumber;
}


void User::showAccount()
{
    userAccount.Show();
}

void User::setEmptyLinkList()
{
    this->userAccount.head=nullptr;
}




bool User::CheckUser( User &Us)
{ 
    if(this->CCCD!=Us.getCCCD())
        return false;
    if(this->_Name!=Us.getName())
        return false;
    if(this->_Address!=Us.getAddress())
        return false;
    if(this->_Gender!=Us.getGender())
        return false;
    if(this->_PhoneNumber!=Us.getPhoneNumber())
        return false;
    if(this->_Birthday.CheckDate(Us.getBirthday())==false)
        return false;
    return true;
}