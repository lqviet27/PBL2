#include"../Account/Account.cpp"
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;


struct NodeAccount {
    Account account;
    NodeAccount* next;
    NodeAccount* prev;
};

typedef NodeAccount nodeAccount;

nodeAccount makeNodeAccount(Account x) {
    nodeAccount newnode = new NodeAccount();
    newnode->account = x;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    return newnode;
}

void push(nodeAccount *head,Account x) {
    if(head->next != nullptr)
        head->next=makeNodeAccount(x);
    else 
        {
            nodeAccount newnode = makeNodeAccount(x);

            newnode.next = head->next;
            head->next=newnode;
        }
}


