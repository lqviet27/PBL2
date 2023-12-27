#pragma once
#include"../../Object/Bank/Bank.cpp"
#include "../Users/QLKH.cpp"
#include "../Account/QLTK.cpp"
using namespace std;

class QLNH
{
private:
    Link_list<Bank> parBank;
public:
    QLNH();
    QLNH(Link_list<Bank>);
    QLNH(const QLNH&);
    ~QLNH();
    void addBank(const Bank&);
    void Sort();
    void showBank();
    void linkData(QLTK&,QLKH&);
    Link_list<Bank>* getLinkListParBank();
    Node<Bank>* SearchBank(const string&);
    int getCountBank();
};



