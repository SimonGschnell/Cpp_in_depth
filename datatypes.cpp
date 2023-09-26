#include <iostream>
#include <iomanip>

int main(){
    //? numbers with fractional part
    float f = 3.123;
    double d = 3.123456;
    long double ld = 3.123456789;

    //? true or false
    //* store their value as integer types
    bool b{};
    bool b2{1}; // 1 equal to true
    bool b3{0}; // 0 equal to false

    //? characters
    //* store their value as integer types
    char c{};
    wchar_t wc{};
    //C++ 20 -> char8_t c8 = 'c'; 
    char16_t c16{};
    char32_t c32{};

    //? numbers
    //signed numbers
    //! assigning a bigger number than the type can store results in undefined behavior (integer overflow)
    //* overflow will result in the number wrapping around and starting from the lowest number again
    short i{};
    int i2{};
    long i3{};
    long long i4{};

    //by default int types are signed we can also specify it with the signed keyword
    signed int abc{};
    
    //? null pointer
    std::nullptr_t p{};

    //? no type
    //void

    std::cout << std::left;
    std::cout << std::setw(16) << "bool: " << sizeof(bool) << '\n';
    std::cout << std::setw(16) << "char: " << sizeof(char) << '\n';
    std::cout << std::setw(16) << "short: " << sizeof(short) << '\n';
    std::cout << std::setw(16) << "int: " << sizeof(int) << '\n';
    std::cout << std::setw(16) << "long: " << sizeof(long) << '\n';
    std::cout << std::setw(16) << "long long: " << sizeof(long long) << '\n';
    std::cout << std::setw(16) << "float: " << sizeof(float) << '\n';
    std::cout << std::setw(16) << "double: " << sizeof(double) << '\n';
    std::cout << std::setw(16) << "long double: " << sizeof(long double) << '\n';
    
    //? the above examples are all statically allocated in the stack
    //! sizeof does not include dynamically allocated memory
    

    return 0;
}