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
            cout << "\t\t\t+=======================================================================================+" << endl;
            cout << "\t\t\t|                               ** THONG TIN TAI KHOAN **                               |" << endl;
            cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
            cout << "\t\t\t|      CCCD      |   So Tai Khoan   |  Loai Tai Khoan  |      So Du      |   Mat Khau   |" << endl;
            cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
            NA->data.Show();
            cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
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
               cout << "\t\t\t+================================================================================================================+" << endl;
               cout << "\t\t\t|                                            ** LICH SU GIAO DICH **                                             |" << endl;
               cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
               cout << "\t\t\t|   LOAI GD   |   STK THUC HIEN   | STK CHUYEN TIEN  | TEN NGAN HANG |     SO TIEN     |   THOI GIAN THUC HIEN   |" << endl;
               cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
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
                    cout << "\t\t\t| " << setw(12) << left << Type << "| " << setw(18) << left << IDSourceAccount << "| " << setw(17) << left << IDDesAccount << "| " << setw(14) << left << NameBank << "| " << setw(12) << left << Amount <<" VND"<< "| " << setw(10) << left << Time << "|" << endl;
               }
                cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
               system("pause");
               return;
         }
    }
}
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
            cout<<"DA XOA THANH CONG TAI KHOAN "<<numAC<<endl;
            system("pause");
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
            cout << "\t\t\t+=======================================================================================+" << endl;
            cout << "\t\t\t|                          **DANH SACH TAI KHOAN CUA KHACH HANG**                       |" << endl;
            cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
            cout << "\t\t\t|      CCCD      |   So Tai Khoan   |  Loai Tai Khoan  |      So Du      |   Mat Khau   |" << endl;
            cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
            users.getLinkListUser()->Search(U)->data.showAccount();
            cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
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
            cout << "\t\t\t+=================================================================================================================================+" << endl;
            cout << "\t\t\t|                                                   ** THONG TIN NGUOI DUNG **                                                    |" << endl;
            cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;
            cout << "\t\t\t|      CCCD      |          HoVaTen         |    Ngay Sinh    |    So Dien Thoai   |            Dia Chi           |   Gioi Tinh   |" << endl;
            cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;
            users.getLinkListUser()->Search(U)->data.Show();
            cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;
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
            cout<<"DA CAP NHA THANH CONG THONG TIN CUA NGUOI DUNG "<< cccd <<endl;
            system("pause");
            return ;
    }

    


}

void AdminQLNH::TraCuuDanhSachNganHang(QLNH& banks)
{
    string chon;
    start:
        system("cls");
        banks.showBank();
        system("pause");
}

void AdminQLNH::ThemNganHang(QLNH& banks)
{
    string nameBank;
    cout<<"Nhap Ten Ngan Hang Muon Them: "<<endl;
    cin>>nameBank;

    int idb=banks.getCountBank()+1;
    string idBank=to_string(idb);
    switch(idBank.size())
        {
            case 1:
                {
                    idBank="00"+idBank;
                    break;
                }
            case 2:
                {
                    idBank="0"+idBank;
                    break;
                }
        }
    Bank newBank(nameBank,idBank);
    banks.addBank(newBank);
    cout<<"Ban Da Them Thanh Cong Ngan Hang: "<<nameBank<<" Voi Id la "<<idBank<<endl;
    system("pause");
    return ;
}

