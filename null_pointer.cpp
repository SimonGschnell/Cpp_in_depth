#include <iostream>
#include <cstddef>

void print_pointer(int* ptr){
    std::cout << "in print_pointer(int*)" << std::endl;
}

//? overloaded function that uses nullptr_t as the parameter type 
void print_pointer(std::nullptr_t ptr){
    std::cout << "in print(std::nullptr_t)" << std::endl;
}

int main(){
    //! references should be favored over pointers, unless the additional capabilities provided by pointers are required.

    int i{5};

    //* if a pointer does not point to a memory address it is called a null pointer
    //? an empty initialization of a pointer creates a null pointer
    int* i_ptr {}; 
    //? we can also use the keyword nullptr to create a null pointer
    int* null_ptr {nullptr}; // prefere this way of defining nullptr
    //? a null pointer can also be created by using the C preprocessor macro NULL in <cstddef>
    int *null_ptr_c {NULL};

    //* we can convert a null pointer to a valid pointer any time by assignment to a memory address
    i_ptr = &i;

    //? through conditionals can be checked whether a pointer points to a memory address or not
    if(null_ptr == nullptr){
        std::cout << "does not point to a memory address" << std::endl;
    }else{
        std::cout << "does point to a memory address" << std::endl;
    }
    //* best practice is to avoid dangling pointers by setting them to nullptr 
    //* the programmer is responsible for ensuring that when using unsafe raw pointers

    //! usage of null pointers causes undefined behavior and dereferencing a null pointer will probably crash the program
    //* one of the most common reasons for crashes are dangling or null pointers being dereferenced
    //std::cout << *null_ptr << std::endl;

    //? null pointers have their own type to be destinguished from other pointers
    //* std::nullptr_t in the library <cstddef>
    print_pointer(i_ptr);
    print_pointer(nullptr); // the identifier null_ptr does not work here

    return 0;
}