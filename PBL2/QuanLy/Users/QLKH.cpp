#pragma once
#include "QLKH.h"
#include <fstream>
#include <conio.h>

QLKH::QLKH()
{
    ifstream FileIn("Database/User/User.txt", ios_base::in);
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
            FileIn.ignore(1); // loai bo ky tu xuong dong
            User Us(CCCD, Name, Date(dd, mm, yy), PhoneNumber, Address, Gender);
            addUser(Us);
        }
    }
    FileIn.close();
}
Link_list<User> *QLKH::getLinkListUser()
{
    return &this->parUser;
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
bool QLKH::SearchUser(const User &user)
{
    Node<User> *tail=this->parUser.head;
    while (tail!=nullptr)
    {
        if(tail->data==user)
            return true;
        tail = tail->next;
    }
    return false;
}
void QLKH::addUser(User &b)
{
        if(this->SearchUser(b)==false) 
            this->parUser.Add(b);
}
void QLKH::Sort()
{
    this->parUser.Sort();
}
void QLKH::showUser()
{

    cout << "\t\t\t+=================================================================================================================================+" << endl;
    cout << "\t\t\t|                                                   ** DANH SACH NGUOI DUNG **                                                    |" << endl;
    cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;
    cout << "\t\t\t|      CCCD      |          HoVaTen         |    Ngay Sinh    |    So Dien Thoai   |            Dia Chi           |   Gioi Tinh   |" << endl;
    cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;
    this->parUser.Show();
    cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;


}


Node<User> *QLKH::SearchUser(const string & CCCD)
{
    User Us(CCCD,"Khong Co Nguoi Dung",Date(0,0,0),"", "",1);
    Node<User> *b = this->parUser.Search(Us);
    return b;
}

bool QLKH::SearchUserAll(User & Us)
{
    Link_list<User>* U=this->getLinkListUser();
    Node<User> *NU=U->head;
    while(NU!=nullptr)
    {
        if(NU->data.getCCCD()==Us.getCCCD())
            {
                if(NU->data.CheckUser(Us)==false)
                    return false;
            }
        NU=NU->next;
    }
    return true;
}