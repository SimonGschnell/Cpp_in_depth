#include <iostream>
#include <string>

//! identifiers with internal linkage can only collide with names
//! in the same translation unit, not across the entire program.

//! In modern C++, use of the static keyword for giving identifiers internal linkage is falling out of favor.
//! Unnamed namespaces can give internal linkage to a wider range of identifiers


// An identifier with 
//? internal linkage 
// can be seen and used within a file but is not accessible form other files , 
// identifcally named identifiers in different files will be treated as independent
//! this avoid naming collisions 

//? const and constexpr global variables have internal linkage as default 
const float gravity {9.81f};
constexpr short user_defined_number{5}; 

//? non const global variables have external linkage 
int global_number {55};

//! we can change the external linkage of non const global variables to internal
static std::string global_string {"hello world"};

//?--------------------------------
//* function identifiers have the same linkage property that variable identifiers do --> external
// this function may cause naming collisions
int add(int x, int y){ //? this can be forewarded
    return x + y;
}

//! with the static keyword we change the linkage to internal
static int add_internal(int x, int y) { //? this can't be forewarded
    return x + y;
}

