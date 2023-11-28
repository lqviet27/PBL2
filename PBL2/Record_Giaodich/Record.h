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
    string IDAccount;
    string NameBank;
    double Amount;
    string Time;
public:
    Record();
    Record(string,string,double);
    int getIDRecord();
    virtual void Show() = 0;
    virtual void RecordtoFile()=0;
    ~Record(); 
};

