#include <iostream>
#include <string>

#include "include/LRUCache.h"

using std::cout;
using std::string;

int main() {    
    LRUCache<int, string> cache(3);    
    cache.put(1, "A");  
    cache.put(2, "B");  
    cache.put(3, "C");
    cache.debug();
    cout << "\nGET 2 : " << cache.get(2);
    cout << "\nGET 4 : " << cache.get(4);
    cout << "\nGET 1 : " << cache.get(1);
    cache.debug();    
    cache.put(4, "D");  
    cache.put(3, "E");
    cache.debug();      
    cout << "\nGET 4 : " << cache.get(4);
    cache.put(1, "Z");
    cache.debug();      
    cout << "\n=============================\n";
    LRUCache<int, int> cache2(0);    
    cout << "\nGET 2 : " << cache2.get(2);
    cache2.put(1, 2);  
    cache2.debug();
    cout << "\n=============================\n";
    LRUCache<int, int> cache3(1);    
    cache3.put(1, 2);  
    cout << "\nGET 1 : " << cache3.get(1);
    cout << "\nGET 2 : " << cache3.get(2);
    cache3.put(2, 3);
    cout << "\nGET 1 : " << cache3.get(1);
    cout << "\nGET 2 : " << cache3.get(2);
    cache3.put(1, 4);
    cout << "\nGET 1 : " << cache3.get(1);
    cout << "\nGET 2 : " << cache3.get(2);    
    cache3.put(1, 5);
    cout << "\nGET 1 : " << cache3.get(1);
    cout << "\nGET 2 : " << cache3.get(2);
    cache3.debug();
    return 0;   
}