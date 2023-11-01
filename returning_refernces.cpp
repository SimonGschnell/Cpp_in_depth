#include <iostream>

using namespace std::literals;

//? WHEN we should return references in functions
//* when a reference was passed to the function and can be returned back to the caller

//! without references the following function would have made 3 expensive copies of std::string
//* 2 for the parameters and 1 for the return value
//? using references we are making 0 expensive copies neither for the parameters nor for the return value
const std::string& firstAlphabetically(const std::string& str1,const std::string& str2){
    //? here we are passing the reference back to the caller of this function
    //* we can assume that the value the reference is pointing to is still in scope 
    return ((str1 < str2)? str1 : str2);
}

int& return_modifiable_reference(){
    //! avoid returning references to non-const static variables 
    static int s_id {0};
    ++s_id;
    return s_id;
}

const std::string& return_dangling_reference(){
    //! this local function varialbe does not outlive the function scope and the returned reference to it is left dangling
    std::string name {"Simon Gschnell"s}; 
    return name;
}

//* we want to return references instead of return by value to avoid expensive copies of objects
const std::string& return_reference(){
    //? this can be avoided by makeing the local variable have a static duration and outlive the function
    static const std::string name {"Simon Gschnell"s}; 
    
    //? only an inexpensive reference is returned instead of returning a copy of the string
    return name;
}

int main(){
    
    // std::cout << return_dangling_reference() << std::endl; //! causes segmentation fault using the dangling pointer
    std::cout << return_reference() << std::endl;

    int& a {return_modifiable_reference()};
    int& b {return_modifiable_reference()};
    //? a and b will be the same because both have a reference to the same static variable
    std::cout << a << b << std::endl;

    //? when using non-reference variables to store the values returned, an expensive copy is made
    //* and destroys the purpose to return references to begin with
    int a_by_value {return_modifiable_reference()};
    int b_by_value {return_modifiable_reference()};
    //! values will be independent but expensive copy was made
    std::cout << a_by_value << b_by_value << std::endl;

    std::string hello{"hello"s};
    std::string world{"world"s};
    std::cout << "what comes first alphabetically? Hello or World: " << firstAlphabetically(hello,world) << std::endl;
    std::cout << "what comes first alphabetically? abc or aab: " << firstAlphabetically("abc"s,"aab"s) << std::endl;

    return 0;
}