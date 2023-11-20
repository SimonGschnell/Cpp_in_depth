#include <iostream>
#include <vector>

//? std::vector is defined in the <vector> header as a class template

int main (){

    //? default constructor with template argument int 
    std::vector<int> empty{};
    //? creating a list with 4 integers
    std::vector<int> int_vector{1,6,2,9};
    //? non-const vectors cannot hold const values
    // std::vector<const int> int_vector2{1,6,2,9}; //! compiler error
    //? std::vector objects can be made const, they have to be initialized and the elements are treated as const
    const std::vector<int> const_numbers{1,6,2,9};
    //? creating a list with 4 chars and deducing the template argument
    //! class template argument deduction is only available in C++17 and above
    std::vector vowels{'a', 'e', 'i', 'o'};

    //? elements can be accessed passing a index to the subscript operator[]
    std::cout << int_vector[1] << std::endl;
    //? using an index greater than the number of elements will cause undefined behavior ( array range: 0-N-1 )
    std::cout << int_vector[int_vector.size()] << std::endl;

    //? Arrays are contiguous in memory, elements of array are all adjacent in memory
    //* every element in the container can be accessed directly and with equal speed, regardless of the number of elements in the container
    std::cout << sizeof(int) << std::endl; // sizeof(int) = 4
    std::cout << &(int_vector[0]) << std::endl; //0x557fdfd912b0
    std::cout << &(int_vector[1]) << std::endl; //0x557fdfd912b4
    std::cout << &(int_vector[2]) << std::endl; //0x557fdfd912b8

    //? std::vector contains a explicit constructor to create a vector with a specific size where all elements are value initalized
    //! it must be called with direct initialization () instead of direct list initialization {}
    std::vector<int> n10(10);
    //? std::vector has two different constructors that match this initialization:
    std::vector<int> data{ 10 }; // what does this do?
    //{ 10 } can be interpreted as an initializer list, and matched with the list constructor to construct a vector of length 1 with value 10.
    //{ 10 } can be interpreted as a single braced initialization value, and matched with the std::vector<T>(int) constructor to construct a vector of length 10 with elements

    //? { 10 } is interpreted as an initializer list because of the curly braces
    //! Normally when a class type definition matches more than one constructor, the match is considered ambiguous and a compilation error results
    //! However, C++ has a special rule for this case: A matching list constructor will be selected over other matching constructors
    std::cout << n10.size() << std::endl;
    std::cout << data.size() << std::endl;

    //! a big downside of std::vector is that it cannot be made constexpr
    //? if you need constexpr arrays, use std::array instead

    return 0;
}
