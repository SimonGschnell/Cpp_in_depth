#include <iostream>
#include <cstdint>
#include <iomanip>


int main(){

    //? c++ has 3 types of floating point types
    //* always initialize floating point numbers with at least 1 decimal point number
    float f{3.33f}; // minimum size 4 bytes //! numbers with f at the end denote floats
    double d{20.0}; // minimum size 8 bytes
    long double ld{35090.30}; // minimum size 8 bytes up to 16

    std::cout << "size of float: " << sizeof(float) << '\n';
    std::cout << "size of double: " << sizeof(double) << '\n';
    std::cout << "size of long double: " << sizeof(long double) << '\n';

    std::cout << 5.0 << '\n';
	std::cout << 6.7f << '\n';
	std::cout << 9876543.21 << '\n';

    return 0;

}