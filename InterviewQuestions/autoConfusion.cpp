// Credit - getcracked.io

#include <iostream>
using namespace std;

struct C {
    C() { std::cout << "c"; }
    C(const C&) { std::cout << "C"; }

    void foo() { std::cout << "1"; }
};

struct D {
    D() { std::cout << "d"; }
    D(const C&) { std::cout << "D"; }

    void foo() { std::cout << "2"; }
};


auto TakeTheLOnThisBro(bool flag) {
    return flag ? C{} : D{};
}

int main() {
    TakeTheLOnThisBro(true).foo();
    TakeTheLOnThisBro(false).foo();
}
