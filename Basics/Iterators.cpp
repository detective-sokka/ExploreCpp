#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> nums = {1, 2, 3, 4, 5};
    unordered_map<char, int> charMap = {{'a', 1}, {'b', 2}};

    cout << "\nPrinting vector using iterators : ";
    for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) 
        cout << *it << " ";

    cout << "\nPrinting map using iterators : ";
    for (unordered_map<char, int>::const_iterator it = charMap.begin(); it != charMap.end(); ++it) 
        cout << (*it).first << " , " << (*it).second << " ; ";

    return 0;    
}
