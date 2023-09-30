#include <iostream>

//? const variables are preferred over object like macros
//! object like macros values are not displayed when debugging
#define GRAVITY 9.8 // object macros have the same functionality as constant variables

//? function parameter can be made constant
//* typically used for pass by reference and pass by address
void print_age(const int age);

int main(){

    //? create a constant variable that value can't be changed with the keyword const
    //! const variables have to be initialized 
    const double gravity {9.8};
    const int sides_of_square = 4;

    //? every value that should not be changed after initialization and is known at compile time
    //* should be created with constexpr
    constexpr short sum {4+88};

    //? every value that should not be changed after initialization and is NOT known at compile time
    //* should be created with const
    short tmp{}; // tmp is not a constant expression because it is not defined as a constant
    const short value {tmp};

    //! the keyword constexpr and how it operates in the background 
    //! explaines why rust variables are constant variables by default 
    //? and why compilation time increases while programs are running faster

    //? Making constexpr variables ensures that those variables have values known at compile-time

    



    return 0;
}