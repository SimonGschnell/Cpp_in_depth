#include <iostream>
#include <uchar.h>

int main(){

    //? character are stored as numbers like boolean values
    //* instead of 0 and 1 , they store numbers representing the ASCII table
    char c{};

    char newline{10}; //* ASCII value for newline
    char pos_a{97}; //* ASCII a
    char neg_a{-97}; //! ASCII characters range is only from 0 to 127
    char newline2{'\n'};

    //? unicode values are represented with 32 bits, therefore charX_t exist in <uchar.h>
    #if 0
    char8_t uni1{};
    char16_t uni2{};
    char32_t uni3{};
    #endif

    std::cout << pos_a << '\n' << neg_a << '\n';
    std::cout << "would you like a burrito? (y/n)"<< std::endl;
    std::cout << newline;
    std::cin >> c;

    

    return 0;
}