#include <iostream>
#include <string>

// An identifier with 
//? internal linkage 
// can be seen and used within a file but is not accessible form other files , 
// identifcally named identifiers in different files will be treated as independent

//? const and constexpr global variables have internal linkage as default 
const float gravity {9.81f};
constexpr short user_defined_number{5}; 

//? non const global variables have external linkage 
int global_number {55};

//! we can change the external linkage of non const global variables to internal
static std::string global_string {"hello world"};

int main (){



    return 0;
}