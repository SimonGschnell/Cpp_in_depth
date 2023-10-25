#include <iostream>
#include <cstdint>
#include <vector>
#include <utility>

//? using type aliases to make complex types easier to read
using VecPairSI = std::vector<std::pair<std::string,int>>;
VecPairSI vec;

//! type aliases are commonly used for platform independent coding
//? we can adapt the names of types to their sizes on different platforms
//* we can pivot with the INT_2_BYTE compiler definition which sizes are used on the current platform
#ifdef INT_2_BYTE
using Int8 = char;
using Int16 = int;
using Int32 = long;
#else
using Int8 = char;
using Int16 = short;
using Int32 = int;
using Int64 = long;
#endif

//! fixed size int sizes inside the <cstdint> library are also just type aliases for numeric types
// int_fast8_t uint32_t int8_t ...
//! that's why uint8_t and int8_t are likely to be used for signed/unsigned characters
//? char types print their value as ASCII characters rather than integer values
std::int8_t x{ 97 }; // int8_t is usually a typedef for signed char


//? if you need to use type aliases in multiple files, they can be defined in header files and included into other code files

int main(){

    std::cout << x << std::endl;

    //? type aliases just introduce a new identifier for an existing type
    //* they don't actually define a new type

    // creation of a type alias
    //! preferred variant over typedef because it declares type aliases in a clearer manner
    using TypeAlias = int[3];
    // creation of a type alias using the backwards compatible typedef keyword
    //? typedef are still in c++ for backwards compatibility
    typedef int Abc; 

    Abc number{3};
    std::cout << number << std::endl;
    
    TypeAlias three_ints{1,2,3};
    for (int i : three_ints) {
        std::cout << i << std::endl;
    }

    return 0;
}