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
    string rightpassword;
    cout << "\n\t\t\t\t\tEnter NumAccount: ";
    int count = 0;
    while (true)
    {
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
        cout << "\t\t\t\t\tKhong co tai khoan : " << numAccount << "! Xin hay nhap lai so tai khoan: ";
        count++;
    }
    // count = 0;
    // cout << "\n\t\t\t\t\tEnter Password: ";
    // char c = 0;
    // char *x = new char[30];
    // int i = 0;
    // while (1)
    // {
    //     while (1)
    //     {
    //         c = getch();
    //         if (c == 13 || c == 8)
    //         {
    //             x[i] = '\0';
    //             break;
    //         }
    //         else
    //         {
    //             x[i++] = c;
    //             cout << "*";
    //         }
    //     }
    //     x[i] = '\0';
    //     string a(x);
    //     if (a == rightpassword)
    //     {
    //         cout << endl
    //              << "\t\t\t\t\tBan da dang nhap thanh cong!";
    //         sleep(1);
    //         delete[] x;
    //         if (numAccount > 0)
    //         {
    //             menuMain1(numAccount);
    //         }
    //         else
    //             menuMain2(numAccount);
    //         break;
    //     }
    //     else
    //     {
    //         if (count == 5)
    //         {
    //             DangNhapQuaSoLanQuyDinh();
    //         }
    //         cout << endl
    //              << "\t\t\t\t\tBan nhap sai password! Xin hay nhap lai password: ";
    //         delete[] x;
    //         x = new char[30];
    //         i = 0;
    //         count++;
    //     }
    // }
    return numAccount;
}