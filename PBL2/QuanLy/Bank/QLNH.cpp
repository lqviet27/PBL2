#include "QLNH.h"

QLNH::QLNH()
{
   
}
QLNH::~QLNH()
{

}
void QLNH::addBank(const Bank& b){
    parBank.Add(b);
}


void QLNH::showBank(){
    cout<<"ID"<<"\t\t" <<"Ten Ngan Hang"<<endl;
    parBank.Show();
}
Bank QLNH::SearchBank(const string& id){
    Bank bank("", id);
    Node<Bank> *b=this->parBank.Search(bank);
    if(b!=nullptr)
        return b->data;
    else 
        return Bank("error","-1");
}