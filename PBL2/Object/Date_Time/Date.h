#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
protected:
    int _Day, _Month, _Year;

public:
    Date();
    Date(int, int, int);
    Date(const Date &);
    ~Date();
    int getDay();
    int getMonth();
    int getYear();
    void ShowDate();
    friend ostream &operator<<(ostream &, const Date &);
    friend istream &operator>>(istream &, Date &);
    bool CheckDate(Date );
};