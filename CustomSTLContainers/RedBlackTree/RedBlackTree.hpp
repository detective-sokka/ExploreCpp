
template <typename T>
class RedBlackTree {
public:
    RedBlackTree() : m_root{nullptr} 
    {        
    }   
    ~RedBlackTree() 
    {        
    }

    void insert(T value) 
    {
    }

    void rotateLeft(std::unique_ptr<Node> node) 
    {
    }

    void rotateRight(std::unique_ptr<Node> node) 
    {
    }

    std::unique_ptr<Node> search(T value) 
    {
    }

    std::unique_ptr<Node> getRoot() 
    {
        return m_root;
    }

    bool isUncleRed(std::unique_ptr<Node> node) 
    {
    }
    
private:    
    std::unique_ptr<Node> m_root;
    template <typename T>
    struct Node 
    {
        T value;
        Node* left;
        Node* right;
        Node* parent;
        bool isRed;
        
        Node(T val) : value{val}, left{nullptr}, right{nullptr}, parent{nullptr}, isRed{true} 
        {
        }
    };
};