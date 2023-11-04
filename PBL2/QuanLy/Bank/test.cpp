#include <windows.h>
#include"QLNH.cpp"
#include <fstream>
#include <conio.h>
#include<iostream>
using namespace std;

void TextColor(int x)
{
     HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(color, x);
}


int main(){
    // ifstream FileIn("../../Database/Bank/Bank.txt", ios_base::in);
    // if(FileIn.fail()){
    //     cout<<"Khong tim thay file Bank.txt! Import khong thanh cong"<<endl;
    // }
    // else{
    //     int count=0;
    //     while(!FileIn.eof()){
    //         string id, name;
    //         char separator;
    //         getline(FileIn, id, '|');
    //         getline(FileIn, name, '|');
    //         cout<<id<<" "<<name;
    //     }
    //     FileIn.close();
    // }
    TextColor(14);
    QLNH a;
    // a.showBank();
    a.Show2();
    cout<<endl;
    Bank b=a.SearchBank("003");
    b.Show();


   
    
   
}