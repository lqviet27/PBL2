#include <windows.h>
#include"QLTK.cpp"
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
   
    /*
    ifstream FileIn("../../Database/Account/Account.txt", ios_base::in);
    if(FileIn.fail()){
        cout<<"Khong tim thay file Bank.txt! Import khong thanh cong"<<endl;
    }
    else{
        
        while(!FileIn.eof()){
            string numAccount, password;
            long long amount;
            bool typeAccount;
            char separator;
            getline(FileIn, numAccount, '|');
            FileIn >> amount >> separator;
            FileIn >> typeAccount >> separator;
            getline(FileIn, password, '\n');
            // Account A(numAccount, password, typeAccount, amount);
            cout<<numAccount<<" "<<amount<<" "<<typeAccount<<" "<<password<<endl;
            
            // cout<<"Da them thanh cong ngan hang "<<numAccount<<" vao Database!"<<endl;
        }
        FileIn.close();
    }
    */
    QLTK a;
    a.showAccount();
    Account b ;
    cout<<endl;
    cout<< a.SearchAccount("0013333333").getCCCD()<<endl;;
    //! bi loi search account ra nhung bi sai o so du va laoi tai khoan
    //b.Show();
    cout<<1;
}