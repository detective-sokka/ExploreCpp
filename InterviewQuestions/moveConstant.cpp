#include <iostream>

using namespace std;

class CustomInt {
    public:
        explicit CustomInt(int param) : m_data {param} {
        }

        CustomInt(const CustomInt &) = delete;
        CustomInt(CustomInt &&) = delete;

        CustomInt& operator=(const CustomInt &param) noexcept {

            cout << "\nAssignment operator called.";
            if (&param != this)
                m_data = param.m_data;
            
            return *this;
        }

        CustomInt& operator=(CustomInt &&param) noexcept {      
            
            cout << "\nMove Assignment operator called.";
            if (&param != this) 
                m_data = std::move(param.m_data);
            return *this;
        }

        int getData() const {
            return m_data;
        }

        ~CustomInt() = default;

    private: 
        int m_data;
};

int main() {
    // const CustomInt a{2};
    CustomInt a{2};
    CustomInt b{3};
    b = std::move(a);
    cout << "\nA's value : " << a.getData();
    cout << "\nB's value : " << b.getData();
    return 0;
}