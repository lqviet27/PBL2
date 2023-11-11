#include "QLNH.h"
#include <fstream>
#include <conio.h>
QLNH::QLNH()
{
    ifstream FileIn("Database/Bank/Bank.txt", ios_base::in);
    if(FileIn.fail()){
        cout<<"Khong tim thay file Bank.txt! Import khong thanh cong"<<endl;
        // if (!kbhit())
        // {
        //     char key = getch();
        //     if (key == 27 || key == 'n' || key == 'N')
        //     {
        //         throw "Hay xem xet lai Database va khoi dong lai chuong trinh";
        //     }
        //     else if (key == 'Y' || key == 'y')
        //     {
                
        //     }
        // }
    }
    else{
        
        while(!FileIn.eof()){
            string id, name;
            char separator;
            getline(FileIn, id, '|');
            getline(FileIn, name, '\n');
            Bank A(name, id);
            addBank(A);
            // cout<<"Da them thanh cong ngan hang "<<name<<" vao Database!"<<endl;
        }
    }
    FileIn.close();
}
QLNH::QLNH(Link_list<Bank> parBank){
    this->parBank=parBank;
}
QLNH::QLNH(const QLNH& q){
    this->parBank=q.parBank;
}
QLNH::~QLNH()
{
    this->parBank.~Link_list();
}
void QLNH::addBank(const Bank& b){
    parBank.Add(b);
}


void QLNH::showBank(){
    cout<<"ID"<<"\t\t" <<"Ten Ngan Hang"<<endl;
    parBank.Show();
}

void QLNH::Show2()
{
    cout << "\t\t\t+========================================+" << endl;
    cout << "\t\t\t|       ** DANH SACH NGAN HANG **        |" << endl;
    cout << "\t\t\t+======+=================================+" << endl;
    cout << "\t\t\t|  ID  |        Ten ngan hang            | " << endl;
    cout << "\t\t\t+======+=================================+" << endl;
    this->parBank.Show();
    cout << "\t\t\t+======+=================================+" << endl;
}

Bank QLNH::SearchBank(const string& id){
    Bank bank("", id);
    Node<Bank> *b=this->parBank.Search(bank);
    if(b!=nullptr)
        return b->data;
    else 
        return Bank("error","-1");
}



