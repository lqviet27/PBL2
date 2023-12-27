#include"Record_Nap.h"

const string Record_Nap::Type = "Nap tien";

Record_Nap::Record_Nap():Record()
{
}

Record_Nap::Record_Nap(string IDAccount,string NameBank,long long Amount):Record(IDAccount,NameBank,Amount)
{
    this->IDDesAccount = "NULL";

}

Record_Nap::~Record_Nap()
{
}
void Record_Nap::Show()
{
    cout << "\t\t\t+================================================================================================================+" << endl;
    cout << "\t\t\t|                                            ** LICH SU GIAO DICH **                                             |" << endl;
    cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
    cout << "\t\t\t|   LOAI GD   |   STK THUC HIEN   | STK CHUYEN TIEN  | TEN NGAN HANG |     SO TIEN     |   THOI GIAN THUC HIEN   |" << endl;
    cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
    cout << "\t\t\t| " << setw(12) << left << Type << "| " << setw(18) << left << IDSourceAccount << "| " << setw(17) << left << IDDesAccount << "| " << setw(14) << left << NameBank << "| " << setw(12) << left << Amount <<" VND"<< "| " << setw(10) << left << Time << "|" << endl;
    cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
}

void Record_Nap::RecordtoFile()
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


    // string Path = "DataBase/GiaoDich/" + this->IDSourceAccount + ".txt";
    // ifstream file;
    // if(!file){
    //    ofstream outFile(Path); 
    //    outFile.close();
    // }
    // ofstream outFile(Path, ios::app);
    // outFile << this->Type << "|";
    // outFile << this->IDSourceAccount << "|";
    // outFile << this->IDDesAccount << "|";
    // outFile << this->NameBank << "|";
    // outFile << fixed<<setprecision(2);
    // outFile << this->Amount << "|";
    // outFile << this->Time << "|"<<endl;
    // outFile.close();
}