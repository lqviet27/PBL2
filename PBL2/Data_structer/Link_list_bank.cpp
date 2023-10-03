#include <iostream>
using namespace std;
#include"../Object/Account/Account.cpp"

struct Node {
    Account data;
    Node* next;
    Node* prev;
};
typedef Node node;



node* make_Node(Account acc) {
    node* newnode = new node;
    newnode->data = acc;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    return newnode;
}

int size(node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

void push_Back(node** head, Account acc) {
    node* newnode = make_Node(acc);
    node* temp = *head;
    if (*head == nullptr) {
        *head = newnode;
        return;
    }
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void deleteFront(node** head) {
    if (*head == nullptr)
        return;
    node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

void erase(node** head, int k) {
    int n = size(*head);
    if (k < 1 || k > n)
        return;
    if (k == 1) {
        deleteFront(head);
        return;
    }
    node* temp = *head;
    for (int i = 1; i <= k - 2; i++) {
        temp = temp->next;
    }
    node* kth = temp->next;
    temp->next = kth->next;
    delete kth;
}


int main(){
    Account a1("11111","1",true);
    Account a2("22222","2",true);
    Account a3("33333","3",true);
    Account a4("44444","4",true);
    Account a5("55555","5",true);

    node* head = nullptr;
    push_Back(&head,a1);
    push_Back(&head,a2);
    push_Back(&head,a3);
    push_Back(&head,a4);
    push_Back(&head,a5);


    for(int i=0;i<5;i++){
        head->data.Show();
        cout<<endl;
        head=head->next;
    }
}


