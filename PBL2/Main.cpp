
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
            Node<Account>* nodeAc=SignIn::DangNhap(banks);
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
    
    // Node<Account> *NA=accounts.getLinkListAccount()->head;
    // while(NA!=nullptr)
    // {
    //     NA->data.Show();
    //     NA=NA->next;
    // }

    //* OKEEE 
    // Link_list<Bank> *NB=banks.getLinkListParBank();
    // Node<Bank> *temp=NB->head;
    // while(temp!=nullptr)
    // {
    //     Link_list<User>* NU=temp->data.getLinkListUser();
    //     Node<User> *temp1=NU->head;
    //     while(temp1!=nullptr)
    //     {
    //         Link_list<Account>* NA=temp1->data.getUserAccount();
    //         Node<Account> *temp2=NA->head;
    //         while(temp2!=nullptr)
    //         {
    //             temp2->data.Show();
    //             temp2=temp2->next;
    //         }
    //         temp1=temp1->next;
    //     }
    //     temp=temp->next;
    // }

    //* okeee
    //  Link_list<Bank> *NB=banks.getLinkListParBank();
    // Node<Bank> *temp=NB->head;
    // while(temp!=nullptr)
    // {
    //         Link_list<Account>* NA=temp->data.getLinkListAccount();
    //         Node<Account> *temp2=NA->head;
    //         while(temp2!=nullptr)
    //         {
    //             temp2->data.Show();
    //             temp2=temp2->next;
    //         }
    //     temp=temp->next;
    // }
}