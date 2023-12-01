#include <iostream>
#include <array>

template <typename T, std::size_t N>
//? special syntax that defines a reference to a const C-style array with N elements
//* the & reference symbol needs to be grouped with the name, the name can also be omitted since it is not used in the function body 
std::size_t length(const T (&arr)[N]){
return N;
}

int main (){

    //? because C-style arrays are part of the core language they have their own special definition syntax
    //* just like std::arrays, C-style arrays are aggregates and can make use of aggregate initialization
    //~ C-style arrays can be both const and constexpr, where the elements of the array become immutable
    constexpr int c_arr[3]{1,2,3};

    // c_arr[0]=2; //! compiler error: must be a modifiable lvalue
    //! providing fewer initializer values for the definition of the array will value initialize the remaining elements
    constexpr int c_arr_short[3]{4,5}; 

    //~ we can also let the compiler deduce the length of the C-style array through the aggregate initialization
    constexpr int deduced_c_arr[]{1,2,3};
    constexpr std::array<int,3> arr {1,2,3};

    //? C-style arrays can be indexed with the subscript operator
    //* and they can be index with signed/unsigned/enumeration values without performing narrowing conversions
    std::cout << "The first element inside the c-like array is: " << c_arr[0] << std::endl;

    //* the sizeof global function will return the size of the C-style array, because they have no overhead
    //* they contain their elements and nothing more
    std::cout << "C-style array with 3 int elements, each int 4bytes big: 4*3 = " << sizeof(c_arr) << std::endl;

    //? the get the length of a C-style array we can use the std::size or std::ssize functions 
    //* C-style arrays do not have the .size() memeber function
    std::cout << "size of C-style array using std::size = " << std::size(c_arr) << ", using std::ssize = " << std::ssize(c_arr) << std::endl;
    //? these functions were not available prior to C++17, a user-defined function was used
    std::cout << "prior to C++17, user-defined function was used to get the length of a C-style array: " << length(c_arr) << std::endl;

    return 0;
}