#include"Admin.h"

void AdminQLTK::TraCuuThongTinTaiKhoan(QLTK &accounts)
{
    string numAC;
    while(1)
    {
        start:
        system("cls");
        cout<<"Nhap So Tai Khoan Can Tra Cuu(Gom 10 So Lien Tiep(Nhap 'Exit' De Quay Lai)): ";
        cin>>numAC;
        if(numAC=="Exit"||numAC=="exit")
            return ;
        if(numAC.size()!=10)
            {
                cout<<"So Tai Khoan Khong Hop Le !!!"<<endl;
                system("pause");
                goto start;
            }
        for(int i=0;i<numAC.size();i++)
            if(!isdigit(numAC[i]))
            {
                cout<<"So Tai Khoan Khong Hop Le !!!"<<endl;
                system("pause");
                goto start;
            }
         Node<Account> *NA = accounts.SearchAccount(numAC);
         if(NA==nullptr) 
         {  
            cout<<"So Tai Khoan Khong Ton Tai !!!"<<endl;
            system("pause");
            goto start;
         }
         else 
         {
            cout << "\t\t\t+==================================================================================+" << endl;
            cout << "\t\t\t|                             ** THONG TIN TAI KHOAN **                            |" << endl;
            cout << "\t\t\t+================+==================+==================+============+==============+" << endl;
            cout << "\t\t\t|      CCCD      |   So Tai Khoan   |  Loai Tai Khoan  |    So Du   |   Mat Khau   |" << endl;
            cout << "\t\t\t+================+==================+==================+============+==============+" << endl;
            NA->data.Show();
            cout << "\t\t\t+================+==================+==================+============+==============+" << endl;
            system("pause");
            return ;
         }
    }
   
}

void AdminQLTK::TraCuuLichSuGiaoDich(QLTK &accounts)
{
    string numAC;
    while(1)
    {
        start:
        system("cls");
        cout<<"Nhap So Tai Khoan Can Tra Cuu(Gom 10 So Lien Tiep(Nhap 'Exit' De Quay Lai)): ";
        cin>>numAC;
        if(numAC=="Exit"||numAC=="exit")
            return ;
        if(numAC.size()!=10)
            {
                cout<<"So Tai Khoan Khong Hop Le !!!"<<endl;
                system("pause");
                goto start;
            }
        for(int i=0;i<numAC.size();i++)
            if(!isdigit(numAC[i]))
            {
                cout<<"So Tai Khoan Khong Hop Le !!!"<<endl;
                system("pause");
                goto start;
            }
         Node<Account> *NA = accounts.SearchAccount(numAC);
         if(NA==nullptr) 
         {  
            cout<<"So Tai Khoan Khong Ton Tai !!!"<<endl;
            system("pause");
            goto start;
         }
         else 
         {
            string Path="DataBase/GiaoDich/" + NA->data.getNumAccount() + ".txt";
               ifstream file(Path,ios::in);
               cout << "\t\t\t+===========================================================================================================+" << endl;
               cout << "\t\t\t|                                           ** LICH SU GIAO DICH **                                         |" << endl;
               cout << "\t\t\t+============+==================+==================+============+=================+=========================+" << endl;
               cout << "\t\t\t|    Type    | IDSourceAccount  |   IDDesAccount   |  NameBank  |     Amount      |           Time          |" << endl;
               cout << "\t\t\t+============+==================+==================+============+=================+=========================+" << endl;
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
                    cout << "\t\t\t| " << setw(11) << left << Type << "| " << setw(17) << left << IDSourceAccount << "| " << setw(17) << left << IDDesAccount << "| " << setw(11) << left << NameBank << "| " << setw(10) << left << Amount <<" VND"<< "| " << setw(10) << left << Time << "|" << endl;
               }
               system("pause");
               return;
         }
    }
}

// void AdminQLTK::DoiMatKhau(QLNH &banks,QLKH &users,QLTK &accounts)
// {
//     string numAC;
//     while(1)
//     {
//         start:
//         system("cls");
//         cout<<"Nhap So Tai Khoan Can Tra Cuu(Gom 10 So Lien Tiep(Nhap 'Exit' De Quay Lai)): ";
//         cin>>numAC;
//         if(numAC=="Exit"||numAC=="exit")
//             return ;
//         if(numAC.size()!=10)
//             {
//                 cout<<"So Tai Khoan Khong Hop Le !!!"<<endl;
//                 goto start;
//             }
//         for(int i=0;i<numAC.size();i++)
//             if(!isdigit(numAC[i]))
//             {
//                 cout<<"So Tai Khoan Khong Hop Le !!!"<<endl;
//                 goto start;
//             }
//          Node<Account> *NA = accounts.SearchAccount(numAC);
//          if(NA==nullptr) 
//          {  
//             cout<<"So Tai Khoan Khong Ton Tai !!!"<<endl;
//             goto start;
//          }
//          else 
//          {
//             string password;
//             cout<<"Nhap Mat Khau :";

