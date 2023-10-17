#include"Node.h"
template<typename T>
Node<T>::Node(const T& data){
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}
template<typename T>
void Node<T>::Show(){
    cout<<this->data;
}