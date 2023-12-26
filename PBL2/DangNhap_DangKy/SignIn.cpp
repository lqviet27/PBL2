#pragma once
#include "SignIn.h"
#include "../QuanLy/Account/QLTK.cpp"
#include <unistd.h>

void SignIn::DangNhapQuaSoLanQuyDinh()
{
    cout<<"Ban da dang nhap sai qua so lan quy dinh!!"<<endl;
}

Node<Account>* SignIn::DangNhap(QLNH &X,QLKH &users,QLTK &acccouts)
{
    
    cout << "\t\t\t\t      *********************************************" << endl;
    cout << "\t\t\t\t      *                  DANG NHAP                *" << endl;
    cout << "\t\t\t\t      *********************************************" << endl;
    string numAccount;
    string pass;
    string rightpassword;
    Node<Bank> *B;
    Node<Account> *nodeAC;
    cout << "\n\t\t\t\t\tNhap So Tai Khoan: ";
    int count = 0;
    while (true)
    {
        cin>>numAccount;
        if (numAccount == "ADMIN" )
        {
            cout << "\t\t\t\t\tNhap Mat Khau: ";
            cin >> pass;
            if (pass == "ADMIN")
            {
                cout << "\t\t\t\t\tDang Nhap Thanh Cong Voi Tu Cach Admin!!!" << endl;
                sleep(1);
                system("cls");
                admin(X,users,acccouts);
                return nullptr;
            }
            else
            {
                cout << "\t\t\t\t\tMat Khau Khong Dung!!!" << endl;
                count++;
                if (count == 5)
                {
                    DangNhapQuaSoLanQuyDinh();
                    break;
                }
                cout << "\t\t\t\t\tXin Hay Nhap Lai Mat Khau: ";
            }
        }
        string idB=numAccount.substr(0,3);
        B=X.SearchBank(idB);
        if(B==nullptr)
            {
                cout<<"Khong Ton Tai Tai Khoan!!!"<< endl;
            }
            else 
            {
                Link_list<Account> *A=B->data.getLinkListAccount();
                Account temp("",numAccount,"",false,0);
                nodeAC=A->Search(temp);
                if(nodeAC==nullptr)
                    cout<<"\t\t\t\t\tKhong Ton Tai Tai Khoan!!!"<< endl;
                else 
                    break;
            }
        if(count==4)
            {
              DangNhapQuaSoLanQuyDinh();
              system("pause");
              return nullptr;
            }
        cout << "\t\t\t\t\tXin Hay Nhap Lai So Tai Khoan: ";
        count++;
    }
    count=0;
    while(true)
    {
        string pass;
        cout << "\n\t\t\t\t\tNhap Mat Khau: ";
        cin>>pass;
        
        if(pass==nodeAC->data.getPassword())
        {
            cout<<"\t\t\t\t\tDanh Nhap Thanh Cong!!!"<<endl;
            return nodeAC;
        }
        count++;
        if (count == 5)
        {
            DangNhapQuaSoLanQuyDinh();
            return nullptr;
        }
            cout << "\t\t\t\t\tXin Hay Nhap Lai Mat Khau: ";
    }
    
}