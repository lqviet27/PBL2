#pragma once
#include "SignIn.h"
#include "../QuanLy/Account/QLTK.cpp"
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
    string rightpassword;
    Bank B;
    QLTK TK;
    cout << "\n\t\t\t\t\tEnter NumAccount: ";
    int count = 0;
    while (true)
    {
        cin>>numAccount;
        if (numAccount == "ADMIN" )
        {
            //Quan ly
            cout<<"Admin"<< endl;
            break;
        }
        string idB=numAccount.substr(0,3);
        B=X.SearchBank(idB);
        Account A = TK.SearchAccount(numAccount);
        B.addAccount(A);
        if(A.getNumAccout() == numAccount)
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
        cout<<pass;
        // Account acc = TK.SearchAccount(numAccount);
        Account acc = B.searchAcc(numAccount);
        if (pass == acc.getPassword())
        {
            cout << endl
                 << "\t\t\t\t\tBan da dang nhap thanh cong!";
            sleep(1);
            break;
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