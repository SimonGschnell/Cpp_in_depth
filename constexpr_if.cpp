#include <iostream>
#include <type_traits>


//! constexpr if are mostly used when working with templates, where a method is only usable for some types
//* here if the value parameter is an integral the else path won't be compiled because of the constexpr if
//? with this addition the compiler will not throw an error because int has no method .length() but string does
template <typename T> auto return_length(T const& value){
    if constexpr (std::is_integral<T>::value){
        return value;
    }else{
        return value.length();
    }
}

int main (){

    constexpr double gravity{9.8};
    std::string some_string{"gravity"};
    int some_int{5};

    //? evaluating a constexpr at runtime is wasteful because we could know the result already at compile time
    //? the constexpr takes a constexpr condition and the compiler will decide whether to use the if or the else branch based of the condition
    if constexpr ( gravity == 9.8 )
    
        std::cout << "we are on earth!" << std::endl;
    else
        std::cout << "the gravity of the current planet is: " << gravity << std::endl;
    
    //! because of the constexpr everything except of the "we are on earth!" print will be removed from the final translation unit

    //! you can see the preprocessed file of a c++ program using the -E flag when compiling
    //? a preprocessed file will still contain both the if and else because only at the compiler step it is removed
    //* g++ -E sourcefile.cpp -o preprocessed_sourcefile.cpp

    std::cout << some_int << " has length: " << return_length(some_int) << std::endl;
    std::cout << some_string << " has length: " << return_length(some_string) << std::endl;
    

    return 0;
}

