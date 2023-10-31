#include "./DangNhap_DangKy/SignIn.cpp"
#include "./DangNhap_DangKy/Register.cpp"
#include<iostream>
void DangNhap_DangKy()
{
    startMenu();
Menu:
    menuUser();

    int chon;
    cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
    cin >> chon;
    while (chon < 0 || chon > 3)
    {
        cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
        cin >> chon;
    }
    switch (chon)
    {
    case 1:
        system("cls");
        SignIn::DangNhap();
        cout << endl;
        system("pause");
        cout.flush();
        break;
    case 2:
        system("cls");
        Register::NhapThongTinKhachHang();
        cout << endl;
        system("pause");
        cout.flush();
        goto Menu;
        break;
    case 3:
        exit(0);
        break;
    }
}

int main()
{
    
    try
    {
        fflush(stdin);
        DangNhap_DangKy();
    }
    catch (const char *msg)
    {
        cout << endl
             << "\t\t\t\t\t" << msg;
    }
    catch (string msg)
    {
        cout << endl
             << "\t\t\t\t\t" << msg;
    }
}