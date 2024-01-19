#include <iostream>

void fun(const int& value){ //* lvalues select this function
    std::cout << "lvalue version: " << value << std::endl;
};

void fun(int&& value){ //* rvalues select this version of the function

    std::cout << "rvalue version: " << value << std::endl;
};

int main(){

    //? In C++11 R-Value References were introduced which can only reference R-values
    //* they are written with two && instead of one & like L-Value References
    int number {10};
    //int&& rValueRef {number}; //! an rvalue reference cannot be bound to an lvalue
    int& lValueRef {number}; //? lvalue
    int&& rValueRef {99}; //? rvalue

    //? rvalues are an important feature for the move semantic 
    //? they are often used to pass rvalues to function parameters
    fun(number);
    fun(5);

    //! rValueRef acts as a lvalue because it is a named type
    //* therefore, it will use the "const int& value" overloaded function 
    fun(rValueRef);
    



    return 0;
}//* rValueRef increases the lifetime of the literal it holds inside a temporary object and goes out of scope here