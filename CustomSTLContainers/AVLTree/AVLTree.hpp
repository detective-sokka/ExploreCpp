template <typename T>
class AVLTree
{
public: 
    AVLTree () : m_root{nullptr} 
    {
    }

    ~AVLTree ()
    {
    }

    void insert (const T& value)
    {
    }

    void remove (const T& value)
    {
    }

private:
    Node* m_root;
    
    template <typename T>
    struct Node
    {
        T value;
        Node *left;
        Node *right;
        Node *parent;
        size_t height;

        Node (T value, Node *left = nullptr, Node *right = nullptr) : value{value},
                                                                      left{left},
                                                                      right{right},
                                                                      height{0}

        {            
        }
    };

};