
// #include"QuanLy/Bank/QLNH.cpp"
// #include"Object/Bank/Bank.cpp"
#include"QuanLy/Bank/QLNH.cpp"
#include <fstream>
#include <conio.h>
#include<iostream>
using namespace std;


int main(){
 
    QLNH A;
    QLKH B;
    QLTK C;
    A.linkData(C,B);
    Link_list<User> US=B.getLinkListUser();
    while(US.head!=nullptr){
        US.head->data.showAccount();
        US.head=US.head->next;
    }
}   































 /*
    QLKH qlkh;
    QLTK qltk;
    Link_list<Account> AC=qltk.getLinkListAccount();
        // C.showAccount();
        // AC.Show();
        while(AC.head!=nullptr)
        {
            string numAC=AC.head->data.getNumAccount();
            string cccdChuTaiKhoan=AC.head->data.getCCCD();
            User US=qlkh.SearchUser(cccdChuTaiKhoan);
            User *p = &US;
            if(US.getName()=="Khong Co Nguoi Dung")
            {
                cout<<"Khong Tim Thay Chu So Huu Cua Tai Khoan: ";
                cout<<AC.head->data.getNumAccount();
                exit(0);
            }
        
            string idBankcuaAC=numAC.substr(0,3);
            Bank Ba=A.SearchBank(idBankcuaAC);
            Bank *p_b = &Ba;
            // Ba.Show();
            if(Ba.getNameBank()=="error")
            {
                cout<<"Khong Tim Thay Ngan Hang Cua Tai Khoan: ";
                cout<<AC.head->data.getNumAccount();
                exit(0);
            }
            
            p->addAccount(AC.head->data);
            p_b->addAccount(AC.head->data);
            p_b->addUser(US);
            AC.head=AC.head->next;
        }
        */
