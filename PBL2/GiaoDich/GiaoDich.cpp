#include"../QuanLy/Account/QLTK.cpp"
#include"../QuanLy/Bank/QLNH.cpp"
#include"../QuanLy/Users/QLKH.cpp"
#include"../Record_Giaodich/Record_Nap.cpp"
#include"../Record_Giaodich/Record_Rut.cpp"
#include"../Record_Giaodich/Record_Chuyen.cpp"

#include<iostream>
#include<limits> 
#include<fstream>
using namespace std;
class GiaoDich{
    public:
        static void NapTien(Node<Account>* AC,QLNH &banks,QLKH &users)
        {      
            
            long long money;
            cout<<"Nhap So Tien Can Nap Vao Tai Khoan((Nhap '-1' De Quay Lai)): ";
                while (!(cin >> money) || (cin.peek() != '\n')) {
                         if(money==-1)
                              return ;
                         cout << endl;
                         cout << "So tien khong hop le! Vui long nhap lai((Nhap '-1' De Quay Lai)): ";
                         cin.clear();
                         cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
               AC->data.setAmount(money);

               Link_list<Bank> *B=banks.getLinkListParBank();
               Node<Bank> *NB=B->head;
               bool success=0;
               while(NB!=nullptr)
               {
                    Link_list<User> *U=NB->data.getLinkListUser();
                    Node<User> *NU=U->head;
                     while (NU!=nullptr)
                     {

                         if(NU->data.getCCCD()==AC->data.getCCCD())
                         {
                              NU->data.getUserAccount()->Search(AC->data)->data.setAmount(money);
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
               string idBank=AC->data.getNumAccount().substr(0,3);
               Record_Nap R(AC->data.getNumAccount(),banks.SearchBank(idBank)->data.getNameBank(),money);
               R.RecordtoFile();
        }
        static void RutTien(Node<Account>* AC,QLNH &banks,QLKH &users)
        {
               long long money;
               Start:
               cout<<"Nhap So Tien Can Rut Vao Tai Khoan(Nhap '-1' De Quay Lai): ";
               if(money==-1)
                    return;
               while (!(cin >> money) || (cin.peek() != '\n')) {
                         cout << endl;
                         cout << "So tien khong hop le! Vui long nhap lai(Nhap '-1' De Quay Lai): ";
                         cin.clear();
                         cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
               if(AC->data.getAmount()-money > 0)
               AC->data.setAmount(-money);
               else {
                    cout<<"Khong Du Tien Trong Tai Khoan!!!"<<endl;
                    cout<<"Vui Long Nhap Lai So Tien Can Rut!!!"<<endl;
                    goto Start;
               }

               Link_list<Bank> *B=banks.getLinkListParBank();
               Node<Bank> *NB=B->head;
               bool success=0;
               while(NB!=nullptr)
               {
                    Link_list<User> *U=NB->data.getLinkListUser();
                    Node<User> *NU=U->head;
                     while (NU!=nullptr)
                     {

                         if(NU->data.getCCCD()==AC->data.getCCCD())
                         {
                              NU->data.getUserAccount()->Search(AC->data)->data.setAmount(-money);
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
                         if(Y->data.getAmount()-money > 0)
                         Y->data.setAmount(-money);
                         break;
                    }
                    NX=NX->next;
               }
               string idBank=AC->data.getNumAccount().substr(0,3);
               Record_Rut R(AC->data.getNumAccount(),banks.SearchBank(idBank)->data.getNameBank(),-money);
               R.RecordtoFile();
        }

        static void ChuyenTien(Node<Account>* AC,Node<Account>* NA,QLNH &banks,QLKH &users)
        {
               

               long long money;
               Start:
               cout<<"Nhap So Tien Can Chuyen(Nhap '-1' De Quay Lai): ";
               if(money==-1)
                    return;
               while (!(cin >> money) || (cin.peek() != '\n')) {
                         if(money==-1)
                               return;
                         cout<<endl;
                         cout << "So tien khong hop le! Vui long nhap lai(Nhap '-1' De Quay Lai): ";
                         cin.clear();
                         cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
               if(AC->data.getAmount()-money >= 0)
               AC->data.setAmount(-money);
               else {
                    cout<<"Khong Du Tien Trong Tai Khoan!!!"<<endl;
                    cout<<"Vui Long Nhap Lai So Tien Can Chuyen!!!"<<endl;
                    goto Start;
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
                         break;
                    }
                    NX=NX->next;
               }

               
               //int cnt=0;
               // Link_list<Bank> *BANK=banks.getLinkListParBank();
               // Node<Bank> *NBANK=BANK->head;
               // while(NBANK!=nullptr)
               // {
               //      Link_list<User> *USER=NBANK->data.getLinkListUser();
               //      Node<User> *NUSER=USER->head;
               //      while(NUSER!=nullptr)
               //      {
               //           Link_list<Account> *ACCOUNT=NUSER->data.getUserAccount();
               //           Node<Account> *NACCOUNT=ACCOUNT->head;
               //           while(NACCOUNT!=nullptr)
               //           {
               //                if(NACCOUNT->data==AC->data)
               //                     {
               //                          NACCOUNT->data.setAmount(-money);
               //                          cnt++;
               //                     }
               //                if(NACCOUNT->data==NA->data)
               //                     {
               //                          NACCOUNT->data.setAmount(money);
               //                          cnt++;
               //                     }
               //                if(cnt==2)
               //                     break;
               //                NACCOUNT=NACCOUNT->next;
               //           }
               //           if(cnt==2)
               //                break;    
               //           NUSER=NUSER->next;                     
               //      }
               //      if(cnt==2)
               //           break;
               //      NBANK=NBANK->next;
               // }


               Bank NH=banks.SearchBank(AC->data.getNumAccount().substr(0,3))->data;
               Bank NHDich=banks.SearchBank(NA->data.getNumAccount().substr(0,3))->data;
               Record_Chuyen Chuyen(AC->data.getNumAccount(),NA->data.getNumAccount(),NH.getNameBank(),-money);
               Record_Chuyen ChuyenDich(NA->data.getNumAccount(),AC->data.getNumAccount(),NHDich.getNameBank(),money);
               Chuyen.RecordtoFile();
               ChuyenDich.RecordtoFile();
        }


        static void TraCuuSoDu(Node<Account>* AC,QLNH &bank)
          {
               
               string type= (AC->data.getTypeAccount()==0) ? "Tiet Kiem" : "Ghi no" ;
               string nameB=bank.SearchBank(AC->data.getNumAccount().substr(0,3))->data.getNameBank();
               cout << "\t\t\t+==============================================================+" << endl;
               cout << "\t\t\t|                     ** TRA CUU SO DU **                      |" << endl;
               cout << "\t\t\t+============+==================+============+=================+" << endl;
               cout << "\t\t\t|    Type    | IDSourceAccount  |  NameBank  |     Amount      |" << endl;
               cout << "\t\t\t+============+==================+============+=================+" << endl;
               cout << "\t\t\t|   "<<type<<"   |  "<<AC->data.getNumAccount()<<"   |  "<<nameB<<"  |     "<<AC->data.getAmount()<<"      |" << endl;
               system("pause");
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
               system("pause");
        }
        
};

