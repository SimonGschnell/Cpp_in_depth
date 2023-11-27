#include <iostream>
#include <array>

//? passing std::arrays is similar to pass std::vectors, we pass the container by const reference to avoid expensive copying
//* but when we use a std::array as function parameter we have to define the full type for the container
// type and length has to be defined //! no CTAD for function parameters
void print_first_in_array(const std::array<int,5>& arr){
    std::cout << std::get<1>(arr) << std::endl;
}

//? if we combine type and non-type function templates, we can pass an array with dynamic type and length
//! if the non-type template parameter would be int instead, we wouldn't be able to use CTAD when calling the function
//! because CTAD passes the returned value from .size which is std::size_t and template parameters don't do conversions
//~ in C++20 to avoid looking up the type of the non-type template parameter, type deduction with auto can be used
//~ template <typename T, auto len>
template <typename T, std::size_t len>
void dynamic_print_first(const std::array<T,len>& arr){
    //* non-type template parameters are compile time constants and can be used where constexpr values are needed
    // static_assert(1<len); //! to assert if the array even has 1 element
    std::cout << std::get<1>(arr) << std::endl;
}



int main(){

    std::array arr{3,1,8,3}; //* using CTAD to construct and deduce an array of <int,4>
    // print_first_in_array(arr); //! now this throws an compiler error because the function parameter expects an array with length 5 not 4

    //* calling the template function with both template parameters
    dynamic_print_first<int,4>(arr);
    //? we can simply pass the array and both the type and the length of the passed array will be deduced
    dynamic_print_first(arr); 



    return 0;
}