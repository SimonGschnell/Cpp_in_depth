#include <iostream>

int main(){

    //! pointers are more flexible than references but also more dangerous

    //? size of pointers
    //* the size of pointers depends on the architecture the executable is compiled for
    //* 32bit architectures use 4bytes for pointers and 64bits architectures use 8bytes for pointers respectively
    // regardless of the object the pointer is pointing to

    int x{5};
    int y{10};
    //? definition of a raw pointer
    //* to define a pointer we use the * symbol after the type to indicate that it's a pointer to that type
    int* x_ptr =&x; 
    //! not initalized pointers are called wild pointers and dereferencing them causes undefined behavior
    int* wild_ptr;

    std::cout << x << std::endl;
    //? using the address-of operator we can get the memory address of an indentifier
    std::cout << &x << std::endl; 
    //? using the dereference operator we can get the original value which the memory address is pointing to
    std::cout << *(&x) << std::endl;
    std::cout << *x_ptr << std::endl;
    
    #if 0
    std::cout << "this is the value of a wild pointer: " << *wild_ptr << std::endl;
    #endif
    
    //? assignment for pointers
    //* we can change what the pointer is pointing at (assigning the pointer a new address) //! not possible when using refrences
    x_ptr = &y;
    //* we can change the value being pointed at by the pointer (by assigning the dereferenced pointer a new value)
    *x_ptr = 22;

    //! printing the size of a pointer 
    std::cout << sizeof(x_ptr) << std::endl;

    {
        int temporary{55};
        x_ptr = &temporary;
    }// temporary goes out of scope and the x_ptr becomes a dangling pointer

    //* undefined behavior
    std::cout << *x_ptr << std::endl;

    return 0;
}