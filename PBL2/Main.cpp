
// #include "Menu/Menu.cpp"
#include "./DangNhap_DangKy/SignIn.cpp"
// #include "./DangNhap_DangKy/Register.cclpp"
#include<iostream>

QLNH banks;
QLKH users;
QLTK accounts;



void DangNhapAC(Node<Account> *nodeAC)
{
    if(nodeAC->data.getTypeAccount() == 0)
    {
        SavingCard(nodeAC,banks,users);
    }
    else 
    {
        menuDebitCard();
    }

}


void DangNhap_DangKy()
{
    startMenu();
Menu:
    menuUser();
    switch (choose(1,3))
    {
    case 1:     
        system("cls");
        Node<Account>* nodeAc=SignIn::DangNhap(banks);
        if(nodeAc==nullptr)
            goto Menu;
        else {
            DangNhapAC(nodeAc);
        }
        cout << endl;
        system("pause");
        cout.flush();
        break;
    // case 2:
    // system("cls");
    // Register::NhapThongTinKhachHang();
    // cout << endl;
    // system("pause");
    // cout.flush();
    // goto Menu;
    //     break;
    // case 3:
    //     exit(0);
    //     break;
    }
}

int main()
{
    banks.linkData(accounts,users);
   
    system("pause");
    TextColor(12);
    try
    {
        fflush(stdin);
        DangNhap_DangKy();
    }
    
    catch (string msg)
    {
        cout << endl
             << "\t\t\t\t\t" << msg;
    }

    
}