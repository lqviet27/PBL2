#pragma once
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
    void addUser(User&);
    void Sort();
    void showUser();
    Link_list<User> *getLinkListUser();
    Node<User>* SearchUser(const string&);
    bool SearchUser(const User&);
    bool SearchUserAll(User&);
};

