#include <iostream>

using namespace std;
#include "../Object/Users/User.cpp"

struct Node {
    User data;
    Node* next;
    Node* prev;
};
typedef Node node;



node* make_Node(User u) {
    node* newnode = new node;
    newnode->data = u;
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

void push_Back(node** head, User u) {
    node* newnode = make_Node(u);
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
    Date birth(1,1,2000);
    User u1("viet",birth,"0123444444","Da Nang",0);
    User u2("duc",birth,"09013214124","Quang Nam",0);
    User u3("duyet",birth,"0183001234","Quang Binh",0);
    User u4("toan",birth,"0814151617","Da Nang",0);
    User u5("tuan",birth,"0771235612","Quang Nam",0);

    node* head = nullptr;
    push_Back(&head,u1);
    push_Back(&head,u2);
    push_Back(&head,u3);
    push_Back(&head,u4);
    push_Back(&head,u5);


    for(int i=0;i<5;i++){
        head->data.ShowUser();
        cout<<endl;
        head=head->next;
    }
    
}


