
#include"../../Object/Bank/Bank.cpp"
using namespace std;
class QLNH
{
private:
    Link_list<Bank> parBank;
public:
    QLNH();
    QLNH(Link_list<Bank>);
    QLNH(const QLNH&);
    ~QLNH();
    void addBank(const Bank&);
    void showBank();
    void Show2();
    Bank SearchBank(const string&);
    void ImportFromFile();
};



