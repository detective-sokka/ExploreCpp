#include "Vector.hpp"
#include <iostream>
#include <string>
#include <utility>

void test_custom_vector() {
    Vector<int> a = {1, 2, 3, 4};
    a.debug_vector();
    Vector<int> b = a;
    b.debug_vector();
    Vector<int> c = std::move(a);
    c.debug_vector();    
    a = c;
    a.debug_vector();
    b = std::move(c);
    b[1] = 0;
    c.debug_vector();
    b.debug_vector();

    Vector<std::string> strVec = {"a", "b", "c", "d"};
    strVec.debug_vector();
    Vector<std::string> strVec2 = strVec;
    strVec2.debug_vector();
    Vector<std::string> strVec3 = std::move(strVec);
    strVec3.debug_vector();    
    strVec = strVec3;
    strVec.debug_vector();
    strVec3 = std::move(strVec2);
    strVec3[1] = "z";
    strVec2.debug_vector();
    strVec3.debug_vector();

    std::cout << "\n===== Testing emplace_back =====\n";
    strVec.emplace_back("e");
    strVec.emplace_back("f");
    strVec.debug_vector();
}

int main() {
    test_custom_vector();
    return 0;
}