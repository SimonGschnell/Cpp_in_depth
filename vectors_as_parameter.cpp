#include <iostream>
#include <vector>
#include <assert.h>


//? the element type is part of the std::vector type and has to be defined when passing a vector as argument
//! we pass vectors as const references because they are expensive to copy
void print_first_int(const std::vector<int>& vec){
    std::cout << vec.at(0) << std::endl;
}

//? template functions are used to use vector with any element type as parameter
template <typename T>
void print_vector(const std::vector<T>& vec){
    for(T element : vec){
        std::cout << element << std::endl;
    }
}

//? using a generic template to allow all parameters that implement the subscript operator
//! compiler error otherwise
template <typename T>
void needs_to_have_subscription_operator(const T& value){
    std::cout << value[0] << std::endl;
}

//? c++ will allow us to access indexes that are out of bounds and cause undefined behavior
//* best option is to avoid functions that rely on vectors with minimum lengths
void print_third_element(const std::vector<int>& int_vec){
    //* assertion has to be made to check if the array even has enough elements
    //! std::vector::size is non-constexpr and therefore we cannot assert at compile time
    //? the following assert function will assert at runtime
    assert(int_vec.size() >=3);
    std::cout << int_vec[2] << std::endl;
}

int main(){

    std::vector<int> array{1,7,3,2};
    std::vector<int> small_array{1,2};
    std::vector<double> double_array{4.13,6.55,1.1};
    print_vector(array);
    print_vector(double_array);

    
    std::string string_var{"hello world"};
    char char_var{'a'};
    needs_to_have_subscription_operator(array);
    needs_to_have_subscription_operator(string_var); //? std::string does implement the subscript operator
    //needs_to_have_subscription_operator(char_var); //! compiler error because char doesn't support the subscript operator
    // print_third_element(small_array); //! asserts at runtime

    return 0;
}