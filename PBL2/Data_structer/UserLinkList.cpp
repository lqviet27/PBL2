#include"../Object/Users/User.cpp"

#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;


struct NodeUser {
    User user;
    NodeUser* next;
    NodeUser* prev;
};

typedef NodeUser nodeUser;

nodeUser makeNodeUser(User x) {
    nodeUser newnode = new NodeUser();
    newnode->user = x;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    return newnode;
}

void push(nodeUser *head,User x) {
    if(head->next != nullptr)
        {
            head->next=makeNodeUser(x);
        }
    else 
        {
            nodeUser newnode = makeNodeUser(x);
            newnode.next = head->next;
            head->next=newnode;
        }
}

int main()
{
    cout<<1;
}