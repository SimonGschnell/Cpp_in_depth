#include <iostream>

//! allways try to avoid non-const global variables
//? they tend to be unpredictable when function modify them as side effects

//* instead use global variables that are:
// prefixed with g_ to differentiate them from local variables
// constant (do not change their value)
// internally linked
// inside their own namespace to avoid naming collisions
//? and they can be accessed by a externally linked function instead (minimizes refactoring)

namespace Constants {
    // const -> internally linked
    // starts with g_
    // inside Constants namespace
    const std::string g_name{"simon"}; 
    const std::string g_salutation{"Herr"};
}

std::string get_g_name(){
    // here can be extra implementation details before returning the value
    return Constants::g_name;
}

std::string get_g_salutation(){
    // here can be extra implementation details before returning the value
    return Constants::g_salutation;
}

//? if the global variable is used as a product to create a new value, pass them as arguments to maintain modularity
std::string greetings(std::string salutation, std::string name){
    return salutation + " " + name;
}



