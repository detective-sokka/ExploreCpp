#include <atomic>
#include <iostream>

using namespace std;

struct A {
    long x;
};

struct B {
    long x;
    long y;
};

struct C {
    long x;
    int y;
};

struct D {
    int x;
    int y;
    int z;
};

struct E {
    long x;
    long y;
    long z;
};

int main() {
    // atomic<A> a;
    // cout << "A (long), size : " << sizeof(A) << " ; Is lock free? : " << a.is_lock_free();

    cout << "\nA (long), size : " << sizeof(A) << " ; Is lock free? : " << atomic<A>::is_always_lock_free;
    cout << "\nB (long, long), size : " << sizeof(B) << " ; Is lock free? : " << atomic<B>::is_always_lock_free;
    cout << "\nC (long, int), size : " << sizeof(C) << " ; Is lock free? : " << atomic<C>::is_always_lock_free;
    cout << "\nD (int, int, int), size : " << sizeof(D) << " ; Is lock free? : " << atomic<D>::is_always_lock_free;
    cout << "\nE (long, long, long), size : " << sizeof(E) << " ; Is lock free? : " << atomic<E>::is_always_lock_free;
    return 0;
}