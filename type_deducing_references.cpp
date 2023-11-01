#include <iostream>
using namespace std::literals;

int main(){

    //? the auto keyword deduces the type of an expression 
    //! but doing so drops the const / constexpr characteristics
    //! AND it also removes references

    const std::string& name{"Simon"s};
    auto a {name}; //! removes the const and reference characteristic
    const auto& y{name}; //? we have to rewrite those characteristics to reapply them

    a = "adsf"s; // valid
    //y = "asdf"s; //! not valid

    //? 2 types of const levels exist
    //* top-level and low-level const

    const int x{};    // this const applies to x, so it is top-level
    std::string* const ptr{&a}; // this const applies to ptr, so it is top-level

    const int& const_ref{x}; // this const applies to the object being referenced, so it is low-level
    const int* ptr{&x}; // this const applies to the object being pointed to, so it is low-level

    //? both types can be applied
    const int* const strong_ptr{&x}; // the left const is low-level, the right const is top-level

    
    //!type deduction only drops top-level consts. Low-level consts are not dropped.
    //* the same rules apply to constexpr
    //? when a function return a const value& reference, type deduction will first remove the reference, which makes the const top-level and will also be removed
    auto abc {const_ref}; //! removes both the reference and the top-level const after
    auto& abcd {const_ref}; //? the reference characteristic was reapplied and so the const is low-level and won't be removed when deducing the type

    abc =5; //? is allowed
    //abcd =4; //! is not allowed

    //! BEST PRACTICE is to reapply both characteristics for clear code

    //? unlike references, type deduction does not remove pointers
    //type: const int*
    auto deducted_ptr{ptr}; //* const characteristic prevails
    //type: const int*
    auto* deducted_ptr{ptr}; //* same result as above


    return 0;
}