#include"../QuanLy/Account/QLTK.cpp"
#include"../QuanLy/Bank/QLNH.cpp"
#include"../QuanLy/Users/QLKH.cpp"
#include"../Record_Giaodich/Record_Nap.cpp"
#include"../Record_Giaodich/Record_Rut.cpp"

#include<iostream>
#include<limits> 
#include<fstream>
using namespace std;
class GiaoDich{
    public:
        static void NapTien(Node<Account>* AC,QLNH &banks,QLKH &users)
        {      
            
            long long money;
            cout<<"Nhap So Tien Can Nap Vao Tai Khoan: ";
                while (!(cin >> money) || (cin.peek() != '\n')) {
                         cout << endl;
                         cout << "So tien khong hop le! Vui long nhap lai: ";
                         cin.clear();
                         cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
               AC->data.setAmount(money);

               Link_list<User> *X=users.getLinkListUser();
               Node<User> *NX=X->head;
               while(NX!=nullptr)
               {
                    Node<Account> *Y=NX->data.getUserAccount()->Search(AC->data);
                    if(Y!=nullptr)
                    {
                         Y->data.setAmount(money);
                         break;
                    }
                    NX=NX->next;
               }
               string idBank=AC->data.getNumAccount().substr(0,3);
               Record_Nap R(AC->data.getNumAccount(),banks.SearchBank(idBank)->data.getNameBank(),money);
               R.RecordtoFile();
        }
        static void RutTien(Node<Account>* AC,QLNH &banks,QLKH &users)
        {
               long long money;
               cout<<"Nhap So Tien Can Rut Vao Tai Khoan: ";
               while (!(cin >> money) || (cin.peek() != '\n')) {
                         cout << endl;
                         cout << "So tien khong hop le! Vui long nhap lai: ";
                         cin.clear();
                         cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
               if(AC->data.getAmount()-money > 0)
               AC->data.setAmount(-money);
               else {
                    cout<<"Khong Du Tien Trong Tai Khoan!!!"<<endl;
               }

               Link_list<User> *X=users.getLinkListUser();
               Node<User> *NX=X->head;
               while(NX!=nullptr)
               {
                    Node<Account> *Y=NX->data.getUserAccount()->Search(AC->data);
                    if(Y!=nullptr)
                    {
                         if(Y->data.getAmount()-money > 0)
                         Y->data.setAmount(-money);
                         else {
                              cout<<"Khong Du Tien Trong Tai Khoan!!!"<<endl;
                         }
                         break;
                    }
                    NX=NX->next;
               }
               string idBank=AC->data.getNumAccount().substr(0,3);
               Record_Rut R(AC->data.getNumAccount(),banks.SearchBank(idBank)->data.getNameBank(),-money);
               R.RecordtoFile();
        }
        static void TraCuuLichSuGiaoDich(Node<Account>* AC)
        {
               
               string Path="DataBase/GiaoDich/" + AC->data.getNumAccount() + ".txt";
               ifstream file(Path,ios::in);
               cout << "\t\t\t+===========================================================================================================+" << endl;
               cout << "\t\t\t|                                           ** LICH SU GIAO DICH **                                         |" << endl;
               cout << "\t\t\t+============+==================+==================+============+=================+=========================+" << endl;
               cout << "\t\t\t|    Type    | IDSourceAccount  |   IDDesAccount   |  NameBank  |     Amount      |           Time          |" << endl;
               cout << "\t\t\t+============+==================+==================+============+=================+=========================+" << endl;
               string line;
               while(getline(file,line))
               {
                    string Type,IDSourceAccount,IDDesAccount,NameBank,Amount,Time;
                    stringstream ss(line);
                    getline(ss,Type,'|');
                    getline(ss,IDSourceAccount,'|');
                    getline(ss,IDDesAccount,'|');
                    getline(ss,NameBank,'|');
                    getline(ss,Amount,'|');
                    getline(ss,Time,'|');
                    cout << "\t\t\t| " << setw(11) << left << Type << "| " << setw(17) << left << IDSourceAccount << "| " << setw(17) << left << IDDesAccount << "| " << setw(11) << left << NameBank << "| " <<"+ "<< setw(10) << left << Amount <<" VND"<< "| " << setw(10) << left << Time << "|" << endl;
               }

        }
        
};

