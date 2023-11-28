#include"../QuanLy/Account/QLTK.cpp"
#include"../QuanLy/Bank/QLNH.cpp"
#include"../QuanLy/Users/QLKH.cpp"
#include"../Record_Giaodich/Record_Nap.cpp"
#include<iostream>
#include<limits> 
#include<fstream>
using namespace std;
class GiaoDich{
    public:
        static void NapTien(Node<Account>* AC,QLNH &banks,QLKH &users)
        {      
            
            double money;
            cout<<"Nhap So Tien Can Nap Vao Tai Khoan: ";
               // while(cin>>money)
               // {
               //      cout<<endl;
               //      if(money>0.0 && )
               //           break;
               //      else {

               //           cout<<"So tien Khong Hop Le!!!"<<endl;
               //           cout<<"Vui Long Nhap Lai: ";
               //           cin.clear();
               //           cin.ignore(1000, '\n');
               //      }
               // }
                while (!(cin >> money) || (cin.peek() != '\n')) {
                         cout << endl;
                         cout << "So tien khong hop le! Vui long nhap lai: ";
                         cin.clear();
                         cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
            AC->data.setAmount(money);

            bool success=0;
            Link_list<Bank> *B=banks.getLinkListParBank();
            Node<Bank>* NB=B->head;
            while(NB!=nullptr)
            {
               Link_list<User> *U=NB->data.getLinkListUser();
               Node<User> *NU=U->head;
               while(NU!=nullptr)
               {    
                    Node<Account> *A=NU->data.getUserAccount()->Search(AC->data);
                    if(A!=nullptr)
                    {
                         A->data.setAmount(money);
                         success=1;
                         break;
                    }
                    NU=NU->next;
               }
               if(success==1)
                    break;
               NB=NB->next;
            }

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

               Record_Nap R(AC->data.getNumAccount(),NB->data.getNameBank(),money);
               R.RecordtoFile();
        }
        static void RutTien(Node<Account>*)
        {
          //   double money;
          //   cout<<"Nhap So Tien Can Nap Vao Tai Khoan: ";
          //      while(cin>>money)
          //      {
          //           cout<<endl;
          //           if(money>0)
          //                break;
          //           cout<<"So tien Khong Hop Le!!!"<<endl;
          //           cout<<"Vui Long Nhap Lai: ";
          //      }
          //   AC->data.setAmount(money);
        }
        static void TraCuuLichSuGiaoDich(Node<Account>* AC)
        {
               
               string Path="DataBase/GiaoDich/" + AC->data.getNumAccount() + ".txt";
               ifstream file(Path,ios::in);
               cout << "\t\t\t+===========================================================================+" << endl;
               cout << "\t\t\t|                          ** LICH SU GIAO DICH **                          |" << endl;
               cout << "\t\t\t+==================+============+=================+=========================+" << endl;
               cout << "\t\t\t|    IDAccount     |  NameBank  |     Amount      |           Time          |" << endl;
               cout << "\t\t\t+==================+============+=================+=========================+" << endl;
               string line;
               while(getline(file,line))
               {
                    string IDAccount,NameBank,Amount,Time;
                    stringstream ss(line);
                    getline(ss,IDAccount,'|');
                    getline(ss,NameBank,'|');
                    getline(ss,Amount,'|');
                    getline(ss,Time,'|');
                    cout << "\t\t\t| " << setw(17) << left << IDAccount << "| " << setw(11) << left << NameBank << "| " <<"+ "<< setw(10) << left << Amount <<" VND"<< "| " << setw(10) << left << Time << "|" << endl;
               }

        }
        static void ChuyenTien(Node<Account>*);
};

