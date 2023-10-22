#include <iostream>
#include <cassert>

//? static_assert is a keyword that does'nt need a header file
//* static_assert is not compiled out in release builds
static_assert(sizeof(long) == 8, "long must be 8 bytes long");
static_assert(sizeof(int) >= 4, "int must be at least 4 bytes long");

int main(){

    //? we use the NDEBUG define to check whether we evaluate the asserts or not
    //? release builds add the compiler option -D NDEBUG to ignore the asserts when creating the translation unit
    #ifndef NDEBUG
    //? asserts calls std::abort which terminates unconditionally
    //* testing db connections or files like that should be avoided to avoid corruption
    assert(0 && "assert evaluated to false");

    #endif

    return 0;
}