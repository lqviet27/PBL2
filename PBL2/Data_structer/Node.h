template <typename T>
class Node
{

public:
    T data;
    Node *next;
    Node *prev;
    Node(const T& data):data(data),next(nullptr),prev(nullptr){};
};

