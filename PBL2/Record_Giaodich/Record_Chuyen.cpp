#include"Record_Chuyen.h"

const string Record_Chuyen::Type = "Chuyen tien";


Record_Chuyen::Record_Chuyen():Record()
{
}

Record_Chuyen::Record_Chuyen(string IDAccount,string IDDesAccount,string NameBank,long long Amount):Record(IDAccount,NameBank,Amount)
{
    this->IDDesAccount = IDDesAccount;
}

Record_Chuyen::~Record_Chuyen()
{
}

void Record_Chuyen::Show()
{
    cout << "\t\t\t+================================================================================================================+" << endl;
    cout << "\t\t\t|                                            ** LICH SU GIAO DICH **                                             |" << endl;
    cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
    cout << "\t\t\t|   LOAI GD   |   STK THUC HIEN   | STK CHUYEN TIEN  | TEN NGAN HANG |     SO TIEN     |   THOI GIAN THUC HIEN   |" << endl;
    cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
    cout << "\t\t\t| " << setw(12) << left << Type << "| " << setw(18) << left << IDSourceAccount << "| " << setw(17) << left << IDDesAccount << "| " << setw(14) << left << NameBank << "| " << setw(12) << left << Amount <<" VND"<< "| " << setw(10) << left << Time << "|" << endl;
    cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
}

void Record_Chuyen::RecordtoFile()
{
    string Path = "DataBase/GiaoDich/" + this->IDSourceAccount + ".txt";
    ofstream file(Path, ios::app);
    file << this->Type << "|";
    file << this->IDSourceAccount << "|";
    file << this->IDDesAccount << "|";
    file << this->NameBank << "|";
    file << fixed<<setprecision(2);
    file << this->Amount << "|";
    file << this->Time << "|"<<endl;
    file.close();
}