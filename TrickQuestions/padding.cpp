#include <iostream>
using namespace std;

/* While they asked me this basic question, Is it enough to practice these scenarios? */
// Cache line? Thread_local A, B; ? 
// Why is "block" the power of 2, i.e. 2, 4, 8, 16?

/* 
struct Example {
    char c;
    int i;
    char d;
}; // Size = 12

Consider this struct and assume 4-byte alignment:

struct L {
    short s;
    int i;
    char c;
};
What is the offset of member c?

a) 4
b) 6
c) 8
d) 10

5. What change reduces the size of the following struct?

struct N {
    char c1;
    char c2;
    double d;
};
a) Place double d first
b) Merge c1 and c2 into a short
c) Use #pragma pack(1)
d) All of the above

struct B {
    short s;
    char c;
    int i;
};
// What is sizeof(B)?
// a) 7
// b) 8
// c) 12
// d) 10

struct C {
    char c;
    double d;
    int i;
};
// What is sizeof(C)?
// a) 13
// b) 16
// c) 20
// d) 24

struct D {
    double d;
    int i;
    char c;
};
// What is sizeof(D)?
// a) 13
// b) 16
// c) 20
// d) 24

How can the order of members in a struct affect its overall size due to padding?
a) It never affects the size
b) Only if struct has more than two members
c) It can increase or decrease the amount of padding required
d) It only matters if #pragma pack is used

struct E {
    int i;
    char c1;
    char c2;
};
a) 6
b) 8
c) 9
d) 12

struct F {
    char c;
    double d;
    char c2;
};
a) 18
b) 16
c) 24
d) 20

struct G {
    char c;
    short s;
    int i;
};
a) 7
b) 8
c) 10
d) 12

#pragma pack(1)
struct H {
    char c;
    int i;
    char d;
};
#pragma pack()
a) No padding, size is 6
b) Padding kept, size is 8
c) No padding, size is 9
d) Compiler error

struct I {
    double d;
    int i;
    char c;
};
What is the likely offset of char c if no explicit packing directives are used on a machine with 8-byte double alignment?

a) 12
b) 8
c) 16
d) 20
*/

// Besides #pragma pack(1) no other technique reduces size in this case. 
struct N {
    double d;
    char c1;
    char c2;
};

struct Example {
    int i;
    char c;
    char d;
}; 

struct F {
    double d;
    char c;
    char c2;
};

int main() {
    // cout << sizeof(N);
    // cout << sizeof(Example);
    // cout << sizeof(Example);
    cout << sizeof(F);
    return 0;
}