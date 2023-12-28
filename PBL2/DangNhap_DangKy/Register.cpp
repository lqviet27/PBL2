#pragma once
#include "Register.h"
#include <fstream>

void Register::DangKi(QLNH& banks,QLKH& users,QLTK& accounts)
{
    Node<Bank> *B=ChonNganHang(banks);
    system("cls");
    if(B==nullptr)
        return ;
    NhapThongTinKhachHang(B,users,accounts);
    return ;
}

Node<Bank>* Register::ChonNganHang(QLNH& banks)
{
    cout << "\t\t\t\t      *********************************************" << endl;
    cout << "\t\t\t\t      *                   DANG KI                 *" << endl;
    cout << "\t\t\t\t      *********************************************" << endl;
    while(1) 
    {   
        banks.showBank();
        cout<< "\t\t\t\t  Nhap Id Ngan Hang Ban Muon Tao Tai Khoan(Nhap '-1' De Quay Lai): " << endl;
        string IDB;
        cin>>IDB;
        if(IDB=="-1")
            return nullptr;
        if(IDB.size()>3)
            {
                cout<<"Khong Ton Tai Id Ngan Hang Nay!!!";
                system("Pause");
                system("cls");
                continue;
            }
        switch(IDB.size())
        {
            case 1:
                {
                    IDB="00"+IDB;
                    break;
                }
            case 2:
                {
                    IDB="0"+IDB;
                    break;
                }
        }
        Node<Bank> *NB=banks.SearchBank(IDB);
        if(NB==nullptr) 
        {
            cout<<"Khong Ton Tai Ngan Hang!!!";
            system("Pause");
            system("cls");
            continue;
        }
        return NB;
    }
}

void Register::NhapThongTinKhachHang(Node<Bank> *NB,QLKH &users,QLTK &accounts)
{
    cout << "\t\t\t\t      *********************************************" << endl;
    cout << "\t\t\t\t      *                  DANG KI                  *" << endl;
    cout << "\t\t\t\t      *********************************************" << endl;
    User user;
    int cnt=0;
    while(1)
    {
    cin>>user;
    if(user.getCCCD()=="Exit")
        return ;
    if(users.SearchUserAll(user)==false) {
        cnt++;
        cout<<"Thong Tin CCCD Khong Dong Bo Thong Tin He Thong!!!"<<endl;
    }
    else break;
    if(cnt==5)
        return ;
    cout<<"Moi Ban Nhap Lai Thong Tin!!!(Nhap Sai Qua 5 lan se Thoat!)"<<endl;
    system("Pause");
    system("cls");
    }
    system("cls");
    string numAC;
    while(1)
    {
        cout<<"\t\t\tNhap So Tai Khoan Ban Muon Tao(Gom 7 Chu So Lien Tiep):"<<endl;
        cin>>numAC;
            
        if (numAC.length() == 7)
        {
            bool isAllDigits = true;
            for (char c : numAC) {
                if (!isdigit(c)) {
                    isAllDigits = false;
                    break;
                }
            }

            if (isAllDigits) {
                numAC=NB->data.getIdBank()+numAC;
                if(accounts.SearchAccount(numAC)!=nullptr) 
                    {
                        cout<<"So Tai Khoan Da Duoc Su Dung!!!"<<endl;
                        system("Pause");   
                    }
                else 
                {   
                    bool typeAC;      
                    cout<<"\t\t\tNhap Loai Tai Khoan Can Tao:"<<endl;
                    cout<<"\t\t\t1: Tai Khoan Tiet Kiem"<<endl;
                    cout<<"\t\t\t2: Tai Khoan Thanh Toan"<<endl;
                    int c=choose(1,2);
                    typeAC=(c==1)? 0: 1;
                    string password;
                    cout<<"\t\t\tNhap Mat Khau: ";
                    cin>>password;
                    Account ACC(user.getCCCD(),numAC,password,typeAC,0);
                    
                    if(NB->data.searchUser(user.getCCCD())==nullptr)
                    {
                        user.addAccount(ACC);
                        NB->data.addAccount(ACC);
                        NB->data.addUser(user);
                    }
                    else{
                        NB->data.addAccount(ACC);
                        NB->data.searchUser(user.getCCCD())->data.addAccount(ACC);
                    }

                    
                    users.addUser(user);
                    if(user.getUserAccount()->head==nullptr)
                        users.SearchUser(user.getCCCD())->data.addAccount(ACC);
                        
                    accounts.addAccount(ACC);
                    cout<<"\t\t\tBan Da Tao Xong Tai Khoan! So Tai Khoan Cua Ban La: "<<ACC.getNumAccount()<<endl;
                    system("pause");
                    return ;
                }
            }
            else {
                cout << "Ban Phai Nhap Chu So!!!" <<endl;
            }
        }
        else {
            cout << "Ban Phai Nhap Dung 7 Chu So!!!" <<endl;
        }
    }
 
}
