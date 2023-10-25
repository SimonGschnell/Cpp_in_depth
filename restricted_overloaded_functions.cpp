#include <iostream>

void printInt(int value){
    std::cout << value << std::endl;
}

//? the usage of overloaded functions can be restricted by deleting those variants with undesirable types
void printInt(char value) = delete;
void printInt(bool value) = delete;

//? all types except of the exact match can be restricted/deleted with a template
template <typename T> void printInt(T value) = delete;

int main(){

    //? if values that arrise from numeric conversions after function resolution don't behave as defined
    //* this can be avoided by deleting the overloaded functions with the undesired types 
    printInt(8); // prints 8 as expected
    #if 0
    printInt('8'); //! prints 56
    printInt(true); //! prints 1
    printInt(8.0); // was restricted by deleting the template overloaded function
    #endif 

    return 0;
}