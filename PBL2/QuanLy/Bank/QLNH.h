
#include"../../Object/Bank/Bank.cpp"

class QLNH
{
private:
    Link_list<Bank> parBank;
public:
    QLNH();
    ~QLNH();
    void addBank(const Bank&);
    void showBank();
};