//          }
//     }
// }

void AdminQLTK::XoaTaiKhoan(QLNH &banks,QLKH &users,QLTK &accounts)
{
    string numAC;
    while(1)
    {
        start:
        system("cls");
        cout<<"Nhap So Tai Khoan Can Xoa(Gom 10 So Lien Tiep(Nhap 'Exit' De Quay Lai)): ";
        cin>>numAC;
        if(numAC=="Exit"||numAC=="exit")
            return ;
        if(numAC.size()!=10)
            {
                cout<<"So Tai Khoan Khong Hop Le !!!"<<endl;
                system("pause");
                goto start;
            }
        for(int i=0;i<numAC.size();i++)
            if(!isdigit(numAC[i]))
            {
                cout<<"So Tai Khoan Khong Hop Le !!!"<<endl;
                system("pause");
                goto start;
            }
        Node<Account> *NA = accounts.SearchAccount(numAC);
        if(NA==nullptr) 
        {  
            cout<<"So Tai Khoan Khong Ton Tai !!!"<<endl;
            system("pause");
            goto start;
        }
        else 
        {
            Node<Bank> *NB=banks.SearchBank(numAC.substr(0,3));
            NB->data.getLinkListAccount()->Delete(NA->data);

            User U=User(NA->data.getCCCD(),"",Date(0,0,0),"","",0);
            Node<User> *NU=NB->data.getLinkListUser()->Search(U);
            Node<Account> *NA1=NU->data.getUserAccount()->head;
            if(NA1->next==nullptr)
                NB->data.getLinkListUser()->Delete(NU->data);
            else 
                NU->data.getUserAccount()->Delete(NA1->data);
            
            Node<User> *NU1=users.getLinkListUser()->Search(U);
            Node<Account> *NA2=NU1->data.getUserAccount()->head;
            if(NA2->next==nullptr)
                users.getLinkListUser()->Delete(NU1->data);
            else NU1->data.getUserAccount()->Delete(NA2->data);

            accounts.getLinkListAccount()->Delete(NA->data);
            return ;
        }
    }
}



void AdminQLKH::TraCuuDanhSachTaiKhoan(QLKH &users)
{
    string cccd;
    while(1)
    {
        start:
        system("cls");
        cout<<"NHAP CCCD CUA NGUOI DUNG CAN TRA CUU(GOM 12 CHU SO LIEN TIEP('Exit' DE QUAY LAI)): ";
        cin>>cccd;
        
        if(cccd=="Exit"||cccd=="exit")
            return ;
        if(cccd.size()!=12)
            {
                cout<<"SO CAN CUOC CONG DAN KHONG HOP LE !!!"<<endl;
                system("pause");
                goto start;
            }
        for(int i=0;i<cccd.size();i++)
            if(!isdigit(cccd[i]))
            {
                cout<<"SO CAN CUOC CONG DAN KHONG HOP LE !!!"<<endl;
                system("pause");
                goto start;
            }
            User U(cccd,"",Date(0,0,0),"","",0);
            if(users.getLinkListUser()->Search(U)==nullptr)
            {
                cout<<"SO CAN CUOC CONG DAN KHONG TON TAI !!!"<<endl;
                system("pause");
                goto start;
            }
            cout << "\t\t\t+==================================================================================+" << endl;
            cout << "\t\t\t|                       **DANH SACH TAI KHOAN CUA KHACH HANG**                     |" << endl;
            cout << "\t\t\t+================+==================+==================+============+==============+" << endl;
            cout << "\t\t\t|      CCCD      |   So Tai Khoan   |  Loai Tai Khoan  |    So Du   |   Mat Khau   |" << endl;
            cout << "\t\t\t+================+==================+==================+============+==============+" << endl;
            users.getLinkListUser()->Search(U)->data.showAccount();
            cout << "\t\t\t+================+==================+==================+============+==============+" << endl;
            system("pause");
            return ;
    }
}


