
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