void AdminQLNH::XoaNganHang(QLNH& banks,QLKH& users,QLTK& accounts)
{
     while(1) 
    {   
        system("cls");
        banks.showBank();
        cout<< "\t\t\t\t  Nhap Id Ngan Hang Ban Muon Xoa(Nhap '-1' De Quay Lai): " << endl;
        string IDB;
        cin>>IDB;
        if(IDB=="-1")
            return ;
        if(IDB.size()>3)
            {
                cout<<"Khong Ton Tai Id Ngan Hang Nay!!!";
                system("Pause");
                continue;
            }
        switch(IDB.size())
        {
            case 1:
                {
                    IDB="00"+IDB;
                    break;
                }
            case 2:
                {
                    IDB="0"+IDB;
                    break;
                }
        }

        Node<Bank> *NB=banks.SearchBank(IDB);
        if(NB==nullptr) 
        {
            cout<<"Khong Ton Tai Ngan Hang!!!";
            system("Pause");
            continue;
        }

        Node<Account> *NA=NB->data.getLinkListAccount()->head;
        while(NA!=nullptr)
        {
            accounts.getLinkListAccount()->Delete(NA->data);
            NA=NA->next;
        }

        Node<User> *NU=NB->data.getLinkListUser()->head;
        while(NU!=nullptr)
        {
            Node<User> *NUusers=users.getLinkListUser()->Search(NU->data);
            
            Node<Account> *NAuser=NU->data.getUserAccount()->head;
            while(NAuser!=nullptr)
            {
                NUusers->data.getUserAccount()->Delete(NAuser->data);
                NAuser=NAuser->next;
            }
            NU=NU->next;
        }
        cout<<"Da Xoa Ngan Hang "<<NB->data.getNameBank()<<" Voi Id "<<IDB<<endl;
        system("pause");
        banks.getLinkListParBank()->Delete(NB->data);
        return ;
    }
}

void AdminQLNH::CapNhapThongTinNganHang(QLNH& banks){
    
    while(1) 
    {   
        system("cls");
        banks.showBank();
        string IDB;
        cout<< "\t\t\t\t  Nhap Id Ngan Hang Ban Muon Chinh Sua(Nhap '-1' De Quay Lai): " << endl;
        cin>>IDB;
        if(IDB=="-1")
            return ;
        if(IDB.size()>3)
            {
                cout<<"Khong Ton Tai Id Ngan Hang Nay!!!";
                system("Pause");
                continue;
            }
        switch(IDB.size())
        {
            case 1:
                {
                    IDB="00"+IDB;
                    break;
                }
            case 2:
                {
                    IDB="0"+IDB;
                    break;
                }
        }
        cout<<"Nhap Ten Ngan Hang Moi :";
        string NameBank;
        cin>>NameBank;
        Node<Bank> *NB=banks.SearchBank(IDB);
        NB->data.setNameBank(NameBank);
        cout<<"Ban Da Chinh Sua Thanh Cong Ngan Hang Co ID: "<<IDB<<endl;
        system("pause");
        return ;
    }
    
    
}

