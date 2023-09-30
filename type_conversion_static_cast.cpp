#include <iostream>
#include <cstdint>

void print_double(double);
void print_int(int);

int main (){

    //? implicit type conversion
    int a{5};
    //* we pass a int to a function that expects a double
    //* type conversion will try to create a double value out of the int variable and pass it to the function instead
    print_double(a);

    //? implicit type conversion with data loss
    double d{5.5};
    //* when trying to create a int value from 5.5, the compiler recognizes that there is a lost of information
    print_int(d);

    //! explicit type conversion using static_cast
    print_int(static_cast<int>(d)); //? we explicitly cast the type ourself and the compiler won't throw warnings

    double some_double{static_cast<double>(433)};//? casted to 433.0

    //* casting int to ASCII char
    std::cout << "the number 98 in ASCII is equal to the letter: " << static_cast<char>(98) << std::endl;

    unsigned short short_n = 65000;
    //? casting unsigned numbers out of range compared to signed numbers will introduce undefined behavior
    std::cout << "unsigned short 65000 converted to signed short: " << static_cast<signed short>(short_n) << std::endl;

    //? int8_t and uint8_t are treated like signed and unsigned chars
    std::int8_t myInt{65}; 
    //* the following prints A on most compilers instead of the number     
    std::cout << myInt << '\n'; 
    //* we can prevent this by explicitly casting into int
    std::cout << static_cast<int>(myInt) << std::endl;

    return 0;
}

void print_double(double x) { 
    std::cout << x << std::endl;
}

void print_int(int x) { 
    std::cout << x << std::endl;
}