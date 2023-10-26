#pragma once
#include<iostream>
using namespace std;
template <class T>
class Node
{
    public:
        T data;
        Node *next;
        Node *prev;
        Node(const T& );
        void Show();
        bool operator==(const Node&);
        void operator=(const Node&);
};





