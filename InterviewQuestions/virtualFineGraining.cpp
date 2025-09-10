#include <iostream>

using namespace std;

struct A {
    A() {
        cout << "A()\n";
    }
    ~A() {
        cout << "~A()\n";
    }
};

struct B {
    B() {
        cout << "B()\n";
    }
    ~B() {
        cout << "~B()\n";
    }
};

class Base {
    public:
        Base() {
            cout << "Base()\n";
        }

        virtual ~Base() {
            cout << "~Base()\n";
        }

        void printNumber(int number) {
            cout << "printNumber(int)\n";
        }
};

class Derived : public Base {
    public:
        Derived() : a(), 
                    b() {
            cout << "Derived()\n";
        }
        ~Derived() {
            cout << "~Derived()\n";
        }
        void printNumber(long number) {
            cout << "printNumber(long)\n";
        }

    private:
        B b;
        A a;
};

int main() {
    Base *d = new Derived();
    int l = 10;
    d->printNumber(l);
    delete d;
    return 0;
}