void AdminQLNH::TraCuuDanhSachTaiKhoan(QLNH& banks)
{
    while(1) 
    {   
        banks.showBank();
        cout<< "\t\t\t\t  Nhap Id Ngan Hang Ban Muon Tra Cuu(Nhap '-1' De Quay Lai): " << endl;
        string IDB;
        cin>>IDB;
        if(IDB=="-1")
            return ;
        if(IDB.size()>3)
            {
                cout<<"Khong Ton Tai Id Ngan Hang Nay!!!";
                system("Pause");
                continue;
            }
        switch(IDB.size())
        {
            case 1:
                {
                    IDB="00"+IDB;
                    break;
                }
            case 2:
                {
                    IDB="0"+IDB;
                    break;
                }
        }
        Node<Bank> *NB=banks.SearchBank(IDB);
        if(NB==nullptr) 
        {
            cout<<"Khong Ton Tai Ngan Hang!!!";
            system("Pause");
            continue;
        }
        system("cls");
        string chon;
        start:
        cout<<"Ban Co Muon Sap Xep Tai Khoan Theo So Du Tang Dan('Exit' De Quay Lai): "<<endl;
        cout<<"\t\t\t\t Y:Dong Y"<<endl;
        cout<<"\t\t\t\t N:Khong Dong Y"<<endl;
        cin>>chon;
        if(chon=="exit"||chon=="Exit")
            return ;
        if(chon!="Y"&&chon!="N"&&chon!="y"&&chon!="n")
            {
                cout<<"Vui Long Nhap Dung Cu Phap!!!"<<endl;
                system("Pause");
                goto start;
            }
        else {
            if(chon=="Y"||chon=="y")
                {
                    NB->data.getLinkListAccount()->Sort();
                    cout << "\t\t\t+=======================================================================================+" << endl;
                    cout << "\t\t\t|                         **DANH SACH TAI KHOAN CUA KHACH HANG**                        |" << endl;
                    cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
                    cout << "\t\t\t|      CCCD      |   So Tai Khoan   |  Loai Tai Khoan  |      So Du      |   Mat Khau   |" << endl;
                    cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
                    if(NB->data.getLinkListAccount()->head==nullptr){
                        cout<<endl;
                        cout<<"\t\t\t\t";
                        cout<<"Khong Co Tai Khoan Nao Cua Ngan Hang Nay!!!"<<endl;
                        system("pause");
                        return ;
                    }
                    else 
                    {
                        NB->data.getLinkListAccount()->Show();
                        cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
                    }
                    system("pause");
                }
            else 
                {
                    cout << "\t\t\t+=======================================================================================+" << endl;
                    cout << "\t\t\t|                         **DANH SACH TAI KHOAN CUA KHACH HANG**                        |" << endl;
                    cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
                    cout << "\t\t\t|      CCCD      |   So Tai Khoan   |  Loai Tai Khoan  |      So Du      |   Mat Khau   |" << endl;
                    cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
                    if(NB->data.getLinkListAccount()->head==nullptr){
                        cout<<endl;
                        cout<<"\t\t\t\t";
                        cout<<"Ngan Hang "<<NB->data.getNameBank()<<" Khong Co Tai Khoan !!!"<<endl;
                        system("pause");
                        return ;
                    }
                    else 
                    {
                        NB->data.getLinkListAccount()->Show();
                        cout << "\t\t\t+================+==================+==================+=================+==============+" << endl;
                    }
                    system("pause");
                }
                return ;
        }
    }
}


