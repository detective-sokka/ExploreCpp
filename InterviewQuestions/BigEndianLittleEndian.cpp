#include <iostream>

using namespace std;

class BigEndianLittleEndian {
    public:
        static void cStyleCheck() {
            constexpr static union {
                uint32_t integer;
                uint8_t c[4];
            } data = {0x11022022};
            if (data.c[0] == 0x22)
                cout << "\nLittle endian.";
            else 
                cout << "\nBig endian.";
        }

}; 

int main() {
    cout << "Endianness using C-Style - ";
    BigEndianLittleEndian::cStyleCheck();
    
    return 0;
}