void AdminQLKH::TraCuuThongTin(QLKH &users)
{
    string cccd;
    while(1)
    {
        start:
        system("cls");
        cout<<"NHAP CCCD CUA NGUOI DUNG CAN TRA CUU(GOM 12 CHU SO LIEN TIEP('Exit' DE QUAY LAI)): ";
        cin>>cccd;
        
        if(cccd=="Exit"||cccd=="exit")
            return ;
        if(cccd.size()!=12)
            {
                cout<<"SO CAN CUOC CONG DAN KHONG HOP LE !!!"<<endl;
                system("pause");
                goto start;
            }
        for(int i=0;i<cccd.size();i++)
            if(!isdigit(cccd[i]))
            {
                cout<<"SO CAN CUOC CONG DAN KHONG HOP LE !!!"<<endl;
                system("pause");
                goto start;
            }
            User U(cccd,"",Date(0,0,0),"","",0);
            if(users.getLinkListUser()->Search(U)==nullptr)
            {
                cout<<"SO CAN CUOC CONG DAN KHONG TON TAI !!!"<<endl;
                system("pause");
                goto start;
            }
            cout << "\t\t\t+=============================================================================================================================+" << endl;
            cout << "\t\t\t|                                                 ** DANH SACH NGUOI DUNG **                                                  |" << endl;
            cout << "\t\t\t+================+======================+=================+====================+==============================+===============+" << endl;
            cout << "\t\t\t|      CCCD      |        HoVaTen       |    Ngay Sinh    |    So Dien Thoai   |            Dia Chi           |   Gioi Tinh   |" << endl;
            cout << "\t\t\t+================+======================+=================+====================+==============================+===============+" << endl;
            users.getLinkListUser()->Search(U)->data.Show();
            cout << "\t\t\t+================+======================+=================+====================+==============================+===============+" << endl;
            system("pause");
            return ;
    }
}

void AdminQLKH::CapNhapThongTinKhachHang(QLNH& banks,QLKH& users)
{
    string cccd;
    while(1)
    {
        start:
        system("cls");
        cout<<"NHAP CCCD CUA NGUOI DUNG CAN THAY DOI THONG TIN(GOM 12 CHU SO LIEN TIEP('Exit' DE QUAY LAI)): ";
        cin>>cccd;
        if(cccd=="Exit"||cccd=="exit")
            return ;
        if(cccd.size()!=12)
            {
                cout<<"SO CAN CUOC CONG DAN KHONG HOP LE !!!"<<endl;
                system("pause");
                goto start;
            }
        for(int i=0;i<cccd.size();i++)
            if(!isdigit(cccd[i]))
            {
                cout<<"SO CAN CUOC CONG DAN KHONG HOP LE !!!"<<endl;
                system("pause");
                goto start;
            }
            User Us(cccd,"",Date(0,0,0),"","",0);
            if(users.getLinkListUser()->Search(Us)==nullptr)
            {
                cout<<"SO CAN CUOC CONG DAN KHONG TON TAI !!!"<<endl;
                system("pause");
                goto start;
            }
            string Name;
            Date Birthday;
            string PhoneNumber;
            string Address;
            string gender;
            bool check=0,Gender;
            cout << "Nhap Ho Va Ten: ";
            cin.ignore();
            getline(cin, Name);
            cout << "Nhap Ngay Sinh(dd/mm/yyyy): ";
            cin>>Birthday;
            cout << "Nhap So Dien Thoai(bao Gom 10 Chu so Lien Tiep): ";
            cin>>PhoneNumber;
            cout << "Nhap Dia Chi: "; // Trường hợp đặc biệt
            fflush(stdin);
            getline(cin,Address);
            cout << "Nhap Gioi Tinh(Nam/Nu): ";
            do
            {
                if (check == 1)
                    cout << "Sai Cu Phap Gioi Tinh, Moi Ban Nhap Lai :";
                check = 1;
                cin >> gender;
                if (gender == "nam" || gender == "Nam" || gender == "0")
                {
                    Gender = 0;
                    check = 0;
                }
                else if (gender == "Nu" || gender == "nu" || gender == "1")
                {
                    Gender = 1;
                    check = 0;
                }
            } while (check);
            User U(cccd,Name,Birthday,PhoneNumber,Address,Gender);

            Node<Bank> *NB=banks.getLinkListParBank()->head;
            while(NB!=nullptr)
            {
                Node<User> *NU=NB->data.getLinkListUser()->Search(U);
                if(NU!=nullptr)
                    NU->data.copyUser(U);
                NB=NB->next;
            }
            users.getLinkListUser()->Search(U)->data.copyUser(U);
            return ;
    }

    


}