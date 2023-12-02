#pragma once
#include"Node.h"
template<class T>
Node<T>::Node(const T& data){
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}
template<class T>
void Node<T>::Show(){
    this->data.Show();
}
template<class T>
bool Node<T>::operator==(const Node& node)
{
    return (this->data == node.data);
} 
template<class T>
void Node<T>::operator=(const Node& node)
{
    this->data = node.data;
    this->next = node.next;
    this->prev = node.prev;
}