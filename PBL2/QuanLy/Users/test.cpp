
#include"QLKH.cpp"
#include <fstream>
#include <conio.h>
#include<iostream>
using namespace std;



int main(){

    QLKH a;
    a.showUser();
    User b;
    try{
        b = a.SearchUser("092111111115");
    }
    catch(string &msg){
        cout << msg << endl;
        return 0;
    }
    b.Show();
}