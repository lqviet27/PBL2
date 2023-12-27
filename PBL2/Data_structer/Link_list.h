#include"Node.h"
template<typename T>
class Link_list
{ 
    public:
        Node<T> *head;
        Link_list();
        Link_list(const Link_list<T>&);
        ~Link_list();
        void Add(const T& data);
        void Show();
        void Delete(const T& data);
        void operator=(const Link_list<T>);
        Node<T>* Search(const T& data);
        void Sort();
};
