#pragma once
#include"Record.h"


Record::Record()
{

    this->IDAccount="";
    this->NameBank="";
    this->Amount=0;
    time_t now = time(0);
    string T_time = ctime(&now);
    T_time.erase(std::remove(T_time.begin(), T_time.end(), '\n'), T_time.end());
    this->Time = T_time;
}

Record::Record(string IDAccount,string NameBank,double Amount)
{
    this->IDAccount=IDAccount;
    this->NameBank=NameBank;
    this->Amount=Amount;
    time_t now = time(0);
    string T_time = ctime(&now);
    T_time.erase(std::remove(T_time.begin(), T_time.end(), '\n'), T_time.end());
    this->Time = T_time;
}

Record::~Record()
{
}

