
#include"../../Object/Bank/Bank.cpp"
using namespace std;
class QLNH
{
private:
    Link_list<Bank> parBank;
public:
    QLNH();
    ~QLNH();
    void addBank(const Bank&);
    void showBank();
    Bank SearchBank(const string&);
};


