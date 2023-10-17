#include"Link_list.h"
template<class T>
Link_list<T>::Link_list()
{
    head = nullptr;
}
template<class T>
void Link_list<T>::Add(const T& data){
    Node<T> *new_node = new Node<T>(data);
    if(this->head == nullptr){
        this->head = new_node;
        return;
    }
    else {
    new_node->next=head;
    head->prev=new_node;
    head = new_node;
    }
}


template<class T>
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

template<class T>
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

template<class T>
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