#pragma once
#include "SignIn.h"
#include <unistd.h>
void SignIn::DangNhapQuaSoLanQuyDinh()
{
    throw "Ban da dang nhap sai qua so lan quy dinh!!";
}

string SignIn::DangNhap(QLNH &X)
{
    cout << "\t\t\t\t      *********************************************" << endl;
    cout << "\t\t\t\t                       DANG NHAP                       " << endl;
    cout << "\t\t\t\t      *********************************************" << endl;
    string numAccount;
    string pass;
    
    int count = 0;
    while (true)
    {
        cout << "\n\t\t\t\t\tEnter NumAccount: ";
        cin >> numAccount;
        if (numAccount == "ADMIN" )
        {
            //Quan ly
            cout<<"Admin"<< endl;
        }
        string idB=numAccount.substr(0,3);
        
        Bank B=X.SearchBank(idB);
        if(B.getIdBank()!="-1")
            {
                cout<<"Co tai khoan nha thang l";
                break;
            }
            if(count==4)
            {
                DangNhapQuaSoLanQuyDinh();
                break;
            }
        cout << "\t\t\t\t\tKhong co tai khoan : " << numAccount <<endl;
        cout << "\t\t\t\t\tXin hay nhap lai so tai khoan: ";
        count++;
    }

    while(true)
    {
        string pass;
        cout << "\n\t\t\t\t\tEnter Password: ";
        cin>>pass;
        if (1)
        {

        }
        else
        {
            if (count == 5)
            {
                DangNhapQuaSoLanQuyDinh();
            }
            cout << endl
                 << "\t\t\t\t\tBan nhap sai password! Xin hay nhap lai password: ";
           
        }
    }
    return numAccount;
}