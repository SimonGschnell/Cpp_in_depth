#include <iostream>

int non_value_returning_function() {

    //! we do not return the a value even though we specified a return type in the function signature
    //! This results in undefined behavior
    //? most of the compiler will catch this error and won't compile
}

int main(){

    //declaration without initialization
    //? the variable will point to a not used memory location which may already have a value assigned
    //! this decision was made back in the days where memory was expensive 
    //? BEST PRACTICE: always initialize your variables with values because the performance difference is minimal
    int x;

    //uninitialized variables will contain the value of a random empty memory space
    std::cout << x << '\n';

    //? implementation defined behavior is when the compiler defines the behavior
    //! normally int takes 4 bytes of memory but other compiler will use just 2 bytes instead
    std::cout << "sizeof(int) = " << sizeof(int) << '\n';

    return 0;
}