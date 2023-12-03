
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
    // A.linkData(C,B);
    // A.showBank();
    A.showBank();
    A.Sort();
    cout<<"Sau khi sap xep:"<<endl;
    A.showBank();
    cout<<endl;
    B.showUser();
    B.Sort();
    cout<<"Sau khi sap xep:"<<endl;
    B.showUser();
    cout<<endl;
    C.showAccount();
    C.Sort();
    cout<<"Sau khi sap xep:"<<endl;
    C.showAccount();

    // B.showUser();
    // C.showAccount();
    /*
    Link_list<Bank> *U=A.getLinkListParBank();
    Node<Bank> *Une=U->head;
    while(Une!=nullptr){
      cout<<Une->data.getNameBank()<<endl;
      Link_list<User> *x =Une->data.getLinkListUser();
      Node<User> *tail=x->head;
      while(tail!=nullptr)
        {
          cout<<"Khach hang "<<tail->data.getName()<<endl;
          Link_list<Account> *y =tail->data.getUserAccount(); 
          Node<Account> *tail2=y->head;
          
          while(tail2!=nullptr){
            
            tail2->Show();
            tail2=tail2->next;
          }
          tail=tail->next;
        }
      // cout<<"Ngan hang "<<Une->data.getNameBank()<<" co cac tai khoan:"<<endl;
      // Link_list<Account> *x = Une->data.getLinkListAccount();
      // while(x->head!=nullptr){
      //   x->head->Show();
      //   x->head=x->head->next;
      // }
      Une=Une->next;
    }
    */
    /*
    Link_list<Bank> *U=A.getLinkListParBank();
    Node<Bank> *Une=U->head;
    while(Une!=nullptr){
      cout<<Une->data.getNameBank()<<endl;
          Link_list<Account> *y =Une->data.getLinkListAccount(); 
          Node<Account> *tail2=y->head;
          while(tail2!=nullptr){
            tail2->Show();
            tail2->data.setAmount(2000);
            tail2=tail2->next;
          }
      Une=Une->next;
    }
    cout<<"Sau khi cap nhat:"<<endl;
    Link_list<Bank> *U2=A.getLinkListParBank();
    Node<Bank> *Une2=U->head;
    while(Une2!=nullptr){
      cout<<Une2->data.getNameBank()<<endl;
          Link_list<Account> *y2 =Une2->data.getLinkListAccount(); 
          Node<Account> *tail2=y2->head;
          while(tail2!=nullptr){
            tail2->Show();
            tail2->data.setAmount(2000);
            tail2=tail2->next;
          }
      Une2=Une2->next;
    }
    */
   /*
    Link_list<Bank> *U=A.getLinkListParBank();
    Node<Bank> *Une=U->head;
    while(Une!=nullptr){
      Link_list<User> *x =Une->data.getLinkListUser();
      Node<User> *tail=x->head;
      while(tail!=nullptr)
        {
          
          tail->data.setName("le quoc viet");
          tail->data.Show();
          tail=tail->next;
        }
      Une=Une->next;
    }
    cout<<"Sau khi cap nhat :"<<endl;
    Link_list<User> *U2=B.getLinkListUser();
    Node<User> *Une2=U2->head;
    while(Une2!=nullptr){
      Une2->data.Show();
      Une2=Une2->next;
    }
    */
    /*
    cout<<"Sau khi cap nhat:"<<endl;
    Link_list<User> *x =B.getLinkListUser();
    Node<User> *tail=x->head;
    while(tail!=nullptr)
      {
        cout<<"Khach hang "<<tail->data.getName()<<endl;
        Link_list<Account> *y =tail->data.getUserAccount(); 
        Node<Account> *tail2=y->head;
        while(tail2!=nullptr){
          tail2->Show();
          tail2=tail2->next;
        }
        tail=tail->next;
      }
      */
    
   
    // User u=User("1", "1", Date(0,0,0), "1", "1", true);
    // B.addUser(u);
    // B.showUser();
}
