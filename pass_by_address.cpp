#include <iostream>
#include <cassert>
using namespace std::literals;

//! “Pass by reference when you can, pass by address when you must”.

void print_by_value(std::string value){
    // expensive std::string copy
    std::cout << value << std::endl;
}

void print_by_reference(std::string& value){
    // binds the reference to the argument , avoiding copying
    value = "new Name reference"s;
    std::cout << value << std::endl;
}

void print_by_address(std::string* value){

    //! fails the program if a null pointer has been passed and should have not been allowed
    //assert(value != nullptr);

    //? (option) otherwise return early if null pointers are allowed
    if(value == nullptr) {return; }

    // passes the address by value which is an inexpensive copy, the address can be used like a reference
    *value = "new Name address"s;
    std::cout << *value << std::endl;
}

//? a pointer passed to a function cannot change to where the origianl pointer is pointing to
//! using a reference on a pointer allows you to change the original pointer object inside the function
void pass_by_reference_address(std::string*& value){
    value = nullptr;
}

int main(){
    
    std::string name {"Simon Gschnell"s};

    //? pass by value
    print_by_value(name);

    //? pass by reference
    print_by_reference(name);

    //? pass by address (not the value is copied, just the pointer)
    //* we can pass the address of the identifier with &
    //* or create a explicit pointer that can be used
    print_by_address(&name); 
    std::string* str_pointer{&name};
    print_by_address(str_pointer);

    //? what if we pass a nullptr to the function
    //* the programm will probably crash if it doesn't catch the exception in the function
    std::string* empty_ptr{};
    print_by_address(empty_ptr);

    //? we can change what a pointer object is pointing to through a function that uses a reference to a pointer as parameter
    //! this would not be possible with a raw pointer as parameter because it would have been passed by value
    std::cout << "value:" << ((str_pointer)? *str_pointer : "null pointer") << std::endl;
    pass_by_reference_address(str_pointer);
    std::cout << "value:" << ((str_pointer)? *str_pointer : "null pointer") << std::endl;
    

    return 0;
}