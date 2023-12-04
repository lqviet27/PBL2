#pragma once
#include "Register.h"
#include <fstream>

Node<Account>* Register::DangKi(QLNH& banks,QLKH& users,QLTK& accounts)
{
    Node<Bank> *B=ChonNganHang(banks);
    // Node<User> *U=NhapThongTinKhachHang();
    // Node<Account> *A=NhapThongTinTaiKhoan();
    return nullptr;
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

void Register::NhapThongTinKhachHang()
{
    cout << "\t\t\t\t      *********************************************" << endl;
    cout << "\t\t\t\t                         DANG KI                     " << endl;
    cout << "\t\t\t\t      *********************************************" << endl;

    
}
