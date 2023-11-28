#include"Record_Nap.h"

Record_Nap::Record_Nap():Record()
{
}

Record_Nap::Record_Nap(string IDAccount,string NameBank,double Amount):Record(IDAccount,NameBank,Amount)
{
}

Record_Nap::~Record_Nap()
{
}
void Record_Nap::Show()
{
    cout << "\t\t\t+=========================================================+" << endl;
    cout << "\t\t\t|                  ** LICH SU GIAO DICH **                |" << endl;
    cout << "\t\t\t+================+==================+============+========+" << endl;
    cout << "\t\t\t| IDAccount        | NameBank   | Amount       |  Time    |" << endl;
    cout << "\t\t\t+==================+============+==============+==========+" << endl;
    cout << "\t\t\t| " << setw(17) << left << IDAccount << "| " << setw(11) << left << NameBank << "| " <<"+ "<< setw(10) << left << Amount << "| " << setw(10) << left << Time << "|" << endl;

}

void Record_Nap::RecordtoFile()
{
    string Path = "DataBase/GiaoDich/" + this->IDAccount + ".txt";
    ofstream file(Path, ios::app);
    // file <<'\n'
        file << this->IDAccount << "|";
    file << this->NameBank << "|";
    file << fixed<<setprecision(2);
    file << this->Amount << "|";
    file << this->Time << "|"<<endl;
    file.close();
}