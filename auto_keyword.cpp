#include <iostream>
#include <string>
#include <string_view>

//? type deduction on functions is also possible using the auto keyword
//! functions using auto as return type cannot be used before they were defined (no function forwarding)
auto return_numerics(std::string value){
    if ( value == "int" ) return 5;
    //! functions using type deduction can not use different types in return statements 
    #if 0
    else if ( value == "double" ) return 4.0;
    else return 3.0f;
    #endif
}

int add(int x, int y){
    return x + y;
}

int main(){

    //? types like double can be implicitly determined via the format of the literal used
    //* 5.0 will be implicitly double 
    double fpn {5.0};

    // keywod for type deduction = auto
    //? type deduction / inference is used to deduce the type of the object to the object initializer
    //* because 5.0 will be double, also the d variable will receive the type double 
    auto d {5.0};
    //? also functions are valid expressions that we can use to deduce the type for a variable
    //* because function add() returns the int type also the variable addition will receive the type int
    auto addition {add(4,9)};
    
    //! type deduction can not be used on none or empty initializers
    #if 0
    auto a{}; // compiler error - cannot deduce 'auto' type
    auto b; // compiler error - cannot deduce 'auto' type (initializer required)
    #endif

    //? type deduction with the auto keyword will drop the const & contexpr characteristic 
    const int i{3};
    auto deducted_i{i};
    deducted_i +=2;
    std::cout << "type deducted variables lose the const/contexpr characteristic, 3 was raised to " << deducted_i << std::endl;
    
    //? we can supply the const & contexpr characteristic on to the deduced type by reapllying it
    // now the deduced type is const again
    const auto const_deducted_i{i};
    #if 0
    const_deducted_i += 2; // compiler error - ezpression must be a modifiable lvalue
    #endif 

    //? deducting the type of a C like string will deduce to a char* pointer
    //! if you want the literal to deduce to std::string or std::string_view, the corresponding suffixes have to be used
    auto Clike {"c_like_string_literal"};
    //* "c_like_string_literal" will convert to "string_literal"
    auto shortened_Clike =Clike+7; // +7 on char* will result in pointer arithmetic and shift the pointer 7 chars forward
    std::cout << shortened_Clike << std::endl;

    //? C like strings can be deduced to std::string and std::string_view using the corresponding suffixes in std::literals
    using namespace std::literals; // needed for std::string (s) and std::string_view (sv) suffixes
    auto string_deduce {"string"s};
    auto string_view_deduce {"string_view"sv};

    //? now type methods can be used on the deduced types
    string_view_deduce.remove_prefix(7);
    std::cout << string_deduce.substr(0,3) << std::endl;
    std::cout << string_view_deduce << std::endl;



    return 0;
}