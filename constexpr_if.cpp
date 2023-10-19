#include <iostream>


int main (){

    constexpr double gravity{9.8};

    //? evaluating a constexpr at runtime is wasteful because we could know the result already at compile time
    //? the constexpr takes a constexpr condition and the compiler will decide whether to use the if or the else branch based of the condition
    if constexpr ( gravity == 9.8 )
    
        std::cout << "we are on earth!" << std::endl;
    else
        std::cout << "the gravity of the current planet is: " << gravity << std::endl;
    
    //! because of the constexpr everything except of the "we are on earth!" print will be removed from the final translation unit

    //! you can see the preprocessed file of a c++ program using the -E flag when compiling
    //* g++ -E sourcefile.cpp -o preprocessed_sourcefile.cpp

    return 0;
}