#include <iostream>
#include <bitset>

//? the smallest addressable unit of memory is 1 byte, which are 8 bits
//* a boolean value only requires 1 bit instead of 8
//* std::bitset can be used to keep track of 8 boolean flags inside a byte

int main(){

    //? bitset has 4 important member functions
    //* test() - query whether a bis is 0 or 1
    //* set() - turns a bit to 1
    //* reset() - turns a bit to 0
    //* flip() - will change to bit to the opposite value (1 to 0 && 0 to 1)

    //? we instantiate a bitset variable with position 0 and 2 turned on
    std::bitset<8> flags{0b0000'0101}; // 0000 0101
    flags.set(3);                      // 0000 1101
    flags.flip(4);                     // 0001 1101
    flags.reset(4);                    // 0000 1101
    std::cout << "bits in bitset: " << flags << std::endl;
    std::cout << "is bit 0 set ? " << flags.test(0) << std::endl;
    std::cout << "is bit 1 set ? " << flags.test(1) << std::endl;

    return 0;
}