void AdminQLNH::TraCuuDanhSachKhachHang(QLNH& banks)
{
    while(1) 
    {   
        banks.showBank();
        cout<< "\t\t\t\t  Nhap Id Ngan Hang Ban Muon Tra Cuu(Nhap '-1' De Quay Lai): " << endl;
        string IDB;
        cin>>IDB;
        if(IDB=="-1")
            return ;
        if(IDB.size()>3)
            {
                cout<<"Khong Ton Tai Id Ngan Hang Nay!!!";
                system("Pause");
                continue;
            }
        switch(IDB.size())
        {
            case 1:
                {
                    IDB="00"+IDB;
                    break;
                }
            case 2:
                {
                    IDB="0"+IDB;
                    break;
                }
        }
        Node<Bank> *NB=banks.SearchBank(IDB);
        if(NB==nullptr) 
        {
            cout<<"Khong Ton Tai Ngan Hang!!!";
            system("Pause");
            continue;
        }
        system("cls");
        string chon;
        start:
        cout<<"Ban Co Muon Sap Xep Ten Khach Hang Theo Alphabet ('Exit' De Quay Lai): "<<endl;
        cout<<"\t\t\t\t Y:Dong Y"<<endl;
        cout<<"\t\t\t\t N:Khong Dong Y"<<endl;
        cin>>chon;
        if(chon=="exit"||chon=="Exit")
            return ;
        if(chon!="Y"&&chon!="N"&&chon!="y"&&chon!="n")
            {
                cout<<"Vui Long Nhap Dung Cu Phap!!!"<<endl;
                system("Pause");
                goto start;
            }
        else {
            if(chon=="Y"||chon=="y")
                {
                    NB->data.getLinkListUser()->Sort();
                    cout << "\t\t\t+=================================================================================================================================+" << endl;
                    cout << "\t\t\t|                                                   ** DANH SACH NGUOI DUNG **                                                    |" << endl;
                    cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;
                    cout << "\t\t\t|      CCCD      |          HoVaTen         |    Ngay Sinh    |    So Dien Thoai   |            Dia Chi           |   Gioi Tinh   |" << endl;
                    cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;
                    if(NB->data.getLinkListUser()->head==nullptr){
                        cout<<endl;
                        cout<<"\t\t\t\t";
                        cout<<"Ngan Hang "<<NB->data.getNameBank()<<" Khong Co Nguoi Dung !!!"<<endl;
                        system("pause");
                        return ;
                    }
                    else 
                    {
                        NB->data.getLinkListUser()->Show();
                        cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;
                    }
                   
                    system("pause");
                }
            else 
                {
                    cout << "\t\t\t+=================================================================================================================================+" << endl;
                    cout << "\t\t\t|                                                   ** DANH SACH NGUOI DUNG **                                                    |" << endl;
                    cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;
                    cout << "\t\t\t|      CCCD      |          HoVaTen         |    Ngay Sinh    |    So Dien Thoai   |            Dia Chi           |   Gioi Tinh   |" << endl;
                    cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;
                    if(NB->data.getLinkListUser()->head==nullptr){
                        cout<<endl;
                        cout<<"\t\t\t\t";
                        cout<<"Ngan Hang "<<NB->data.getNameBank()<<" Khong Co Nguoi Dung !!!"<<endl;
                        system("pause");
                        return ;
                    }
                    else 
                    {
                        NB->data.getLinkListUser()->Show();
                        cout << "\t\t\t+================+==========================+=================+====================+==============================+===============+" << endl;
                    }
                    system("pause");
                }
                return ;
        }
    }
}

void AdminQLNH::TongDoanhThu(QLNH& banks)
{
        Node<Bank> *NB=banks.getLinkListParBank()->head;
        cout << "\t\t\t\t\t+=======================================+====================+" << endl;
        cout << "\t\t\t\t\t|                ** DANH SACH NGAN HANG **                   |" << endl;
        cout << "\t\t\t\t\t+=====+=================================+====================+" << endl;
        cout << "\t\t\t\t\t| ID  |        Ten ngan hang            |    Doanh Thu       |" << endl;
        cout << "\t\t\t\t\t+=====+=================================+====================+" << endl;
        while(NB!=nullptr)
        {
            cout<<"\t\t\t\t\t";
            cout <<"| "<< NB->data.getIdBank() << " |          " << left << setw(22) << NB->data.getNameBank()  ;
            cout << " | " << setw(15) << left << NB->data.TotalAmount()<<"VND"<<" |";
            cout<<endl;
            NB=NB->next;
        }
        cout << "\t\t\t\t\t+=====+=================================+====================+" << endl;
        system("pause");
    return ;      
}


