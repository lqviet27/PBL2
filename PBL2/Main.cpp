
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
            if(nodeAc==nullptr)
                goto Menu;
            else {
                DangNhapAC(nodeAc);
            }
            cout << endl;
            system("pause");
            break;
        }
    case 2:
        {
            system("cls");
            Node<Account>* nodeAc=Register::DangKi(banks,users,accounts);
            cout << endl;
            system("pause");   
            break;
        }
    case 3:
        {
            cout<<"Tam Biet!"<<endl;
            system("pause");
            exit(0);
        }
    }
}

int main()
{
    banks.linkData(accounts,users);

    // cout<<endl<<endl<<endl<<endl;
    // Link_list<Bank> *B=banks.getLinkListParBank();
    // Node<Bank> *NB=B->head;
    // while(NB!=nullptr)
    // {
    //     Link_list<User> *U=NB->data.getLinkListUser();
    //     Node<User> *NU=U->head;
    //     while(NU!=nullptr)
    //     {
    //         cout<<NU->data.getCCCD();
    //         NU->data.showAccount();
    //         NU=NU->next;
    //     }

    //     NB=NB->next;
    //     cout<<endl;
    // }


    // Link_list<Bank> *listBank=banks.getLinkListParBank();
    // Node<Bank> *nodeBank=listBank->head;
    // while(nodeBank!=nullptr)
    // {
    //     Link_list<User> *listUser=nodeBank->data.getLinkListUser();
    //     Node<User> *nodeUser=listUser->head;
    //     while(nodeUser!=nullptr)
    //     {   
    //         nodeUser->data.Show();
    //         Link_list<Account> *listAccount=nodeUser->data.getUserAccount();
    //         // Link_list<Account> *listAccount=nodeBank->data.getLinkListAccount();
    //         Node<Account> *nodeAccount=listAccount->head; //* đang bị nullptr
    //         while(nodeAccount!=nullptr)
    //         {
    //             nodeAccount->data.Show();
    //             nodeAccount=nodeAccount->next;
    //         }
    //         nodeUser=nodeUser->next;
    //     }
    //     cout<<endl;
    //     nodeBank=nodeBank->next;
    // }

    system("pause");
    TextColor(12);
    DangNhap_DangKy();
    
    
    

    
}