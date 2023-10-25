#include <iostream>

//! how overloaded funcitons are differciated
// number of parameters -> YES 
// type of parameters -> YES 
// return type -> NO
//! additionally member functions (methods) have additional characteristics for differenciation (const & Ref-qualifiers)

//? function overloading allows to have multiple functions with the same name but different parameter types or return type
int add(int x, int y){
    return x + y;
}

//* overloaded version of the add() function with double parameters
//! overloaded functions cannot be distinguished by different return types alone
//? type aliases are not treated as different types for differenciation
double add(double x, double y){
    return x + y;
}

//* overloaded functions can be distinguished by the amount of parameters
int add(int x, int y, int z){
    return x + y + z;
}

int main(){

    std::cout << add(4,8) << std::endl;
    std::cout << add(4,8,2) << std::endl;
    std::cout << add(0.5, 8.3) << std::endl;

    return 0;
}

//* some function with prototype int fcn() might compile to name __fcn_v,
//* whereas int fcn(int) might compile to name __fcn_i. 
//* So while in the source code, two overloaded functions share a name,
//*  in compiled code, the names are actually unique.
// different compilers will produce different names