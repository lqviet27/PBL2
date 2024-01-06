#include "./DangNhap_DangKy/SignIn.cpp"
#include "./DangNhap_DangKy/Register.cpp"
#include "./DataBase/XuatduLieu.cpp"
#include<iostream>

QLNH banks;
QLKH users;
QLTK accounts;


void DangNhapAC(Node<Account> *nodeAC)
{
    if(nodeAC->data.getTypeAccount() == 0)
    {
        SavingCard(nodeAC,banks,users,accounts);
    }
    else 
    {
        DebitCard(nodeAC,banks,users,accounts);
    }

}


void DangNhap_DangKy()
{
    startMenu();
    system("pause");
    system("cls");
Menu:
    menuUser();
    switch (choose(1,3))
    {
    case 1:     
        {
            system("cls");
            Node<Account>* nodeAc=SignIn::DangNhap(banks,users,accounts);
            if(nodeAc!=nullptr)
                DangNhapAC(nodeAc);
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
    
    xuatDuLieuAccounts(accounts);
    xuatDuLieuUsers(users);
    xuatDuLieuBanks(banks);
}