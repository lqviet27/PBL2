
#include"../../Object/Users/User.cpp"
#include"../../Data_structer/Link_list.cpp"
#include"../../Data_structer/Node.cpp"


using namespace std;
class QLKH
{
private:
    Link_list<User> parUser;
public:
    QLKH();
    QLKH(Link_list<User>);
    QLKH(const QLKH&);
    ~QLKH();
    void addUser(const User&);
    void showUser();
    Link_list<User> getLinkListUser();
    User SearchUser(const string&);
    void ImportFromFile();
};

