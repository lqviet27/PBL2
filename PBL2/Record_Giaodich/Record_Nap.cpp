#include"Record_Nap.h"

Record_Nap::Record_Nap():Record()
{
}

Record_Nap::Record_Nap(string IDAccount,string NameBank,double Amount):Record(IDAccount,NameBank,Amount)
{
}

void Record_Nap::Show()
{
    cout << "\t\t\t+=========================================================+" << endl;
    cout << "\t\t\t|                  ** LICH SU GIAO DICH **                |" << endl;
    cout << "\t\t\t+================+==================+============+========+" << endl;
    cout << "\t\t\t| IDAccount        | NameBank   | Amount       |  Time    |" << endl;
    cout << "\t\t\t+==================+============+==============+==========+" << endl;
    cout << "\t\t\t| " << setw(17) << left << this->IDAccount << "| " << setw(11) << left << this->NameBank << "| " << setw(13) << left <<"+"<< this->Amount << "| " << setw(10) << left << this->Time << "|" << endl;

}

void Record_Nap::RecordtoFile()
{
    ofstream file;
    string Path = "DataBase/GiaoDich/" + this->IDAccount + ".txt";
    file.open("Path", ios::app);
    file <<'\n'
         << this->IDAccount << "|";
    file << this->NameBank << "|";
    file << this->Amount << "|";
    file << this->Time << "|";
    file.close();
}