void AdminQLNH::ThongKeSoLuongNapTien(QLNH& banks)
{
    while(1) 
    {   
        banks.showBank();
        cout<< "\t\t\t\t  Nhap Id Ngan Hang Ban Muon Tra Cuu Giao Dich Nap Tien(Nhap '-1' De Quay Lai): " << endl;
        string IDB;
        int check = 0 ;
        cin>>IDB;
        if(IDB=="-1")
            return ;
        if(IDB.size()>3)
            {
                cout<<"Khong Ton Tai Id Ngan Hang Nay!!!";
                system("Pause");
                continue;
            }
        switch(IDB.size())
        {
            case 1:
                {
                    IDB="00"+IDB;
                    break;
                }
            case 2:
                {
                    IDB="0"+IDB;
                    break;
                }
        }
        Node<Bank> *NB=banks.SearchBank(IDB);
        if(NB==nullptr) 
        {
            cout<<"Khong Ton Tai Ngan Hang!!!";
            system("Pause");
            continue;
        }
        system("cls");
        string folderPath = "DataBase/GiaoDich";
        // Kiểm tra xem thư mục có tồn tại không
        if (!fs::exists(folderPath) || !fs::is_directory(folderPath)) {
            std::cerr << "Khong Ton Tai Thu Muc " << std::endl;
            return ;
        }
        // Duyệt qua tất cả các file trong thư mục
        cout << "\t\t\t+================================================================================================================+" << endl;
        cout << "\t\t\t|                                             ** LICH SU NAP TIEN **                                             |" << endl;
        cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
        cout << "\t\t\t|   LOAI GD   |   STK THUC HIEN   | STK CHUYEN TIEN  | TEN NGAN HANG |     SO TIEN     |   THOI GIAN THUC HIEN   |" << endl;
        cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            // Kiểm tra xem là file .txt hay không
            if (entry.path().extension() == ".txt") {
                // In tên file
                string name =entry.path().filename().stem().string().substr(0,3);
                if(name==IDB){
                    check++;
                    string fileName = folderPath + "/" + entry.path().filename().string();
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
                            if(Type == "Nap tien"){
                            cout << "\t\t\t| " << setw(12) << left << Type << "| " << setw(18) << left << IDSourceAccount << "| " << setw(17) << left << IDDesAccount << "| " << setw(14) << left << NameBank << "| " << setw(12) << left << Amount <<" VND"<< "| " << setw(10) << left << Time << "|" << endl;
                            }
                        }
                //  system("pause");
                }
            }
        }
        if(check==0)
        {
            cout<<endl;
            cout<<"\t\t\t\t";
            cout<<"Ngan Hang "<<NB->data.getNameBank()<<" Khong Co Giao Dich Nap Tien !!!"<<endl;
            system("pause");
            return ;
        }
        else 
        {
            cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
            system("pause");
            // system("cls");
            return ;
        }
    }
}


void AdminQLNH::ThongKeSoLuongRutTien(QLNH& banks)
{
    while(1) 
    {   
        banks.showBank();
        cout<< "\t\t\t\t  Nhap Id Ngan Hang Ban Muon Tra Cuu Giao Dich Rut Tien(Nhap '-1' De Quay Lai): " << endl;
        int check = 0 ;
        string IDB;
        cin>>IDB;
        if(IDB=="-1")
            return ;
        if(IDB.size()>3)
            {
                cout<<"Khong Ton Tai Id Ngan Hang Nay!!!";
                system("Pause");
                continue;
            }
        switch(IDB.size())
        {
            case 1:
                {
                    IDB="00"+IDB;
                    break;
                }
            case 2:
                {
                    IDB="0"+IDB;
                    break;
                }
        }
        Node<Bank> *NB=banks.SearchBank(IDB);
        if(NB==nullptr) 
        {
            cout<<"Khong Ton Tai Ngan Hang!!!";
            system("Pause");
            continue;
        }
        system("cls");
        string folderPath = "DataBase/GiaoDich";
        // Kiểm tra xem thư mục có tồn tại không
        if (!fs::exists(folderPath) || !fs::is_directory(folderPath)) {
            std::cerr << "Khong Ton Tai Thu Muc " << std::endl;
            return ;
        }
        // Duyệt qua tất cả các file trong thư mục
        cout << "\t\t\t+================================================================================================================+" << endl;
        cout << "\t\t\t|                                            ** LICH SU RUT TIEN **                                              |" << endl;
        cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
        cout << "\t\t\t|   LOAI GD   |   STK THUC HIEN   | STK CHUYEN TIEN  | TEN NGAN HANG |     SO TIEN     |   THOI GIAN THUC HIEN   |" << endl;
        cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            // Kiểm tra xem là file .txt hay không
            if (entry.path().extension() == ".txt") {
                // In tên file
                string name =entry.path().filename().stem().string().substr(0,3);
                if(name==IDB){
                    check++;
                    string fileName = folderPath + "/" + entry.path().filename().string();
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
                            if(Type == "Rut tien"){
                            cout << "\t\t\t| " << setw(12) << left << Type << "| " << setw(18) << left << IDSourceAccount << "| " << setw(17) << left << IDDesAccount << "| " << setw(14) << left << NameBank << "| " << setw(12) << left << Amount <<" VND"<< "| " << setw(10) << left << Time << "|" << endl;
                            }
                        }
                //  system("pause");
                }
            }
        }
        if(check==0)
        {
            cout<<endl;
            cout<<"\t\t\t\t";
            cout<<"Ngan Hang "<<NB->data.getNameBank()<<" Khong Co Giao Dich Rut Tien !!!"<<endl;
            system("pause");
            return ;
        }
        else 
        {
            cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
            system("pause");
            // system("cls");
            return ;
        }
    }
}


