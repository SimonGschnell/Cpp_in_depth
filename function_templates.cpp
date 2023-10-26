#include <iostream>
#include <string>
#include "function_template_forward_declaration.h"

//! function template forward declarations won't work if the specific template function versions used were not 
//! instantiated by using them in the file of definition
//? to avoid this problem function templates should be defined in header files
//* function templates are special exceptions to the ODR (one definition rule)
// The ODR says that types, templates, inline functions, and inline variables are allowed to have identical 
// definitions in different files
//! and instantiated function from function templates are implicitly inline

//? this function is usable for a variety of types but we are restricted to the parameter types
//* if we would like to have a max() function for double values we would have to overload the function
int max(int a, int b){
    return a>b? a:b;
}

//? templates allows us to hand the hard overloading part to the compiler 
//* we only define one definition of the function and determine the actual types used later
template <typename T> //template parameter declaration
T max(T a, T b){ // usage of the template type in our function
    return a>b? a:b;
}
//? the compiler creates following overloaded functions for us in the background
//* these are called function template specializations and can be added manually
template<>
double max(double a, double b){ 
    return a>b? a:b;
}

//? Not all types that can be passed to template functions make sense semantically 
//! for example adding 1 to a std::string would throw a compiler error
//! or adding 1 to a C like string would cause pointer arithmetic and move the starting position 1 up
template <typename T>
T addOne(T value){
    return value +1;
}

//? we can use function template specialization to forbid specific types that we know cause undefined behavior
template<>
const char* addOne(const char* value) = delete;
template<>
std::string addOne(std::string value) = delete;

int main (){

    std::cout << max(4,7) << std::endl; // compiler decides between non template or template function
    std::cout << max<>(4,7) << std::endl; //ensures that only the template function is considered
    //? we use the function template annotating the type for the type templates after the function name
    std::cout << max<double>(4.5,4.2) << std::endl; // exchang T for double
    std::cout << max<char>('b','g') << std::endl; // exchange T for char
    std::cout << max<std::string>("abc","abb") << std::endl; // exchange T for std::string

    //? also the usage of static_cast follows the function template rules
    // static_cast<double>(4)

    #if 0
    using namespace std::literals;
    addOne("hello"); // can't be used because it's a deleted function
    addOne("world"s); // """ """
    #endif

    //? usage of function template forwarded by definition in header file
    Function_template_forward_declaration::TemplateFunctions::printType(true);

    return 0;
}