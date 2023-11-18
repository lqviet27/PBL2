
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
    // Link_list<Bank> U=A.getLinkListParBank();
    //         while(U.head!=nullptr){
    //            U.head->data.getLinkListUser();
    //          U.head=U.head->next;
    //         }
    User u=User("1", "1", Date(0,0,0), "1", "1", true);
    B.addUser(u);
    B.showUser();
}