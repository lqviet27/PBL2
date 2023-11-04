#pragma once
#include"Link_list.h"
template<typename T>
Link_list<T>::Link_list()
{
    head = nullptr;
}

template<typename T>
Link_list<T>::~Link_list() {
    Node<T> *current = head;
    while (current != nullptr) {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

template<typename T>
void Link_list<T>::Add(const T& data){
    Node<T> *new_node = new Node<T>(data);
    
    if(this->head == nullptr){
        this->head = new_node;
        return;
    }
    else {
        Node<T> *tmp = this->head;
        while(tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next = new_node;
        new_node->prev = tmp;
    }
    
}


template<typename T>
void Link_list<T>::Show(){
    Node<T> *tmp = head;
    if(tmp==nullptr){
            cout<<"Link_list is empty!"<<endl;
        }
    while(tmp != nullptr){
        tmp->Show();
        tmp=tmp->next;
    }
}

template<typename T>
void Link_list<T>::Delete(const T& data){
    Node<T> *tmp = this->head;
    while(tmp != nullptr){
        if(tmp->data == data){
            if(tmp->data == head->data)
            {
                if(tmp->next == nullptr)
                this->head =nullptr; 
                else 
                this->head = head->next;
                break;
            }
            else 
            {
                 
                if(tmp->next != nullptr)
                {
                    tmp->next->prev= tmp->prev;
                    tmp->prev->next= tmp->next;   
                }
                else
                    tmp->prev->next=nullptr;
                break;
            }
        }
        tmp = tmp->next;
    }
}

template<typename T>
Node<T>* Link_list<T>::Search(const T& data){
    Node<T> *tmp = head;
    while(tmp != nullptr){
        if(tmp->data == data){
            return tmp;
        }
        tmp = tmp->next;
    }
    return nullptr;
}