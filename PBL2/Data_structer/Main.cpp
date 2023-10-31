#include"Link_list.cpp"
#include"Node.cpp"
#include "../Object/Account/Account.h"

using namespace std; 

int main()
{
    Link_list <Account> AC;
    Account a1("001","1","666",true,10000000);
    Account a2("001","2","666",true,10000000);

    Account a3("001","3","666",true,10000000);

    Account a4("001","4","666",true,10000000);
    Account a5("001","5","666",true,10000000);
    AC.Add(a1);
    AC.Add(a2);
    AC.Add(a3);
    AC.Add(a4);
    AC.Show();
    AC.Delete(a3);
    AC.Show();
}