#pragma once
#include <windows.h>
#include <iostream>
#include"../Object/Account/Account.cpp"
#include "../Data_structer/Node.cpp"
#include "../GiaoDich/GiaoDich.cpp"
#include "../Admin/Admin.cpp"

using namespace std;
#define en cout << endl;
// #include <string.h>

string soTaiKhoan, matKhau;
// bool checkChoose(int choose,const int )

void TextColor(int x)
{
     HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(color, x);
}

void InLine(int n)
{
     for (int i = 0; i < n; i++)
          cout << "=";
}

int choose(int l,int r)
{
    int chon;
    cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
    cin >> chon;
    while (chon < l || chon > r || chon==0)
    {
        cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
        cin >> chon;
    }
    return chon;
}


void startMenu()
{
     en
         TextColor(12);
     cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");
     cout << endl;
     TextColor(14);
     cout << ("\t\t               ==========================================================");
     cout << endl;
     cout << ("\t\t               De tai: QUAN LY TAI KHOAN LIEN NGAN HANG");
     cout << endl;
     cout << ("\t\t               Giao vien huong dan: LE THI MY HANH");
     cout << endl;
     cout << ("\t\t               Ho ten sinh vien 1: Le Quoc Viet"
              "\t      Lop: 22T_Nhat2");
     cout << endl;
     cout << ("\t\t               Ho ten sinh vien 2: Tran Trung Duc "
              "    Lop: 22T_Nhat2");
     cout << endl;
     cout << ("\t\t               Nhom: 04");
     cout << endl;
     TextColor(14);
     cout << ("\t\t               ==========================================================");
     cout << endl;
     TextColor(3);
     cout << endl;
     cout << "\t\t\t       **********************************************************" << endl;
     cout << "\t\t                     CHUONG TRINH QUAN LY TAI KHOAN LIEN NGAN HANG         " << endl;
     cout << "\t\t\t       **********************************************************" << endl;
     
}

void MenuAdmin()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -QUAN LY-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.QUAN LY TAI KHOAN                    \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.QUAN LY KHACH HANG                   \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.QUAN LY DOANH THU                    \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.THOAT                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}
void MenuQuanLyTaiKhoan()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -QUAN LY TAI KHOAN-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Tra Cuu Thong Tin Tai Khoan          \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Tra Cuu Lich Su Giao Dich            \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Xoa Tai Khoan                        \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.Quay lai                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                5.Thoat                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}
void MenuQuanLyKhachHang()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -QUAN LY KHACH HANG-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Tra Cuu Danh Sach Tai Khoan          \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Tra Cuu Thong Tin                    \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Tra Cuu Thong Tin                    \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.Quay lai                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                5.Thoat                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}
void MenuQuanLyDoanhThu()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -QUAN LY NGAN HANG-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Tra Cuu Danh Sach Tai Khoan                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Tong doanh thu                       \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Thong ke so luong nap tien           \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.Thong ke so luong rut tien           \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                5.Thong ke so luong chuyen tien        \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                6.In Danh Sach Ngan Hang Theo Doanh Thu\t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                6.Quay Lai                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                7.Thoat                             \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}



void admin(QLNH &banks,QLKH &users,QLTK &accounts){
     start:
     MenuAdmin();
     switch(choose(1,4))
     {
          case 1:
               startAdTK:
               system("cls");
               MenuQuanLyTaiKhoan();
               switch(choose(1,5))
               {
                    case 1:
                         {
                              system("cls");
                              AdminQLTK::TraCuuThongTinTaiKhoan(accounts);
                              break;
                         }
                    case 2:
                         {
                              system("cls");
                              AdminQLTK::TraCuuLichSuGiaoDich(accounts);
                              break;
                         }
                    case 3:
                         {
                              system("cls");
                              AdminQLTK::XoaTaiKhoan(banks,users,accounts);
                              break;
                         }
                    case 4:
                         {
                              system("cls");
                              goto start;
                              break;
                         }
                    case 5:
                         return;
               }
               goto startAdTK;
          case 2:
               system("cls");
               MenuQuanLyKhachHang();
               cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
               switch(choose(1,4))
               {
                    case 1:
                         system("cls");
                         // QLKH::DanhSachKhachHang(users);
                         break;
                    case 2:
                         system("cls");
                         // QLKH::TimKiemKhachHangTheoID(users);
                         break;
                    case 3:
                         system("cls");
                         admin(banks,users,accounts);
                         break;
                    case 4:
                         return;
               }
               // QLKH::MenuQuanLyKhachHang(banks,users);
               break;
          case 3:
               system("cls");
               MenuQuanLyDoanhThu();
               cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
               switch(choose(1,6))
               {
                    case 1:
                         system("cls");
                         // QLNH::TongDoanhThu(banks);
                         break;
                    case 2:
                         system("cls");
                         // QLNH::ThongKeSoLuongNapTien(banks);
                         break;
                    case 3:
                         system("cls");
                         // QLNH::ThongKeSoLuongRutTien(banks);
                         break;
                    case 4:
                         system("cls");
                         // QLNH::ThongKeSoLuongChuyenTien(banks);
                         break;
                    case 5:
                         system("cls");
                         admin(banks,users,accounts);
                         break;
                    case 6:
                         return;
               }
               // QLNH::MenuQuanLyDoanhThu(banks);
               break;
          case 4:
               return;
     }
     admin(banks,users,accounts);
}



