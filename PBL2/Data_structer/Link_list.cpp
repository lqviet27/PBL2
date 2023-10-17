#include"Link_list.h"
template<typename T>
Link_list<T>::Link_list()
{
    head = nullptr;
}
template<typename T>
void Link_list<T>::Add(const T& data){
    Node<T> *new_node = new Node<T>(data);
    if(head == nullptr){
        head = new_node;
        return;
    }
    Node<T> *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

template<typename T>
void Link_list<T>::Insert(const T& data,const int& index){

}

template<typename T>
void Link_list<T>::Show(){
    Node<T> *tmp = head;
    while(tmp != nullptr){
        tmp->Show();
        cout<<" ";
    }
}

template<typename T>
void Link_list<T>::Delete(const T& data){
    Node<T> *tmp = head;
    while(tmp->next != nullptr){
        if(tmp->data == data){
            if(tmp->next == nullptr){
                tmp->prev->next = tmp;
            }
            if(tmp->prev == nullptr){
                tmp->next->prev = tmp;
            }
        }
        tmp = tmp->next;
    }
    tmp->prev->next = tmp->next;
    tmp->next = tmp->prev;
    delete tmp;
}

template<typename T>
void Link_list<T>::Delete(const int& index){

}

template<typename T>
bool Link_list<T>::Search(const T& data){
    Node<T> *tmp = head;
    while(tmp != nullptr){
        if(tmp->data == data){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}