#include <iostream>


int implicit_conversion(long x){
    return 10.0 / x; // converts x to double because of the binary operator /
    // return value converts double to int because of the declared return type
}

//? implicit type conversion is performed by the compiler when one data type is required but a different type is provided
int main(){
std::cout << sizeof(long) << std::endl;
    //! if the compiler can't find a conversion, then the compiler will fail with compilation error
    //* brace initialization disallowes conversions that result in data loss
    #if 0 
    // this will fail
    int data_loss {3.3};
    // this will work
    int data_loss_copy_initialization = 3.3; 
    #endif

    //* integer 3 is provided as a value for a float
    //* implicit type conversion is performed by the compiler to produce a new float which value is equal 
    float x {3};

    //? implicit type conversion arrise when:
    // the type of the return value is different from the functions declared return type
    // using certain binary operators with operands of different types //binary operator are operators that take two operands
    double d { 4.0 / 2 }; //! 2 is converted to double

    //using a non-boolean value for an if condition
    if(5) std::cout << "5 is truthy" << std::endl;

    // when arguments passed to function parameters are of different types
    //* implicit_conversion expects a long int, the argument int will be implicitly converted to long int
    implicit_conversion(4);

    return 0;
}