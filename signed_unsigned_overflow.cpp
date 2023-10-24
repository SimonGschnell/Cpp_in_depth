#include <iostream>
#include <limits>

int main(){

    //? unsigned numeric values have well defined overflow
    unsigned int o1 {std::numeric_limits<unsigned int>::max()};
    
    std::cout << o1 << std::endl;
    //* overflow occurs here:
    o1 += 1;
    //* wraps around to 0, the overflow behaves like the modulo operator
    std::cout << o1 << std::endl;


    //? overflows for signed numeric values is implementation defined
    //? it depends on the compiler how he wants to handle and optimize the overflow of signed numeric values
    int o2 {std::numeric_limits<int>::max()};

    std::cout << o2 << std::endl;
    o2 += 1;
    std::cout << o2 << std::endl;

    return 0;
}