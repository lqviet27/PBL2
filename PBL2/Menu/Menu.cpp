#pragma once
#include <windows.h>
#include <iostream>
#include"../Object/Account/Account.cpp"
#include "../Data_structer/Node.cpp"
// #include "../GiaoDich/GiaoDich.cpp"
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
    while (chon < l || chon > r)
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

// void menu()
// {
//      system("cls");
//      en
//          TextColor(12);
//      cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");
//      cout << endl;
//      TextColor(14);
//      cout << ("\t\t               ==========================================================");
//      cout << endl;
//      cout << ("\t\t\t\t                HAY CHON VAI TRO CUA BAN!");
//      cout << endl;
//      cout << ("\t\t\t\t                    1. QUAN LI");
//      cout << endl;
//      cout << ("\t\t\t\t                    2. NGUOI DUNG");
//      cout << endl;
//      system("pause");
// }
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
     cout << ("\t\t\t                 2. CHUYEN TIEN");
     cout << endl;
     cout << ("\t\t\t                 3. RUT");
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
     cout << ("\t\t\t                 2. RUT");
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
     double Money;
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

void SavingCard(Node<Account> *nodeAC,QLNH &banks,QLKH &users){
     menuSavingCard();
     switch(choose(1,5))
     {
          case 1:
               system("cls");
               // GiaoDich::NapTien(nodeAC,banks,users);
               
     }



}
void DebitCard(){}



// int main()
// {
//      // startMenu();
//      // menu();
//      // menuUser();
//      // string a, b, c;
//      // menuSignIn(a, b);
//      // menuSignUp(a, b, c);
//      // menuDebitCard();
//      // menuSavingCard();
//      Account X;
//      deposit(X);

// }