void menuUser()
{
     system("cls");
     en
         TextColor(12);
     cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");
     cout << endl;
     cout << ("\t\t\t\t\t          -DANG NHAP HOAC DANG KI- ");
     cout << endl;
     TextColor(14);
     cout << ("\t\t               ==========================================================");
     cout << endl;
     cout << ("\t\t\t\t                MOI BAN LUA CHON THAO TAC!");
     cout << endl;
     cout << ("\t\t\t\t                    1. DANG NHAP");
     cout << endl;
     cout << ("\t\t\t\t                    2. TAO TAI KHOAN");
     cout << endl;
     cout << ("\t\t\t\t                    3. THOAT");
     cout << endl;
}


void menuDebitCard()
{
     system("cls");
     en
         TextColor(12);
     cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");
     cout << endl;
     TextColor(14);
     cout << ("\t\t               ==========================================================");
     cout << endl;
     cout << ("\t\t\t\t                    THAO TAC CUA BAN!");
     cout << endl;
     cout << ("\t\t\t                 1. NAP TIEN");
     cout << endl;
     cout << ("\t\t\t                 2. RUT TIEN");
     cout << endl;
     cout << ("\t\t\t                 3. CHUYEN TIEN");
     cout << endl;
     cout << ("\t\t\t                 4. TRA CUU SO DU");
     cout << endl;
     cout << ("\t\t\t                 5. TRA CUU LICH SU GIAO DICH");
     cout << endl;
     cout << ("\t\t\t                 6. THOAT");
     cout << endl;
}
void menuSavingCard()
{
     system("cls");
     en
         TextColor(12);
     cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");
     cout << endl;
     TextColor(14);
     cout << ("\t\t               ==========================================================");
     cout << endl;
     cout << ("\t\t\t\t                    THAO TAC CUA BAN!");
     cout << endl;
     cout << ("\t\t\t                 1. NAP TIEN");
     cout << endl;
     cout << ("\t\t\t                 2. RUT TIEN");
     cout << endl;
     cout << ("\t\t\t                 3. TRA CUU SO DU");
     cout << endl;
     cout << ("\t\t\t                 4. TRA CUU LICH SU GIAO DICH");
     cout << endl;
     cout << ("\t\t\t                 5. THOAT");
     cout << endl;
}

void deposit(Account &X)
{
     long long Money;
     system("cls");
     en
         TextColor(12);
     cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");
     cout << endl;
     TextColor(14);
     cout << ("\t\t               ==========================================================");
     cout << endl;
     cout << ("\t\t\t                    NHAP SO TIEN BAN MUON NAP | ");
     cin>>Money;
     cout << endl;
     X.setAmount(Money);
     cout <<fixed<< ("\t\t\t                    SO DU CUA BAN LA | ")<<X.getAmount()<<" VND"<<endl;
}

void SavingCard(Node<Account> *nodeAC,QLNH &banks,QLKH &users,QLTK &accounts){
     Start:
     menuSavingCard();
     switch(choose(1,5))
     {
          case 1:
               system("cls");
               GiaoDich::NapTien(nodeAC,banks,users,accounts);
               break;
          case 2:
               system("cls");
               GiaoDich::RutTien(nodeAC,banks,users,accounts);
               break;
          case 3:
               system("cls");
               GiaoDich::TraCuuSoDu(nodeAC,banks);
               break;
          case 4:
               system("cls");
               GiaoDich::TraCuuLichSuGiaoDich(nodeAC);
               break;
          case 5:
               return;
     }
     goto Start;
}

Node<Account> *nodeNA(QLNH &banks)
{
                string ACDich;
               Node<Account> *NA;
               while(1)
               {
                    cout<<"Nhap So Tai Khoan Can Chuyen Tien(Nhap 'Exit' De Quay Lai): ";
                    cin>>ACDich;
                    if(ACDich=="Exit")
                         return nullptr;
                    cout<<endl;
                    string idBank=ACDich.substr(0,3);
                    Node<Bank> *NB=banks.SearchBank(idBank);
                    if(NB==nullptr)
                         {
                              cout<<"So Tai Khoan Khong Chinh Xac!!!"<<endl;
                         }
                    else{
                    NA=NB->data.searchAccount(ACDich);
                    if(NA==nullptr)
                         {
                              cout<<"So Tai Khoan Khong Chinh Xac!!!"<<endl;
                         }
                    else 
                    {
                         break;
                    }
                    }
               }
          return NA;
}

void DebitCard(Node<Account> *nodeAC,QLNH &banks,QLKH &users,QLTK &accounts){
     Start:
     menuDebitCard();
     switch(choose(1,6))
     {
          
          case 1:
               {
                    system("cls");
                    GiaoDich::NapTien(nodeAC,banks,users,accounts);
                    break;
               }
          case 2:
               {
                    system("cls");
                    GiaoDich::RutTien(nodeAC,banks,users,accounts);
                    break;
               }
          case 3:
               {
                    system("cls");
                    Node<Account> *X=nodeNA(banks);
                    if(X!=nullptr)
                    {
                    long long money=GiaoDich::ChuyenTien(nodeAC,X->data.getCCCD(),banks,users,accounts);
                    if(money!=-1)
                    GiaoDich::NhanTien(X,nodeAC->data.getNumAccount(),money,banks,users,accounts);
                    }
                    break;
               }
          case 4:
               {
                    system("cls");
                    GiaoDich::TraCuuSoDu(nodeAC,banks);
                    break;
               }
          case 5:
               {
                    system("cls");
                    GiaoDich::TraCuuLichSuGiaoDich(nodeAC);
                    break;
               }
          case 6:
                    {return ;}
     }
     goto Start;
}


