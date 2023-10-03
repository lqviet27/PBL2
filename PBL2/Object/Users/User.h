#include"../Date_Time/Date.cpp"

class User
{
private:
    string _Name;
    Date _Birthday;
    string _PhoneNumber;
    string _Address;
    bool _Gender;
    // list <Account_Bank> _ListAccount;

public:
    User();
    User(string, Date, string, string, bool);
    User(const User &);
    ~User();
    void ShowUser();
    void Name(string);
    void Birthday(Date);
    void PhoneNumber(string);
    void Address(string);
    void Gender(bool);
    friend istream &operator>>(istream &, User &);
    void InsertObjecttoFile(ofstream &);
};