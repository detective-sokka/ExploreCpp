#include <iostream>

using namespace std;

class Base {
    public:
        virtual void getValue() const {
            cout << "Base's getValue().";
        }
};

class Derived : public Base {
    public:
        void getValue() const {
            cout << "Derived's getValue().";
        }
};

void callGetValue(Base obj) {
    obj.getValue();
}

int main() {
    Derived d; 
    callGetValue(d);
    return 0;
}