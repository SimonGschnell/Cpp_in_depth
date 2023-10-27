#include <iostream>

//? we can specify non-type template parameters like normal parameters in angle brackets <>
//* the naming convention for non-type parameters starts with N... and goes on ,O,P
//! non-type parameters are used to pass constexpr parameters to function templates 
//! usefull when constexpr values are needed inside a function template
template <int N> auto constexprTemplateParameters (int a=2){
    static_assert(N != 0); //! static_assert only works with constexpr arguments
    #if 0
    static_assert(a == 2); // won't compile because normal parameters are not constexpr values 
    #endif
    if constexpr ( N >= 3 ){
        std::cout << "N is equal or greater 3" << std::endl;
    }else{
        std::cout << "N is less than 3" << std::endl;
    }
}

int main(){
   
    int a {3};
    constexpr int b {3};
    #if 0 
    constexprTemplateParameters<a>(); // won't compile because the non-type parameters has to be a constexpr 
    #endif
    constexprTemplateParameters<b>(); // pass - b is a constexpr value
    constexprTemplateParameters<3>(); // pass - 3 is a constexpr value

    return 0;
}