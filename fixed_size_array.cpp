#include <iostream>
#include <array>
#include <vector>

//? arrays are fixed size containers, which means their capacity cannot be changed at runtime 
//* however because the size is known at compile time, they can be constexpr and optimized better
//! arrays should be preferred over vectors if the size of the container can be known at compile time


int main(){

    //? the difference between the instantiation of an array over a vector is that
    //? the array defines an extra non-type template parameter which will determine the effective size of the container
    std::array<int, 5> c1{};
    std::vector<int> c2(5);

    //! the non-type template parameter has to be a constexpr value
    //* defines an array of size 5 with literal
    std::array<int, 5> container{};
    //* defines an array of size 6 with constexpr lvalue
    constexpr int len{6};
    std::array<int, len> container2{};
    //* defines an array of size 7 with const int lvalue
    const int val{7};
    std::array<int, val> container3{};
    //* defines an array of size 2 with constexpr enum value
    enum Color{red, green, blue};
    std::array<int, blue> container4{};

    //? std::array is an aggregate and therefore can only be initialized using brace enclosed initializer list 
    std::array<int,5> a{1,2,3,4,5};
    //? in case where the initializer list has less elements than the defined size, the rest will be value initilized
    std::array<int,5> b{1,2,3}; // index 3 & 4 will be value initialized to 0

    //? (CTAD) class template argument deduction can be used for both the type and the length of std::array
    //* same as std::array<int,3> arr{1,2,3};
    std::array arr{1,2,3};

    //* an std::array can be defined as const
    const std::array<int,5> array1{5,6};
    //! and most important an std::array has full support for constexpr
    constexpr std::array<int,5> array2{5,6};
    //! if your std::array is not constexpr, consider using a std::vector instead

    //? like std::vector the most common way to access elements in std::array is to use the subscript operator
    std::cout << "first element of std::array arr{1,2,3} is: " << arr[0] << std::endl;

    return 0;
}