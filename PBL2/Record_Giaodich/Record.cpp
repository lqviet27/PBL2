#pragma once
#include"Record.h"


Record::Record()
{
    this->IDSourceAccount="";
    this->IDDesAccount="";
    this->NameBank="";
    this->Amount=0;
    time_t now = time(0);
    string T_time = ctime(&now);
    T_time.erase(std::remove(T_time.begin(), T_time.end(), '\n'), T_time.end());
    this->Time = T_time;
}

Record::Record(string IDAccount,string NameBank,long long Amount)
{
    this->IDSourceAccount=IDAccount;
    this->NameBank=NameBank;
    this->IDDesAccount="";
    this->Amount=Amount;
    time_t now = time(0);
    string T_time = ctime(&now);
    T_time.erase(std::remove(T_time.begin(), T_time.end(), '\n'), T_time.end());
    this->Time = T_time;
}

Record::~Record()
{
}

