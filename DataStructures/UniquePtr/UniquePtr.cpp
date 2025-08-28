#include <iostream>
#include <string>

using namespace std;

template <typename T>
class UniquePtr {

    T *m_ptr;

public:
    UniquePtr() : m_ptr{nullptr} {        
    }

    explicit UniquePtr(T *ptr) : m_ptr{ptr} {        
    }

    UniquePtr(const UniquePtr<T> &obj) = delete;

    UniquePtr& operator=(UniquePtr<T> &obj) = delete; 

    T& operator*() const {
        return *m_ptr;
    }

    T* operator->() const 
    {
        return m_ptr;
    }

    T* getRawPointer() const
    {
        return m_ptr;
    }

    UniquePtr(UniquePtr<T> &&obj) noexcept 
                                : m_ptr{obj.m_ptr} {
        obj.m_ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr<T> &&obj) noexcept 
    {
        if (&obj == this)
            return *this;

        delete m_ptr;
        m_ptr = obj.m_ptr;
        obj.m_ptr = nullptr;

        return *this;
    }

    void reset()
    {
        delete m_ptr;
        m_ptr = nullptr;
    }

    ~UniquePtr()
    {
        delete m_ptr;
        m_ptr = nullptr;
    }
};

int test_unique_ptr()
{
    UniquePtr<int> a{new int(2)}; // param ctor 
    cout << "\n" << *a; // * operator
    // UniquePtr<int> b = a; //copy ctor - compilation error
    UniquePtr<int> b; // default ctor
    // cout << "\n" << *b; // * operator - runtime error
    // b = a; // =operator - compilation error
    UniquePtr<int> c = std::move(a); // move constructor 
    // c = b = a; // =operator   - compilation error
    b = std::move(c);
    cout << "\n" << *b;
    struct Node
    {
        int val;
        Node* next;

    public:
        Node(int val) : val{val}, next{nullptr} {            
        }
    };

    UniquePtr<Node> root{new Node(10)};
    cout << "\n" << root->val;
    
    return 0;
}