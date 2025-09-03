#include <iostream>

using namespace std;

class A {
    public: 
        virtual void foo(int x = 1) {
            std::cout << x;
        }
};

class B : public A {
    public: 
        virtual void foo(int x = 2) { 
            std::cout << x;
        }
};


int main() {
    A *a = new B();
    a->foo();
    return 0;
}
