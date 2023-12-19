
// #include"QuanLy/Bank/QLNH.cpp"
// #include"Object/Bank/Bank.cpp"
// #include"QuanLy/Bank/QLNH.cpp"
#include<iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main(){
 
    // QLNH A;
    // QLKH B;
    // QLTK C;
    // A.linkData(C,B);
    // // A.showBank();
    // A.showBank();
    // A.Sort();
    // cout<<"Sau khi sap xep:"<<endl;
    // A.showBank();
    // cout<<endl;
    // B.showUser();
    // B.Sort();
    // cout<<"Sau khi sap xep:"<<endl;
    // B.showUser();
    // cout<<endl;
    // C.showAccount();
    // C.Sort();
    // cout<<"Sau khi sap xep:"<<endl;
    // C.showAccount();

    // B.showUser();
    // C.showAccount();
    /*
    Link_list<Bank> *U=A.getLinkListParBank();
    Node<Bank> *Une=U->head;
    while(Une!=nullptr){
      cout<<Une->data.getNameBank()<<endl;
      Link_list<User> *x =Une->data.getLinkListUser();
      Node<User> *tail=x->head;
      while(tail!=nullptr)
        {
          cout<<"Khach hang "<<tail->data.getName()<<endl;
          Link_list<Account> *y =tail->data.getUserAccount(); 
          Node<Account> *tail2=y->head;
          
          while(tail2!=nullptr){
            
            tail2->Show();
            tail2=tail2->next;
          }
          tail=tail->next;
        }
      // cout<<"Ngan hang "<<Une->data.getNameBank()<<" co cac tai khoan:"<<endl;
      // Link_list<Account> *x = Une->data.getLinkListAccount();
      // while(x->head!=nullptr){
      //   x->head->Show();
      //   x->head=x->head->next;
      // }
      Une=Une->next;
    }
    */
    /*
    Link_list<Bank> *U=A.getLinkListParBank();
    Node<Bank> *Une=U->head;
    while(Une!=nullptr){
      cout<<Une->data.getNameBank()<<endl;
          Link_list<Account> *y =Une->data.getLinkListAccount(); 
          Node<Account> *tail2=y->head;
          while(tail2!=nullptr){
            tail2->Show();
            tail2->data.setAmount(2000);
            tail2=tail2->next;
          }
      Une=Une->next;
    }
    cout<<"Sau khi cap nhat:"<<endl;
    Link_list<Bank> *U2=A.getLinkListParBank();
    Node<Bank> *Une2=U->head;
    while(Une2!=nullptr){
      cout<<Une2->data.getNameBank()<<endl;
          Link_list<Account> *y2 =Une2->data.getLinkListAccount(); 
          Node<Account> *tail2=y2->head;
          while(tail2!=nullptr){
            tail2->Show();
            tail2->data.setAmount(2000);
            tail2=tail2->next;
          }
      Une2=Une2->next;
    }
    */
   /*
    Link_list<Bank> *U=A.getLinkListParBank();
    Node<Bank> *Une=U->head;
    while(Une!=nullptr){
      Link_list<User> *x =Une->data.getLinkListUser();
      Node<User> *tail=x->head;
      while(tail!=nullptr)
        {
          
          tail->data.setName("le quoc viet");
          tail->data.Show();
          tail=tail->next;
        }
      Une=Une->next;
    }
    cout<<"Sau khi cap nhat :"<<endl;
    Link_list<User> *U2=B.getLinkListUser();
    Node<User> *Une2=U2->head;
    while(Une2!=nullptr){
      Une2->data.Show();
      Une2=Une2->next;
    }
    */
    /*
    cout<<"Sau khi cap nhat:"<<endl;
    Link_list<User> *x =B.getLinkListUser();
    Node<User> *tail=x->head;
    while(tail!=nullptr)
      {
        cout<<"Khach hang "<<tail->data.getName()<<endl;
        Link_list<Account> *y =tail->data.getUserAccount(); 
        Node<Account> *tail2=y->head;
        while(tail2!=nullptr){
          tail2->Show();
          tail2=tail2->next;
        }
        tail=tail->next;
      }
      */
    
   
    // User u=User("1", "1", Date(0,0,0), "1", "1", true);
    // B.addUser(u);
    // B.showUser();



    //     ifstream file;
    //     string folderPath = "DataBase/GiaoDich";
    //     ifstream directory(folderPath);
        
    //     if (!directory.is_open()) {
    //         cerr << "thu muc khong ton tai" << endl;
    //         return 0;
    //     }
    //     while (!directory.eof()) {
    //         string filename;
    //         directory >> filename;

    //         // Kiểm tra xem là file .txt hay không
    //         size_t pos = filename.find_last_of(".");
    //         if (pos != string::npos && filename.substr(pos) == ".txt") {
    //             // In tên file
    //             cout << filename << endl;
    //         }
    //     }
    // return 0;
    string IDB = "005";
    string folderPath = "DataBase/GiaoDich";

    // Kiểm tra xem thư mục có tồn tại không
    if (!fs::exists(folderPath) || !fs::is_directory(folderPath)) {
        std::cerr << "khong ton tai thu muc" << std::endl;
        return 1;
    }

    // Duyệt qua tất cả các file trong thư mục
                cout << "\t\t\t+===========================================================================================================+" << endl;
               cout << "\t\t\t|                                           ** LICH SU GIAO DICH **                                         |" << endl;
               cout << "\t\t\t+============+==================+==================+============+=================+=========================+" << endl;
               cout << "\t\t\t|    Type    | IDSourceAccount  |   IDDesAccount   |  NameBank  |     Amount      |           Time          |" << endl;
               cout << "\t\t\t+============+==================+==================+============+=================+=========================+" << endl;
    for (const auto& entry : fs::directory_iterator(folderPath)) {
        // Kiểm tra xem là file .txt hay không
        if (entry.path().extension() == ".txt") {
            // In tên file
            string name =entry.path().filename().stem().string().substr(0,3);
            if(name==IDB) {

                string fileName = folderPath + "/" + entry.path().filename().string();
                string type = "Nap tien";
                // cout<<fileName<<endl;
               ifstream file(fileName,ios::in);
               string line;
               while(getline(file,line))
               {
                    string Type,IDSourceAccount,IDDesAccount,NameBank,Amount,Time;
                    stringstream ss(line);
                    getline(ss,Type,'|');
                    getline(ss,IDSourceAccount,'|');
                    getline(ss,IDDesAccount,'|');
                    getline(ss,NameBank,'|');
                    getline(ss,Amount,'|');
                    getline(ss,Time,'|');
                    if(Type==type){
                      cout << "\t\t\t| " << setw(11) << left << Type << "| " << setw(17) << left << IDSourceAccount << "| " << setw(17) << left << IDDesAccount << "| " << setw(11) << left << NameBank << "| " << setw(10) << left << Amount <<" VND"<< "| " << setw(10) << left << Time << "|" << endl;
                    }
               }
              //  system("pause");
              };
            // cout << entry.path().filename().stem().string() << endl;
        }
    }

    return 0;
}
/*
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
*/