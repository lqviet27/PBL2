
#include"Bank.h"
#include<iostream>
#include<fstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
Bank::Bank(){
    this->countAccount=0;
}
Bank::Bank(string nameBank, string IDBank)
{   
    this->countAccount = 0;
    this->nameBank = nameBank;
    this->IDBank = IDBank;
}


Bank::~Bank()
{

}

string Bank::getIdBank()
{
    return this->IDBank;
}

void Bank::addAccount(Account& ac)
{
    this->countAccount++;
    parAccount.Add(ac);
    // parAccount.Search(ac)->data.setNumAccount(this->IDBank + to_string(this->countAccount));
    //* xu ly nhap file
    addAccounttoFile(ac);
}

void Bank::addAccounttoFile(Account& acc){
    ifstream file;
    string directory = "DataBase/Account";
    string fileName = directory+ "/Bank_" + this->IDBank + ".txt";
    // string fileName = directory+ "/Account" + ".txt";
    file.open(fileName);
    if(!fs::is_directory(directory)){
        fs::create_directory(directory);
    };
    if(!file){
       ofstream outFile(fileName); 
       outFile.close();
    }
    ofstream outFile(fileName, ios_base::app);
    if (!outFile.is_open()) {
            // Nếu không thể mở file, xuất thông báo lỗi và thoát khỏi phương thức
            cerr << "Error: Unable to open file " << fileName << endl;
            return;
        }
    acc.InsertObjecttoFile(outFile);
    outFile.close();
}

void Bank::addUser(const User& us)
{
    parUser.Add(us);
}

string Bank::getCountAccount()
{
    string tmp = to_string(this->countAccount);
    return tmp;
}

// void Bank::show_User()
// {
//     cout<<"DANH SACH NGUOI DUNG CUA NGAN HANG "<<this->nameBank<<" LA:"<<endl;
//     parUser.Show();
// }

void Bank::show_Account()
{
    cout<<"DANH SACH TAI KHOAN CUA NGAN HANG "<<this->nameBank<<" LA:"<<endl;
    parAccount.Show();
}
void Bank::show_User(){
    cout<<"DANH SACH KHACH HANG CUA NGAN HANG "<<this->nameBank<<" LA:"<<endl;
    parUser.Show();
}
void Bank::Show(){
    cout<<"\t\t\t";
    cout<<"|  "<<this->IDBank<<" |"<<"\t"<<this->nameBank<<setw(12)<<"\t |"<<endl;
    
}
bool Bank::operator==(const Bank& B)
{
    return (this->IDBank == B.IDBank);
}
Account Bank::searchAcc(const string& numAcc){
    Account A(numAcc,"",0,0);
    Node<Account> *b = this->parAccount.Search(A);
    if(b != nullptr)
        {
            return b->data;
        }
    else {
        throw string("Khong tim thay tai khoan!");
}
}
void Bank::InsertObjecttoFile(ofstream &FileOut){
    FileOut<<this->IDBank<<"|"<<this->nameBank<<endl;
}


