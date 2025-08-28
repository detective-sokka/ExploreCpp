#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    cout << "\nSize of vector<int> : " << sizeof(vector<int>);
    cout << "\nSize of vector<string> : " << sizeof(vector<string>);
    cout << "\nSize of string : " << sizeof(string);
    cout << "\nSize of shared_ptr : " << sizeof(shared_ptr<int>{});
    cout << "\nSize of unique_ptr : " << sizeof(shared_ptr<int>{});
    cout << "\nSize of unordered_map<char, int> : " << sizeof(unordered_map<char, int>);

    return 0;
}