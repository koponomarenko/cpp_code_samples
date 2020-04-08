#include <iostream>
#include <iomanip>
#include <cstdint>

using namespace std;

union Int_bytes {
    int32_t value;
    uint8_t bytes[sizeof(int32_t)];
};

int main()
{
    const int32_t test_value{0x01020304};

    // #1
    Int_bytes a{test_value};
    cout << hex;
    cout << "a.value: " << a.value << endl;
    cout << "a.bytes[0]: " << static_cast<int32_t>(a.bytes[0]) << endl;

    // #2
    int32_t byte1 =  test_value & 0x000000ff;
    int32_t byte2 = (test_value & 0x0000ff00) >> 8;
    int32_t byte3 = (test_value & 0x00ff0000) >> 16;
    int32_t byte4 = (test_value & 0xff000000) >> 24;
    cout << "byte1: " << static_cast<int32_t>(byte1) << endl;
    cout << "byte2: " << static_cast<int32_t>(byte2) << endl;
    cout << "byte3: " << static_cast<int32_t>(byte3) << endl;
    cout << "byte4: " << static_cast<int32_t>(byte4) << endl;
    
}
