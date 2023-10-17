#ifndef INLINE_FUNCTIONS_VARIABLES_H
#define INLINE_FUNCTIONS_VARIABLES_H

//* inline functions can be defined in the header file because 
//* the inline keyword makes multiple definitions of the same function in different files possible
//? useful for header-only libraries
namespace Utils {
    inline int min(int a, int b) { 
        return (a < b) ? a : b;
    }
}

//* inline has the same effect for const global variables, modifying one of the globals 
//* does not need recompilation of all files that use the global constants
namespace constants {
    inline constexpr float pi{3.14f};
    inline constexpr float gravity{9.8f};
}

#endif