#include "QLKH.h"
#include <fstream>
#include <conio.h>

QLKH::QLKH()
{
    ifstream FileIn("../../Database/User/User.txt", ios_base::in);
    if (FileIn.fail())
    {
        cout << "Khong tim thay file User.txt! Import khong thanh cong" << endl;
    }
    else
    {
        while (!FileIn.eof())
        {
            string CCCD, Name, PhoneNumber, Address;
            int dd, mm, yy;
            bool Gender;
            char separator;
            getline(FileIn, CCCD, '|');
            getline(FileIn, Name, '|');
            FileIn >> dd >> separator >> mm >> separator >> yy >> separator;
            getline(FileIn, PhoneNumber, '|');
            getline(FileIn, Address, '|');
            FileIn >> Gender ;
            User Us(CCCD, Name, Date(dd, mm, yy), PhoneNumber, Address, Gender);
            addUser(Us);
            cout << "Da them thanh cong nguoi dung" << Name << " vao Database!" << endl;
        }
    }
    FileIn.close();
}

QLKH::QLKH(Link_list<User> parUser)
{
    this->parUser = parUser;
}
QLKH::QLKH(const QLKH &q)
{
    this->parUser = q.parUser;
}
QLKH::~QLKH()
{
    this->parUser.~Link_list();
}
void QLKH::addUser(const User &b)
{
    parUser.Add(b);
}
void QLKH::showUser()
{
    cout << "\t\t\t+=====================================================================================================================+" << endl;
    cout << "\t\t\t|                                               ** DANH SACH NGUOI DUNG **                                            |" << endl;
    cout << "\t\t\t+=====================================================================================================================+" << endl;
    cout << "\t\t\t|      CCCD      |       HoVaTen       |    Ngay Sinh    |    So Dien Thoai   |           Dia Chi           |   Gioi Tinh   |" << endl;
    cout << "\t\t\t+=====================================================================================================================+" << endl;
    this->parUser.Show();
    cout << "\t\t\t+=====================================================================================================================+" << endl;
}

//! bi loi search User ra nhung bi sai o so du va laoi tai khoan
User QLKH::SearchUser(const string & CCCD)
{
    User Us(CCCD,"",Date(1,1,2004),"", "",1);
    Node<User> *b = this->parUser.Search(Us);
    if (b != nullptr)
    {
        return b->data;
    }
    else
    {
        cout << "Khong tim thay Nguoi Dung!" << endl;
        return Us;
    }
}
void QLKH::ImportFromFile()
{

}