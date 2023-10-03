#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

typedef Node node;

node* makenode(int x) {
    node* newnode = new node;
    newnode->data = x;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    return newnode;
}

void duyet(node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void pushFront(node** head, int x) {
    node* newnode = makenode(x);
    newnode->next = (*head);
    if (*head != nullptr) {
        (*head)->prev = newnode;
    }
    (*head) = newnode;
}

void pushBack(node** head, int x) {
    node* newnode = makenode(x);
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

int size(node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

void insert(node** head, int k, int x) {
    int n = size(*head);
    if (k < 1 || k > n + 1)
        return;
    if (k == 1) {
        pushFront(head, x);
        return;
    }
    node* temp = *head;
    for (int i = 1; i <= k - 1; i++) {
        temp = temp->next;
    }
    node* newnode = makenode(x);
    newnode->next = temp;
    temp->prev->next = newnode;
    newnode->prev = temp->prev;
    temp->prev = newnode;
}

void deleteFront(node** head) {
    if (*head == nullptr)
        return;
    node* temp = *head;
    *head = (*head)->next;
    delete temp;
}

void deleteBack(node** head) {
    if (*head == nullptr)
        return;
    node* temp = *head;
    if (temp->next == nullptr) {
        *head = nullptr;
        delete temp;
        return;
    }
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    node* last = temp->next;
    temp->next = nullptr;
    delete last;
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

int main() {
    node* head = nullptr;
    while (true) {
        cout << "-----------------------------------------" << endl;
        cout << "1. Them vao dau" << endl;
        cout << "2. Them vao cuoi" << endl;
        cout << "3. Them vao vi tri k" << endl;
        cout << "4. xuat danh sach lien ket" << endl;
        cout << "5. xoa node dau danh sach lien ket" << endl;
        cout << "6. xoa node cuoi danh sach lien ket" << endl;
        cout << "7. xoa node k danh sach lien ket" << endl;
        cout << "0. Thoat" << endl;
        cout << "-----------------------------------------" << endl;
        int n;
        cout << "Nhap lua chon: ";
        cin >> n;
        if (n == 1) {
            int x;
            cout << "nhap x: ";
            cin >> x;
            pushFront(&head, x);
        }
        if (n == 2) {
            int x;
            cout << "nhap x: ";
            cin >> x;
            pushBack(&head, x);
        }
        if (n == 3) {
            int x, k;
            cout << "nhap k: ";
            cin >> k;
            cout << "nhap x: ";
            cin >> x;
            insert(&head, k, x);
        }

        if (n == 4) {
            duyet(head);
        }
        if (n == 5) {
            deleteFront(&head);
        }
        if (n == 6) {
            deleteBack(&head);
        }
        if (n == 7) {
            int k;
            cout << "nhap k: ";
            cin >> k;
            erase(&head, k);
        }
        if (n == 0)
            break;
    }
    return 0;
}
