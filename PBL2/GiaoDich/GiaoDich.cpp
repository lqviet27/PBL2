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
          static void NapTien(Node<Account>* AC,QLNH &banks,QLKH &users,QLTK &accounts) 
          {
            
            long long money;
            cout<<"Nhap So Tien Can Nap Vao Tai Khoan((Nhap '-1' De Quay Lai)): ";
               while (true) {                  
                    cin >> money;

                    if (money == -1) {
                         return;
                    }

                    if (!cin.fail() && cin.peek() == '\n' && money >= 0) {
                         break;
                    }

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "So tien khong hop le! Vui long nhap lai((Nhap '-1' De Quay Lai)):" << endl;
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
                              Node<Account> *NAUSER=NU->data.getUserAccount()->head;
                              while(NAUSER!=nullptr)
                              {
                                   if(NAUSER->data==AC->data)
                                   {
                                        NAUSER->data.setAmount(money);
                                   }
                                   NAUSER=NAUSER->next;
                              }
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
               
               accounts.SearchAccount(AC->data.getNumAccount())->data.setAmount(money);
               
               string idBank=AC->data.getNumAccount().substr(0,3);
               Record_Nap R(AC->data.getNumAccount(),banks.SearchBank(idBank)->data.getNameBank(),money);
               R.RecordtoFile();
               cout<<"BAN DA THUC HIEN NAP TIEN THANH CONG!!!"<<endl;
               system("pause");
          }
          static void RutTien(Node<Account>* AC,QLNH &banks,QLKH &users,QLTK &accounts)
          {
               long long money;
               Start:
               cout<<"Nhap So Tien Can Rut Vao Tai Khoan(Nhap '-1' De Quay Lai): ";
               while (true) {                  
                    cin >> money;
                    if (money == -1) {
                         return;
                    }
                    if (!cin.fail() && cin.peek() == '\n' && money >= 0) {
                         break;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "So tien khong hop le! Vui long nhap lai((Nhap '-1' De Quay Lai)):" << endl;
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
                              Node<Account> *NAUSER=NU->data.getUserAccount()->head;
                              while(NAUSER!=nullptr)
                              {
                                   if(NAUSER->data==AC->data)
                                   {
                                        NAUSER->data.setAmount(-money);
                                   }
                                   NAUSER=NAUSER->next;
                              }
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

               accounts.SearchAccount(AC->data.getNumAccount())->data.setAmount(-money);


               string idBank=AC->data.getNumAccount().substr(0,3);
               Record_Rut R(AC->data.getNumAccount(),banks.SearchBank(idBank)->data.getNameBank(),-money);
               R.RecordtoFile();
               cout<<"BAN DA THUC HIEN RUT TIEN THANH CONG!!!"<<endl;
               system("pause");
          }
          static long long ChuyenTien(Node<Account>* AC,string STKDich,QLNH &banks,QLKH &users,QLTK &accounts)
          {
               long long money;
               Start:
               cout<<"Nhap So Tien Can Chuyen(Nhap '-1' De Quay Lai): ";
               while (true) {                  
                    cin >> money;
                    if (money == -1) {
                         return -1;
                    }
                    if (!cin.fail() && cin.peek() == '\n' && money >= 0) {
                         break;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "So tien khong hop le! Vui long nhap lai((Nhap '-1' De Quay Lai)):" << endl;
               }
               if(AC->data.getAmount()-money >= 0)
               AC->data.setAmount(-money);
               else {
                    cout<<"Khong Du Tien Trong Tai Khoan!!!"<<endl;
                    cout<<"Vui Long Nhap Lai So Tien Can Chuyen!!!"<<endl;
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
                              Node<Account> *NAUSER=NU->data.getUserAccount()->head;
                              while(NAUSER!=nullptr)
                              {
                                   if(NAUSER->data==AC->data)
                                   {
                                        NAUSER->data.setAmount(-money);
                                   }
                                   NAUSER=NAUSER->next;
                              }
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

               accounts.SearchAccount(AC->data.getNumAccount())->data.setAmount(-money);

               Bank NH=banks.SearchBank(AC->data.getNumAccount().substr(0,3))->data;
               Record_Chuyen Chuyen(AC->data.getNumAccount(),STKDich,NH.getNameBank(),-money);
               Chuyen.RecordtoFile();
               cout<<"BAN DA THUC HIEN CHUYEN TIEN THANH CONG!!!"<<endl;
               system("pause");
               return money;
          }
          static void NhanTien(Node<Account>* AC,string STKNguon,long long money,QLNH &banks,QLKH &users,QLTK &accounts) 
        {
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
                              Node<Account> *NAUSER=NU->data.getUserAccount()->head;
                              while(NAUSER!=nullptr)
                              {
                                   if(NAUSER->data==AC->data)
                                   {
                                        NAUSER->data.setAmount(money);
                                   }
                                   NAUSER=NAUSER->next;
                              }
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

               accounts.SearchAccount(AC->data.getNumAccount())->data.setAmount(money);

               string idBank=AC->data.getNumAccount().substr(0,3);
               Record_Chuyen C(AC->data.getNumAccount(),STKNguon,banks.SearchBank(idBank)->data.getNameBank(),money);
               C.RecordtoFile();
        }
          static void TraCuuSoDu(Node<Account>* AC,QLNH &bank)
          {
               
               string type= (AC->data.getTypeAccount()==0) ? "Tiet Kiem" : "Thanh Toan" ;
               string nameB=bank.SearchBank(AC->data.getNumAccount().substr(0,3))->data.getNameBank();
               cout << "\t\t\t+======================================================================+" << endl;
               cout << "\t\t\t|                         ** TRA CUU SO DU **                          |" << endl;
               cout << "\t\t\t+============+==================+===============+======================+" << endl;
               cout << "\t\t\t|  LOAI TK   |   SO TAI KHOAN   | TEN NGAN HANG |        SO DU         |" << endl;
               cout << "\t\t\t+============+==================+===============+======================+" << endl;
               cout << "\t\t\t| " << setw(11) << left << type << "|   " << setw(15) << AC->data.getNumAccount() << "|   " << setw(12) << left << nameB << "|  " << setw(20) << left << AC->data.getAmount() << "|"<< endl;
               cout << "\t\t\t+============+==================+===============+======================+" << endl;
               system("pause");
          }
          static void TraCuuLichSuGiaoDich(Node<Account>* AC)
        {
               string Path="DataBase/GiaoDich/" + AC->data.getNumAccount() + ".txt";
               ifstream file(Path,ios::in);
               cout << "\t\t\t+================================================================================================================+" << endl;
               cout << "\t\t\t|                                            ** LICH SU GIAO DICH **                                             |" << endl;
               cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
               cout << "\t\t\t|   LOAI GD   |   STK THUC HIEN   | STK CHUYEN TIEN  | TEN NGAN HANG |     SO TIEN     |   THOI GIAN THUC HIEN   |" << endl;
               cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
               string line;
               if(file.peek()==EOF)
               {    
                    cout<<"\t\t\t\t"<<endl;
                    cout<<"TAI KHOAN NAY KHONG CO GIAO DICH NAO!!!"<<endl;
               }
               else
               {
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
                         cout << "\t\t\t| " << setw(12) << left << Type << "| " << setw(18) << left << IDSourceAccount << "| " << setw(17) << left << IDDesAccount << "| " << setw(14) << left << NameBank << "| " << setw(12) << left << Amount <<" VND"<< "| " << setw(10) << left << Time << "|" << endl;
                    }
                    cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
               }
               system("pause");
        }
          static void DoiMatKhau(Node<Account>* NA,QLNH& banks,QLKH& users,QLTK& accounts)
{
    string password="";
    string PWAcc=NA->data.getPassword();
    int cnt=0;
    while(1)
    {
        cout<<"NHAP MAT KHAU CU('Exit' De Quay Lai): ";
        cin>>password;
        if(password=="Exit"||password=="exit")
          return ;
        if(password==PWAcc)
          break;
        cout<<endl;
        cout<<"MAT KHAU CU KHONG CHINH XAC! VUI LONG NHAP LAI !!!"<<endl;
        cout<<"NHAP SAI QUA 5 LAN SE THOAT!!!";
        system("pause");
        cnt++;
        if(cnt==5)
            return ;
    }
    string newpassword;
    cout<<"NHAP MAT KHAU MOI: "<<endl;
    cin>>newpassword;

    NA->data.setPassword(newpassword);

    string idBank=NA->data.getNumAccount().substr(0,3);
    Node<Bank> *NB=banks.getLinkListParBank()->Search(Bank("",idBank));
    User Us(NA->data.getCCCD(),"",Date(0,0,0),"","",0);
    Node<User> *NUB=NB->data.getLinkListUser()->Search(Us);
    NUB->data.getUserAccount()->Search(NA->data)->data.setPassword(newpassword);

    Node<User> *NU=users.getLinkListUser()->Search(Us);
    NU->data.getUserAccount()->Search(NA->data)->data.setPassword(newpassword);

    accounts.getLinkListAccount()->Search(NA->data)->data.setPassword(newpassword);
    cout<<"DA THAY DOI MAT KHAU THANH CONG!"<<endl;
    system("pause");
}      
};


