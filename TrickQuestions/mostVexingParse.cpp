#include <iostream>

using namespace std;

class Animal {
    public:
        Animal() {
            // a();
            cout << "\nConstuctor of animal called.";
        }
};

int main() {
    Animal a(); // Mistaken for function declaration.
    a();
    cout << "\nEnd of main.";
    return 0;
}

// void getAnimal () {
//     a(); // Causes compilation error.
// }

Animal a() {
    cout << "\n a Function definintion";
    return {};
}