void AdminQLNH::ThongKeSoLuongChuyenTien(QLNH& banks)
{
    while(1) 
    {   
        banks.showBank();
        cout<< "\t\t\t\t  Nhap Id Ngan Hang Ban Muon Tra Cuu Giao Dich Chuyen Tien(Nhap '-1' De Quay Lai): " << endl;
        int check = 0 ;
        string IDB;
        cin>>IDB;
        if(IDB=="-1")
            return ;
        if(IDB.size()>3)
            {
                cout<<"Khong Ton Tai Id Ngan Hang Nay!!!";
                system("Pause");
                continue;
            }
        switch(IDB.size())
        {
            case 1:
                {
                    IDB="00"+IDB;
                    break;
                }
            case 2:
                {
                    IDB="0"+IDB;
                    break;
                }
        }
        Node<Bank> *NB=banks.SearchBank(IDB);
        if(NB==nullptr) 
        {
            cout<<"Khong Ton Tai Ngan Hang!!!";
            system("Pause");
            continue;
        }
        system("cls");
        string folderPath = "DataBase/GiaoDich";
        // Kiểm tra xem thư mục có tồn tại không
        if (!fs::exists(folderPath) || !fs::is_directory(folderPath)) {
            std::cerr << "Khong Ton Tai Thu Muc " << std::endl;
            return ;
        }
        // Duyệt qua tất cả các file trong thư mục
        cout << "\t\t\t+================================================================================================================+" << endl;
        cout << "\t\t\t|                                            ** LICH SU CHUYEN TIEN **                                           |" << endl;
        cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
        cout << "\t\t\t|   LOAI GD   |   STK THUC HIEN   | STK CHUYEN TIEN  | TEN NGAN HANG |     SO TIEN     |   THOI GIAN THUC HIEN   |" << endl;
        cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            // Kiểm tra xem là file .txt hay không
            if (entry.path().extension() == ".txt") {
                // In tên file
                string name =entry.path().filename().stem().string().substr(0,3);
                if(name==IDB){
                    check++;
                    string fileName = folderPath + "/" + entry.path().filename().string();
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
                            if(Type == "Chuyen tien"){
                            cout << "\t\t\t| " << setw(12) << left << Type << "| " << setw(18) << left << IDSourceAccount << "| " << setw(17) << left << IDDesAccount << "| " << setw(14) << left << NameBank << "| " << setw(12) << left << Amount <<" VND"<< "| " << setw(10) << left << Time << "|" << endl;
                            }
                        }
                //  system("pause");
                }
            }
        }
        if(check==0)
        {
            cout<<endl;
            cout<<"\t\t\t\t";
            cout<<"Ngan Hang "<<NB->data.getNameBank()<<" Khong Co Giao Dich Chuyen Tien !!!"<<endl;
            system("pause");
            return ;
        }
        else 
        {
            cout << "\t\t\t+=============+===================+==================+===============+=================+=========================+" << endl;
            system("pause");
            // system("cls");
            return ;
        }
    }
}
