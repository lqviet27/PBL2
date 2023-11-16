
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
    // while(US.head!=nullptr){
    //     US.head->data.showAccount();
    //     US.head=US.head->next;
    // }
    US.Show();
}