#include <iostream>
#include <windows.h>
using namespace std;
// Define color constants


void TextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void menu() {
    TextColor(13);
    cout << "\t\t\t\t\t          DO AN CO SO LAP TRINH " << endl;
    TextColor(11);
    cout << "\t\t               ==========================================================" << endl;
    cout << "\t\t               De tai: QUAN LY RAP CHIEU PHIM" << endl;
    cout << "\t\t               Giao vien huong dan: Phan Thanh Tao" << endl;
    cout << "\t\t               Ho ten sinh vien 1: Nguyen Duc Manh    Lop: 20TCLC_Nhat1" << endl;
    cout << "\t\t               Ho ten sinh vien 2: Tran Nhat Minh     Lop: 20TCLC_Nhat1" << endl;
    cout << "\t\t               Nhom: 9" << endl;
    TextColor(11);
    cout << "\t\t               ==========================================================" << endl;
    TextColor(11);
    cout << endl;
    cout << "\t\t\t\t      *********************************************" << endl;
    cout << "\t\t\t                  CHUONG TRINH QUAN LY RAP CHIEU PHIM          " << endl;
    cout << "\t\t\t\t      *********************************************" << endl;
    system("pause");
}

int main() {
    menu();
    return 0;
}
