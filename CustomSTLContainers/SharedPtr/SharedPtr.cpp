#include <iostream>

template<typename T>
class SharedPtr {

public:
    T* m_ptr;
    int* m_ctr;

    SharedPtr() : m_ptr{nullptr},
                  m_ctr{nullptr} {
    }

    SharedPtr(T* ptr) : m_ptr{ptr},
                        m_ctr{new int(1)} {
    }

    SharedPtr(const SharedPtr<T>& obj) { // Copy constructor
        m_ptr = obj.m_ptr;
        m_ctr = obj.m_ctr;

        if (m_ptr)
            (*m_ctr)++;
    }

    SharedPtr(SharedPtr<T>&& obj) : m_ptr{obj.m_ptr},
                                       m_ctr{obj.m_ctr} { // Move constructor
        obj.m_ptr = nullptr;
        obj.m_ctr = nullptr;
    }

    SharedPtr& operator=(const SharedPtr<T>& obj) { // Copy assignment operator
        if (&obj == this)
            return *this;

        m_ptr = obj.m_ptr;
        m_ctr = obj.m_ctr;

        if (m_ctr)
            (*m_ctr)++;

        return *this;
    }

    SharedPtr& operator=(SharedPtr<T> && obj) { // Move assignment operator
        if (&obj == this)
            return *this;

        m_ptr = obj.m_ptr;
        m_ctr = obj.m_ctr;

        obj.m_ctr = nullptr;
        obj.m_ptr = nullptr;

        return *this;
    }

    T& operator * () const {
        return *m_ptr;
    }

    T* operator -> () const {
        return m_ptr;
    }

    int getCount() {
        if (!m_ctr)
            return -1;

        return *m_ctr;
    }

    ~SharedPtr() {       
        
        if (m_ctr && --(*m_ctr) == 0) {            
            delete m_ptr;
            delete m_ctr;
        }
    }
};

int test_shared_ptr()
{
    SharedPtr<int> a{new int(1)}; // Param ctor
    SharedPtr<int> b;   // Def ctor
    b = a; // Assignment operator
    SharedPtr<int> c{b}; // Copy ctor
    SharedPtr<int> d = std::move(c);
    SharedPtr<int> e;
    e = std::move(d);

    std::cout << "\nA Result = "<< (*a ? std::to_string(*a) : "") << " ; Counter = " << a.getCount();
    std::cout << "\nB Result = "<< (*b ? std::to_string(*b) : "") << " ; Counter = " << b.getCount();
    // std::cout << "\nC Result = "<< (*c ? std::to_string(*c) : "") << " ; Counter = " << c.getCount();
    // std::cout << "\nD Result = "<< (*d ? std::to_string(*d) : "") << " ; Counter = " << d.getCount();
    std::cout << "\nE Result = "<< (*e ? std::to_string(*e) : "") << " ; Counter = " << e.getCount();

    return 0;
}