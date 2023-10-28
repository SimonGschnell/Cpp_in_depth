#include <iostream>

int main (){

    //? lvalue references can only be bound to modifiable lvalues
    //* otherwise it would be possible to change the const lvalue through the reference
    const int non_modifiable{33};
    #if 0
    int& bind_to{non_modifiable};
    #endif
    
    //? lvalue is a value that lives longer than 1 expression often an identifier
    //? rvalue is a value that is discarted after it's use in an expression
    //* num is a lvalue and the literal 5 is a rvalue
    int num {5};
    int num2{6};

    //? references and their referent have independent lifetimes 
    //! the otherway around would create a dangling reference and accessing the dangling reference would cause undefined behavior
    {
        int& block_scoped_ref{num}; 
        std::cout << block_scoped_ref << std::endl;
    }// block_scoped_ref goes out of scope here
    #if 0
    std::cout << block_scoped_ref << std::endl; // identifier "block_scoped_ref" is undefined
    #endif

    //? we can make a lvalue reference with a lvalue reference type that uses the & keyword 
    int& num_ref{num};
    //! once intialized, we cannot change the reference to another lvalue object
    //* the following line just sets the value of num to num2 and won't change reference to the object num2
    num_ref = num2; // num = 6
    //? the type of the reference also has to be coherent with the referent type
    #if 0
    double& double_red{num}; // compiler error: invalid conversion
    #endif 
    
    #if 0
    int& ref{}; // references have to be initialized
    int& red; // compiler error
    #endif

    ++num;
    ++num_ref;
    std::cout << num << std::endl;
    std::cout << num_ref << std::endl;

    return 0;
}