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

Node<Bank>* QLNH::SearchBank(const string& id){
    Bank bank("", id);
    Node<Bank> *b=this->parBank.Search(bank);
    return b;
}

Link_list<Bank> QLNH::getLinkListParBank()
{
    return this->parBank;
}

void QLNH::linkData(QLTK& qltk, QLKH& qlkh){
        Link_list<Account> AC=qltk.getLinkListAccount();
        while(AC.head!=nullptr)
        {
            string numAC=AC.head->data.getNumAccount();
            string cccdChuTaiKhoan=AC.head->data.getCCCD();
            User US=qlkh.SearchUser(cccdChuTaiKhoan);
            if(US.getName()=="Khong Co Nguoi Dung")
            {
                cout<<"Khong Tim Thay Chu So Huu Cua Tai Khoan: ";
                cout<<AC.head->data.getNumAccount();
                exit(0);
            }
        
            string idBankcuaAC=numAC.substr(0,3);
            Node<Bank> *Ba=this->SearchBank(idBankcuaAC);

            if(Ba==nullptr)
            {
                cout<<"Khong Tim Thay Ngan Hang Cua Tai Khoan: ";
                cout<<AC.head->data.getNumAccount();
                exit(0);
            }
            US.addAccount(AC.head->data);
            Ba->data.addAccount(AC.head->data);
            Ba->data.addUser(US);

            AC.head=AC.head->next;
        }


}

