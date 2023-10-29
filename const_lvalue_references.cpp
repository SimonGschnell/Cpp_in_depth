#include <iostream>

const int global_var{44};

int main(){

    const int number {5};
    int num{55};
    #if 0
    int& ref_number {numer}; // we are not allowed to make references to non-modifiable lvalues 
    // because otherwise we would be able to change the const value through the reference
    #endif 

    //? for const lvalues we can create const lvalue references
    // now also this reference is non-modifiable 
    const int& ref_number {number};  
     
    
    //? making constant references to mutable lvalues is a great practice when only reading the variable is needed
    const int& const_ref_to_mutable{num};
    //? allowed to use the reference
    std::cout << const_ref_to_mutable << std::endl; 
    //! const_ref_to_mutable +=1; not allowed to change the value
   
    //? we can also create const lvalue references to rvalues
    //* rvalues generate a temporary object which lifetime would go out of scope after the expression it was used in
    //* when we use rvalues as initalizers for references we expand rvalues lifetimes to the lifetime of the reference
    const int& ref_rvalue {5}; 

    //? references can also be constexpr references but they are limited to variables with static duration
    //* this is because the compiler knows the address of the identifier at compile time
    constexpr const int& ref_static{global_var};
    //? constexpr references can be used where constexpr values are required, for example for static assertions
    static_assert(ref_static > 0);  
    //! static_assert(ref_rvalue > 0); this throws a compiler error
    

    std::cout << ref_number << std::endl;
    

    return 0;
}