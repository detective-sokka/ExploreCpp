#include <iostream>
#include <malloc/malloc.h>

using namespace std;

int main() {
    char *a = (char*) malloc(sizeof(char) * 7);
    char *b = (char*) malloc(sizeof(char) * 8);
    char *c = (char*) malloc(sizeof(char) * 16);
    char *d = (char*) malloc(sizeof(char) * 17);

    // malloc_size is macOS specific
    cout << malloc_size(a); 
    cout << "\n" << malloc_size(b);
    cout << "\n" << malloc_size(c);
    cout << "\n" << malloc_size(d);

    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}