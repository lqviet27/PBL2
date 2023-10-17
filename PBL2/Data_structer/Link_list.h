#include"Node.h"
template<class T>
class Link_list
{
private:
    
public:
    Node<T> *head;
    Link_list();
    void Add(const T& data);
    void Insert(const T& data,const int& index);
    void Show();
    void Delete(const T& data);
    void Delete(const int& index);
    Node<T>* Search(const T& data);
    
};

