//? the preprocessor is responsible for the include directives
//* the preprocessor replaces the include with the content of the included file, the included content are then preprocessed recursively
#include <iostream>

//? object like macros are created with the define directive
//! the preprocessor will replace any other occurences of the identifier by the initialized value (substitution text)
//only used in legacy code because c++ supports constants
#define TRUE_VALUE 0
#define MY_NAME "simon"

//? preprocessor directive without substitution text, used for conditional compilation
//* in combination with the ifdef / ifndef / endif directives
#define PRINT_BOB

int main (){
    //std::cout << "my name is : " << MY_NAME << '\n';

    //? ifdef checks whether a specific symbol is defined (if)
    #ifdef PRINT_BOB
    std::cout << "PRINT BOB is defined" << '\n';
    //? endif ends the ifdef directive
    #endif

    //? ifndef checks whether a symbol is NOT defined (if not)
    #ifndef PRINT_BOB
    std::cout << "PRINT BOB is not defined" << '\n';
    #endif

    //? alternative to #ifdef
    #if defined(PRINT_BOB)
    //this will compile
    #endif

    //? alternative to #ifndef
    #if !defined(PRINT_BOB)
    //this won't compile
    #endif
    
    //! convienient way to comment out part of the code
    // can be used to comment out part of code that contains multiline comments because nested multiline comments are not allowed
    //* the 0 can be changed to a 1 to temporarily enable the section
    #if 0
    //? the #if 0 directive will ignore and not compile anything inside the directive
    #endif

    //! object like macros (define symbols) are not visible in other linked source files
    
    
    return 0;
}