#include <iostream>
using namespace std::literals;

//* pass by reference allows us to avoid copying values of arguments into temporary variables
//* pass by reference allows us to directly access passed variables by reference

//! this function will make an expensive copy of the passed arguments
void print_string(std::string value){ // scope of local variable "value" starts here
    std::cout << value << std::endl;
} // scope of local variable "value" ends here

//! when using a const reference we can pass modifiable, non-modifiable and rvalues as arguments (making it more flexible)
//? this function uses references to avoid making copies of values passed as arguments
void print_string_ref(const std::string& value){ // prefer using const references when not modifying passed arguments
    //* the reference acts as a pointer and simply points at the identifier 
    std::cout << value << std::endl;
}

//! without a reference we only copy the value of the argument into a local variable
//! and cannot actually modify the passed argument
void increment_by_one(int value){ // pass by value
    ++value;
}

//! when using non-const reference we can only pass a modifiable lvalue value as argument
//? using a non const lvalue reference allows us to directly modify the passed argument
void increment_by_one_ref(int& value){ // pass by reference
    ++value;
} 



int main(){

    std::string name {"Patrick Gschnell"s};
    const std::string const_name {"Peter Hendricks"s};
    int age {24};

    //? PASS BY VALUE
    //! expensive copy
    print_string(name);

    //? PASS BY REFERENCE
    //* no copies through references (similar to pointers)
    print_string_ref(name);
    print_string_ref(const_name);

    increment_by_one(age);
    std::cout << age << std::endl; // pass by value function did not alter the age
    increment_by_one_ref(age);
    std::cout << age << std::endl; // pass by reference function did alter the age

    return 0;
}