#define en cout << endl;
#include"Object/Account/Account.h"
#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;
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
     system("pause");
}

void menu()
{
     system("cls");
     en
         TextColor(12);
     cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");
     cout << endl;
     TextColor(14);
     cout << ("\t\t               ==========================================================");
     cout << endl;
     cout << ("\t\t\t\t                HAY CHON VAI TRO CUA BAN!");
     cout << endl;
     cout << ("\t\t\t\t                    1. QUAN LI");
     cout << endl;
     cout << ("\t\t\t\t                    2. NGUOI DUNG");
     cout << endl;
     system("pause");
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
     system("pause");
}
void menuSignIn(string &numAccount, string &passWord)
{
     system("cls");
     TextColor(12);
     cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");
     cout << endl;
     cout << ("\t\t\t\t\t               -DANG NHAP- ");
     cout << endl;
     TextColor(14);
     cout << ("\t\t               ==========================================================");
     cout << endl;
     cout << "\n\t\t"
          << "\t\t              TAI KHOAN | ";
     getline(cin, numAccount);
     cout << "\n\t\t"
          << "\t\t              MAT KHAU  | ";
     getline(cin, passWord);
     system("pause");
}
void menuSignUp(string &nameBank, string &name, string &passWord)
{
     system("cls");
     TextColor(12);
     cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");
     cout << endl;
     cout << ("\t\t\t\t\t               -DANG KI- ");
     cout << endl;
     TextColor(14);
     cout << ("\t\t               ==========================================================");
     cout << endl;
     cout << "\n\t\t"
          << "\t\t\t           THONG TIN CA NHAN! ";
     cout << "\n\t\t"
          << "\t\t         TEN NGAN HANG | ";
     getline(cin, nameBank);
     cout << "\n\t\t"
          << "\t\t         HO VA TEN | ";
     getline(cin, name);
     cout << "\n\t\t"
          << "\t\t         MAT KHAU  | ";
     getline(cin, passWord);
     system("pause");
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
     system("pause");
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
     system("pause");
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
     cout <<fixed<< ("\t\t\t                    SO DU CUA BAN LA | ")<<X.getAmount()<<endl;
     system("pause");
}

int main()
{
     // startMenu();
     // menu();
     // menuUser();
     // string a, b, c;
     // menuSignIn(a, b);
     // menuSignUp(a, b, c);
     // menuDebitCard();
     // menuSavingCard();
     Account X;
     deposit(X);

}