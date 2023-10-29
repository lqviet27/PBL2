
#include"Node.h"
template<typename T>
class Link_list
{ 
    public:
        Node<T> *head;
        Link_list();
        void Add(const T& data);
        void Show();
        void Delete(const T& data);
        Node<T>* Search(const T& data);
    
};

