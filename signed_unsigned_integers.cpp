#include <iostream>
#include <iomanip>

int main(){

    //? signed integers

    signed short i{}; 
    //* short 2 bytes -> 
    //* 16 bits -> 
    //* 1bit for sign / -2^15 - 2^15-1
    signed int i2{}; 
    //* int 4 bytes -> 
    //* 32 bits -> 
    //* 1bit for sign / -2^31 - 2^31-1
    signed long i3{}; 
    //* long 4 bytes -> 
    //* 32 bits -> 
    //* 1bit for sign / -2^31 - 2^31-1
    signed long long i4{}; 
    //* long long 8 bytes -> 
    //* 64 bits -> 
    //* 1bit for sign / -2^63 - 2^63-1

    //? unsigned integers

    unsigned short u1{}; 
    //* 2 bytes / 16 bits ->
    //* 0 - 2^16-1 values
    unsigned int u2{};
    //* 4 bytes / 32 bits ->
    //* 0 - 2^32-1 values
    unsigned long u3{};
    //* 4 bytes / 32 bits ->
    //* 0 - 2^32-1 values
    unsigned long long u4{};
    //* 8 bytes / 64 bits ->
    //* 0 - 2^64-1 values

    //! unsigned int overflow results in module wrap around
    //* modern compiler throw a warning but it still compiles with undefined behavior

    unsigned short positive_overflow{ 65535 }; // largest 16-bit unsigned value possible
    std::cout << "x was: " << positive_overflow << '\n';

    positive_overflow = 65536; // 65536 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << positive_overflow << '\n';

    positive_overflow = 65537; // 65537 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << positive_overflow << '\n';

    //! it's also possible to overflow the other way around

    unsigned short negative_overflow{ 0 }; // smallest 2-byte unsigned value possible
    std::cout << "x was: " << negative_overflow << '\n';

    negative_overflow = -1; // -1 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << negative_overflow << '\n';

    negative_overflow = -2; // -2 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << negative_overflow << '\n';

    //! the best practice is to avoid unsigned int becuase it is easier to overflow the bottom
    //! through simple substitution or decrementing a value 

    return 0;

}