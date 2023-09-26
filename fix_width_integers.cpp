#include <iostream>
#include <iomanip>

//? library for fixed width integer types in std namespace
#include <cstdint>

int main (){

    //? it’s a little ridiculous to have to deal with types that have uncertain ranges
    //* C99 defined a set of fixed-width integers that guarantee same size on any architecture

    int8_t bit8{}; //* 1 byte signed (-128 - 127) // treated like a signed char
    //! best to avoid int8_t because of how a character is encoded
    int16_t bit16{}; //* 2 byte signed 
    int32_t bit32{}; //* 4 byte signed
    int64_t bit64{}; //* 8 byte signed

    std::uint8_t ubit8{}; //* 1 byte unsigned (0 - 255) // treated like a unsigned char
    //! best to avoid uint8_t because of how a character is encoded
    std::uint16_t ubit16{}; //* 2 byte unsigned 
    uint32_t ubit32{}; //* 4 byte unsigned
    uint64_t ubit64{}; //* 8 byte unsigned (0 - 18,446,744,073,709,551,615)

    //? size_t is a unsigned integral that is used to represent the size of objects
    //* size_t varies depending on the system, typically equivalent to the address-width of the application
    size_t size_of_int {sizeof(int)};
    std::cout << sizeof(size_t) << std::endl; // prints 8 bytes -> 64 bits on my 64 bit architecture machine

    return 0;
}