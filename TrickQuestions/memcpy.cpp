#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char source[] = "Tutorial";
    char destination[] = "Programiz";

    memcpy(destination, source, sizeof(source));
    cout << destination << "\n";
    cout << sizeof(destination) << " " << sizeof(source) << "\n";
    for (const char &c : destination) {
        
        cout << ((c == '\0') ? '.' : c);
        cout << " ";
    }
    return 0;
}