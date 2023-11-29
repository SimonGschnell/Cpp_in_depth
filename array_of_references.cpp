#include <iostream>
#include <array>
#include <functional>


int main(){
    
    constexpr int a{1};
    constexpr int b{2};
    int c{3};
    int d{4};

    //? we can have arrays of primitive types and of objects
    constexpr std::array array_of_primitives{a,b};
    std::array array_of_pointers{&a ,&b};

    //? but we can not make arrays of references because they are no objects and are not assignable
    const int& a_ref{a};
    const int& b_ref{b};
    // this will actually deducte the array type to <int,2>
    std::array array_of_references{a_ref,b_ref};
    //std::array<int&,2 > array_of_references{a_ref,b_ref}; //! compile error

    //~ there is a workaround with the class template std::reference_wrapper inside the <functional> std library
    //* with the .get() member function of std::reference_wrapper we are able to get a reference to underlying element
    int& c_ref{c};
    int& d_ref{d};
    std::array<std::reference_wrapper<int>,2> reference_array{c_ref,d_ref};

    //? while std::get<0>() returns the element at index 0 and does bounds checking at compile time
    //? the .get() does return a reference to the underlying value 
    //* here we store a reference of the first element in the reference array
    int& first_element_reference {std::get<0>(reference_array).get()};
    //* and we are allowed to modify it
    first_element_reference =44;
    for(const auto& element : reference_array){
        std::cout << element << std::endl;
    }



    return 0;
}