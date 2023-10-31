#include <iostream>

int main(){

    //? four rules when working with const pointers:
    //! if the const keyword is before the type: the value cannot be modified
    //! if the const keyword is after the type: the pointer can not point to a different memory address 
    //* A non-const pointer can be assigned another address to change what it is pointing at
    //* A const pointer always points to the same address, and this address can not be changed

    //* A pointer to a non-const value can change the value it is pointing to. These can not point to a const value
    //* A pointer to a const value treats the value as const when accessed through the pointer, and thus can not change the value it is pointing to. 
    // These can be pointed to const or non-const l-values //! but not r-values, which don’t have an address

    const int const_int {5};
    int non_const_int{8};
    int another_non_const_int{99};
    //? normal raw pointers can not point to constant identifiers
    #if 0
    int* i_ptr{&const_int}; // compiler error
    #endif

    //? a const pointer has to be defined in order to point to a constant identifier
    const int* i_ptr{&const_int};
    // *i_ptr=5; the pointer can not be modified through dereferencing
    
    //? const pointer can also point to non-const identifiers but they will be treated as constants through the pointer being constant
    i_ptr = &non_const_int; 
    #if 0
    *i_ptr = 55; // compiler error expression must be a modifiable value
    #endif
    //* we cannot change the value through the pointer but we can change the identifier itself
    non_const_int = 10;

    std::cout << "constant pointer holding a non-const identifier: " << *i_ptr << std::endl;

    //? we can also make the pointer constant itself, meaning it cannot point to any other memory address after initialization
    #if 0
    int* const const_pointer {&const_int}; // this would fail because the pointer can't point to const values
    const int* const const_pointer2 {&const_int} //* valid assignment
    #endif
    int* const const_pointer {&non_const_int}; 
    //const_pointer = &another_non_const_int; //! this is not allowed because a const pointer cannot point to other memory addresses
    //? we are allowed to dereference and change the const pointer because it does not point to a const
    *const_pointer = 15;  
    std::cout << "we can dereference and change the pointed value of a const pointer: " << *const_pointer << std::endl;

    //! const pointers have to be initialized upon definition
    #if 0 
    int* const const_pointer4; // compiler error: requires a initializer 
    #endif 

    //? combining a const pointer with a pointer to const we get:
    //* here we are allowed to point to const identifiers and cannot point to other identifiers later
    const int* const const_pointer_to_const{&const_int}; 
    //const_pointer_to_const = &non_const_int; // not allowed
    //*const_pointer_to_const = 55; // not allowed


    return 0;
}