#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> vec;

    cout << "Initial capacity : " << vec.capacity() << ", Size : " << vec.size();

    vec.reserve(100);
    cout << "\nAfter setting capacity to 100 : " << vec.capacity() << ", Size : " << vec.size();

    vec.reserve(50);
    cout << "\nAfter setting capacity to 50 : " << vec.capacity() << ", Size : " << vec.size();

    vec.shrink_to_fit();
    cout << "\nAfter shrink to fit : " << vec.capacity() << ", Size : " << vec.size();

    for (int i = 0; i < 100; i++)
        vec.push_back(i);

    cout << "\nAfter inserting 100 elements : " << vec.capacity() << ", Size : " << vec.size();   
    vec.resize(50);
    cout << "\nAfter resize to 50 elements : " << vec.capacity() << ", Size : " << vec.size();   
}