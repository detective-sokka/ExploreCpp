#include <initializer_list>
#include <iostream>
#include <string>
#include <utility>

// This came up! The size of vector is 24 bytes because of capacity.

template <typename T>
class Vector {
public: 
    static constexpr size_t start_capacity = 2;

    Vector() : m_data{new T[start_capacity]},
               m_size{0},
               m_capacity{start_capacity} {
    }

    Vector(std::initializer_list<T> list) : m_data{new T[list.size()]},
                                            m_size{0},
                                            m_capacity{list.size()} {
        for (const auto &v : list)
            m_data[m_size++] = v;
    }
 
    Vector(const Vector<T>& obj) : m_data{nullptr}, 
                                   m_size{0},
                                   m_capacity{0} {
        
        T* new_data = nullptr;
        
        try {
            
            new_data = new T[obj.capacity()];
            for (size_t i=0; i < obj.m_size; i++)
                new_data[i] = obj.m_data[i];

        } catch(...){
            
            delete[] new_data;
            throw;
        }

        m_data = new_data;
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;
    }

    Vector(Vector&& obj) noexcept : m_data{obj.m_data}, 
                                    m_size{obj.m_size},
                                    m_capacity{obj.capacity()} {
        
        obj.m_data = nullptr;
        obj.m_size = 0;
        obj.m_capacity = 0;
    }    

    Vector& operator = (const Vector& obj) {
        
        if (&obj == this)
            return *this;

        T* new_data = nullptr;          

        try {
            new_data = new T[obj.m_capacity]; // Allocate
            
            for (int i=0; i < obj.m_size; i++)
                new_data[i] = obj.m_data[i];                      

        } catch (...) {
            delete[] new_data;
            throw;
        }

        delete[] m_data;
        m_data = new_data; // Commit
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;          
        return *this;
    }

    Vector& operator = (Vector&& obj) noexcept {
        if (&obj != this) {
            delete[] m_data;            
            m_data = obj.m_data;
            m_size = obj.m_size;
            m_capacity = obj.m_capacity;

            obj.m_data = nullptr;
            obj.m_size = 0;
            obj.m_capacity = 0;
        }

        return *this;
    }

    size_t size() const noexcept {
        return m_size;
    }

    size_t capacity() const noexcept {
        return m_capacity;
    }

    void clear() noexcept {
        m_size = 0;
    }

    void debug_vector() const noexcept {
        std::cout << "\nContents of vector are : ";
        if (!m_data) 
            return;
        for (size_t i=0; i < m_size; i++)
            std::cout << m_data[i] << ", ";
    }

    T& operator[] (size_t &index) noexcept {
        return m_data[index];
    }

    T& operator[] (const size_t &index) const noexcept { // Does this cause a bug? 
        return m_data[index];
    } 

    void grow() {
        m_capacity = m_capacity ? m_capacity * 2 : start_capacity;
        T *new_data = nullptr;

        try {
            
            new_data = new T[m_capacity];
            for (size_t i = 0; i < m_size; i++)
                new_data[i] = std::move_if_noexcept(m_data[i]);        

        } catch (...) { 
            delete[] new_data;
            throw;
        }

        delete[] m_data;
        m_data = new_data;
    }

    void push_back(const T &value) {
        if (m_size == m_capacity)
            grow();
        
        m_data[m_size++] = value;
    }

    void push_back(T&& value) {
        if (m_size == m_capacity)
            grow();

        m_data[m_size++] = std::move(value);
    }

    void pop_back() noexcept {
        if (m_size)
            m_size--;   
    }   

    template <typename ... Args> 
    void emplace_back(Args&& ... args) {
        if (m_size == m_capacity)
            grow();
        m_data[m_size++] = T(std::forward<Args>(args)...);
    }


    ~Vector() {
        delete[] m_data;
    }    

private: 

    T* m_data;
    size_t m_size;
    size_t m_capacity;
};

void test_custom_vector() {
    Vector<int> a = {1, 2, 3, 4};
    a.debug_vector();
    Vector<int> b = a;
    b.debug_vector();
    Vector<int> c = std::move(a);
    c.debug_vector();    
    a = c;
    a.debug_vector();
    b = std::move(c);
    b[1] = 0;
    c.debug_vector();
    b.debug_vector();

    Vector<std::string> strVec = {"a", "b", "c", "d"};
    strVec.debug_vector();
    Vector<std::string> strVec2 = strVec;
    strVec2.debug_vector();
    Vector<std::string> strVec3 = std::move(strVec);
    strVec3.debug_vector();    
    strVec = strVec3;
    strVec.debug_vector();
    strVec3 = std::move(strVec2);
    strVec3[1] = "z";
    strVec2.debug_vector();
    strVec3.debug_vector();
}

int main() {
    test_custom_vector();
    return 0;
}