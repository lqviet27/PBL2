#include"../Date_Time/Date.cpp"
#include "../Account_Bank/Account_Bank.cpp"
class KhachHang
{
private:
    int _ID;
    string _Name;
    Date _Birthday;
    string _PhoneNumber;
    string _Address;
    bool _Gender;
    // list <Account_Bank> _ListAccount;

public:
    KhachHang();
    KhachHang(int, string, Date, string, string, bool);
    KhachHang(const KhachHang &);
    ~KhachHang();
    void ShowKhachHang();
    int ID();
    void ID(int);
    void Name(string);
    void Birthday(Date);
    void PhoneNumber(string);
    void Address(string);
    void Gender(bool);
    friend istream &operator>>(istream &, KhachHang &);
    void InsertObjecttoFile(ofstream &);
};