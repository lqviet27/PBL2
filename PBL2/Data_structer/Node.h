#pragma once
#include<iostream>
using namespace std;
template <class T>
class Node
{
    private:
        T data;
        Node *next;
        Node *prev;
    public:
        Node(const T& );
        void Show();
        bool operator==(const Node&);
        void operator=(const Node&);
};

