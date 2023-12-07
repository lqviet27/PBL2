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
    cout << "\t\t\t\t                         DANG KI                     " << endl;
    cout << "\t\t\t\t      *********************************************" << endl;
    while(1) 
    {   
        banks.showBank();
        cout<< "\t\t\t\t  Nhap Id Ngan Hang Ban Muon Tao Tai Khoan(Nhap '-1' De Quay Lai): " << endl;
        int idb=choose(-1,banks.getCountBank());
        if(idb==-1)
            return nullptr;
        string IDB=to_string(idb);
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
        Node<Bank> *B=banks.SearchBank(IDB);
        return B;
    }
}

void Register::NhapThongTinKhachHang(Node<Bank> *NB,QLKH &users,QLTK &accounts)
{
    cout << "\t\t\t\t      *********************************************" << endl;
    cout << "\t\t\t\t                         DANG KI                     " << endl;
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
        cout<<"Thong Tin Khach Hang Khong Hop Le!!!"<<endl;
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
        cout<<"Nhap So Tai Khoan Ban Muon Tao(Gom 7 Chu So Lien Tiep):"<<endl;
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
                    cout<<"Nhap Loai Tai Khoan Can Tao:"<<endl;
                    cout<<"1: Tai Khoan Tiet Kiem"<<endl;
                    cout<<"2: Tai Khoan Ghi No"<<endl;
                    int c=choose(1,2);
                    typeAC=(c==1)? 0: 1;
                    string password;
                    cout<<"Nhap Mat Khau: ";
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
                    users.SearchUser(user.getCCCD())->data.addAccount(ACC);

                    accounts.addAccount(ACC);
                    cout<<"Ban Da Tao Xong Tai Khoan! So Tai Khoan Cua Ban La: "<<ACC.getNumAccount()<<endl;
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
