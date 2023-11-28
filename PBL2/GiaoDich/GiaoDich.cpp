#include"../QuanLy/Account/QLTK.cpp"
#include"../QuanLy/Bank/QLNH.cpp"
#include"../QuanLy/Users/QLKH.cpp"
#include"../Record_Giaodich/Record_Nap.cpp"
class GiaoDich{
    public:
        static void NapTien(Node<Account>* AC,QLNH &banks,QLKH &users)
        {      
            
            double money;
            cout<<"Nhap So Tien Can Nap Vao Tai Khoan: ";
               while(cin>>money)
               {
                    cout<<endl;
                    if(money>0)
                         break;
                    cout<<"So tien Khong Hop Le!!!"<<endl;
                    cout<<"Vui Long Nhap Lai: ";
               }
            AC->data.setAmount(money);

            bool success=0;
            Link_list<Bank> *B=banks.getLinkListParBank();
            Node<Bank>* NB=B->head;
            while(NB!=nullptr)
            {
               Link_list<User> *U=NB->data.getLinkListUser();
               Node<User> *NU=U->head;
               while(NU!=nullptr)
               {    
                    Node<Account> *A=NU->data.getUserAccount()->Search(AC->data);
                    if(A!=nullptr)
                    {
                         A->data.setAmount(money);
                         success=1;
                         break;
                    }
                    NU=NU->next;
               }
               if(success==1)
                    break;
               NB=NB->next;
            }

               Link_list<User> *X=users.getLinkListUser();
               Node<User> *NX=X->head;
               while(NX!=nullptr)
               {
                    Node<Account> *Y=NX->data.getUserAccount()->Search(AC->data);
                    if(Y!=nullptr)
                    {
                         Y->data.setAmount(money);
                         break;
                    }
                    NX=NX->next;
               }
               Record_Nap *R=new Record_Nap(AC->data.getNumAccount(),NB->data.getNameBank(),money);
               R->RecordtoFile();
        }
        static void RutTien(Node<Account>*)
        {
          //   double money;
          //   cout<<"Nhap So Tien Can Nap Vao Tai Khoan: ";
          //      while(cin>>money)
          //      {
          //           cout<<endl;
          //           if(money>0)
          //                break;
          //           cout<<"So tien Khong Hop Le!!!"<<endl;
          //           cout<<"Vui Long Nhap Lai: ";
          //      }
          //   AC->data.setAmount(money);
        }
        static void TraCuuLichSuGiaoDich(Node<Account>*);
        static void ChuyenTien(Node<Account>*);
};

