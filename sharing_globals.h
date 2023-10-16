#ifndef SHARING_GLOBALS_H
#define SHARING_GLOBALS_H

namespace Constants_Cpp17 {
    //! C++ 17 introduces the inline keyword which allows multiple definitions of a identifier in multiple files
    //? inline identifiers are externally linked 
    //! all the definitions in different files will be treated as one definition and only recompilation of the header file will be necessary when changing constants
    
    inline constexpr double pi{3.1415};
    inline constexpr double gravity{9.8};
}

namespace Constants_Prev_Cpp17 {

    //! foreward declarations of global constants (constexpr can't be externally linked)
    //! internally linked globals would be redefined in every file that includes them which also need recompilation when constants change
    //? only sharing_globals.cpp has to be recompiled when constants change
    //* these variables are runtime constant values because files that include them only have a foreward declaration
    //* compile-time constants can be optimized more then runtime constants

    extern const double pi;
    extern const double gravity;

}

#endif