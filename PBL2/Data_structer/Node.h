#pragma once
#include<iostream>
using namespace std;
template <class T>
class Node
{
    public:
        T data;
        Node<T> *next;
        Node<T> *prev;
        Node(const T& );
        void Show();
        bool operator==(const Node&);
        void operator=(const Node&);
};





