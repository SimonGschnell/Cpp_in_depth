#include <iostream>

int main(){

    //* compound expression - 4 + 2 * 3 = 18 OR 10?
    //? at compile time the expression is parsed and it is determined how the operands are grouped with operators
    //? done with the associativity and precedence rules

    int value = 4 + 2 * 3;
    //! precedence rules
    //? multiplication has higher precedence (level 5) than addition and subtraction (level 6)
    //? so the expression will be grouped like: 4 + ( 2 * 3 )
    std::cout << value << std::endl; 

    int associativity = 7 - 4 - 1;
    //* ( 7 - 4 ) - 1 = 2 OR 7 - ( 4 - 1 ) = 4
    //? two operators with the same precedence level are adjacent, associativity rules used
    //? operators in precedence level 6 have associativity of left ot right
    std::cout << associativity << std::endl;

    //! does the following code work correctly
    if ( 3 & 1 == 1 )

    //? == the Equality operator has precedence level 10 while the bitwise AND has precedence level 11
    //! which results in 
    //* if( 3 & ( 1 == 1 ))
    //! but we want if(( 3 & 1) == 1 ))

    // the << and >> operator both work as bitwise left/right and insertion/extraction 
    // the compiler can determine the difference based on the types of the operands

    //!!! IN ORDER TO REDUCE PRECEDENCE MISTAKES, the best practice is to use parathesis

    //? careful the compiler may evaluate in a random order, if getValue reads user input any the result may vary
    //std::cout << getValue() + (getValue() * getValue()) << '\n'; // a + (b * c)

    return 0;
}