
// #include "Menu/Menu.cpp"
#include "./DangNhap_DangKy/SignIn.cpp"
#include "./DangNhap_DangKy/Register.cpp"
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
        DebitCard(nodeAC,banks,users);
    }

}


void DangNhap_DangKy()
{
    startMenu();
    system("pause");
Menu:
    menuUser();
    switch (choose(1,3))
    {
    case 1:     
        {
            system("cls");
            Node<Account>* nodeAc=SignIn::DangNhap(banks);
            if(nodeAc!=nullptr)
                DangNhapAC(nodeAc);
            system("pause");
            goto Menu;
            break;
        }
    case 2:
        {
            system("cls");
            Register::DangKi(banks,users,accounts);
            goto Menu;   
            break;
        }
    case 3:
        {
            cout<<"Tam Biet!"<<endl;
            system("pause");
            return ;
        }
    }
}

int main()
{
    banks.linkData(accounts,users);

    system("pause");
    TextColor(12);
    DangNhap_DangKy();
    
    
}