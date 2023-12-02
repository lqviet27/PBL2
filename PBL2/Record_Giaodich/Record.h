#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<ctime>
using namespace std;
class Record
{
protected:    
    string IDSourceAccount;
    string IDDesAccount;
    string NameBank;
    long long Amount;
    string Time;
public:
    Record();
    Record(string,string,long long);
    ~Record(); 
    virtual void Show() = 0;
    virtual void RecordtoFile()=0;
};

