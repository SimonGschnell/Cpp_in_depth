#include <iostream>
#include <string>

// identifiers with external linkage can be linked to other files with foreward declarations

//? non const global variables have external linkage by default
std::string global_string {"global string"};

//? const global variables can be made externally linked with the 
//! extern keyword
//! they are also forewarded in other files with the extern keyword without initialization
extern const int global_int{88};

//! constexpr variables can't be forewarded because the compiler needs to know a value at compile time
//* so this is useless
extern constexpr int global_integer{99};

//! NOTE: function foreward declarations don't need the extern keyword because they can be separated by whether or not the body of the function was defined. 
//! Variables need the extern keyword because otherwise they could be misinterpreted as uninitialised variables
void global_function(){
    std::cout << "I am a global function" << std::endl;
}


