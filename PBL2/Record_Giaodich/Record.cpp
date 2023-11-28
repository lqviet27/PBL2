#include"Record.h"



Record::Record()
{

    this->IDAccount="";
    this->NameBank="";
    this->Amount=0;
    time_t now = time(0);
    this->Time = ctime(&now);
}

Record::Record(string IDAccount,string NameBank,double Amount)
{
    this->IDAccount=IDAccount;
    this->NameBank=NameBank;
    this->Amount=Amount;
    time_t now = time(0);
    this->Time = ctime(&now);
}

Record::~Record()
{
}

