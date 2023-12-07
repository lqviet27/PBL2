#include <iostream>
#include "../QuanLy/Account/QLTK.cpp"
#include "../QuanLy/Bank/QLNH.cpp"
#include "../QuanLy/Users/QLKH.cpp"
using namespace std;

void xuatDuLieuAccounts(QLTK &accounts)
{
    ifstream file;
    string fileName = "DataBase/Account/Account.txt";
    
    file.open(fileName);
    
    ofstream outFile(fileName, std::ios::out | std::ios::trunc);
    if (!outFile.is_open()) {
            cerr << "Error: Unable to open file " << fileName << endl;
            return;
        }
    Node<Account> *NA = accounts.getLinkListAccount()->head;
    while(NA!=nullptr)
    {
        if(NA->next!=nullptr)
            NA->data.InsertObjecttoFile(outFile,0);
        else 
            NA->data.InsertObjecttoFile(outFile,1);
        NA=NA->next;
    }
    outFile.close();
}

void xuatDuLieuUsers(QLKH& users)
{
    ifstream file;
    string fileName = "DataBase/User/User.txt";
    
    file.open(fileName);
    
    ofstream outFile(fileName, std::ios::out | std::ios::trunc);
    if (!outFile.is_open()) {
            cerr << "Error: Unable to open file " << fileName << endl;
            return;
        }
    Node<User> *NU = users.getLinkListUser()->head;
    while(NU!=nullptr)
    {   if(NU->next!=nullptr)
        NU->data.InsertObjecttoFile(outFile,0);
        else NU->data.InsertObjecttoFile(outFile,1);
        NU=NU->next;
    }
    outFile.close();
}

void xuatDuLieuBanks(QLNH& banks)
{
    ifstream file;
    string fileName = "DataBase/Bank/Bank.txt";
    
    file.open(fileName);
    
    ofstream outFile(fileName, std::ios::out | std::ios::trunc);
    if (!outFile.is_open()) {
            cerr << "Error: Unable to open file " << fileName << endl;
            return;
        }
    Node<Bank> *NB = banks.getLinkListParBank()->head;
    while(NB!=nullptr)
    {
        if(NB->next!=nullptr)
            NB->data.InsertObjecttoFile(outFile,0);
        else NB->data.InsertObjecttoFile(outFile,1);
        NB=NB->next;
    }
    outFile.close();
}