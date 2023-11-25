
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
<<<<<<< HEAD
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
=======
    Link_list<Bank> *U=A.getLinkListParBank();
    Node<Bank> *Une=U->head;
            while(Une!=nullptr){
              Link_list<User> *x =Une->data.getLinkListUser();
              Node<User> *tail=x->head;
              cout<<Une->data.getNameBank()<<endl;
              while(tail!=nullptr)
                {
                   
                  tail->Show();
                  tail->data.setAddress("back khoa vs dut");
                  tail=tail->next;
                }
              
              Une=Une->next;
            }

             cout<<endl<<1<<endl;
             

             Link_list<Bank> *g=A.getLinkListParBank();
             g->Show();
             while(g->head!=nullptr){
              
              Link_list<User> *xx =g->head->data.getLinkListUser();
              cout<<g->head->data.getNameBank()<<endl;
              while(xx->head!=nullptr)
                {
                  xx->head->Show();
                 // x->head->data.setAddress("back khoa vs dut");
                  xx->head=xx->head->next;
                }
              g->head=g->head->next;
            }
    // User u=User("1", "1", Date(0,0,0), "1", "1", true);
    // B.addUser(u);
    // B.showUser();
}
>>>>>>> 35cbc2f069fb67a57d881169cb619d824c5e6115
