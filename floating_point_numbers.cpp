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

    //? std::cout normaly only displays 6 significant digits
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';

    //? we can cahnge this behavior with the function setprecision form iomanip library
    //* setprecision is an output manipulator method that alters how data is output (sticky)
    std::cout << std::setprecision(17);
    std::cout <<"float: "<< 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
    std::cout <<"double: "<< 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double

    //Float has 7 digit precision
    //the following output will be rounded because of that
    float float_number{123456789.0};
    std::cout << float_number << std::endl;

    //double can have 16 digit precision 
    //here we try to output 17 digit so double produces an approximate of the value
    double double_number{0.1};
    std::cout << double_number << std::endl;
    return 0;

}