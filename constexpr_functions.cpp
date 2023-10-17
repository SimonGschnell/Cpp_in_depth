#include <iostream>
#include <type_traits> // for std::is_constant_evaluated

//? normal functions execute at runtime 
int max(int a, int b){
    return (a > b)? a:b;
}

//? constexpr function call (if it is eligible) can be evaluated at compile time 
//! function must return constexpr return type and not call other non-constexpr functions
//* if a constexpr function is not eligible it will evaluate at runtime
constexpr int greater(int a, int b){
    //!constexpr functions are implicitly inline

    //? in C++20 you can use the <type_traits> header with function std::is_constant_evaluated()
    //? to determine if a function is actually evalutated at compile time
    #if 0
    if(std::__is_constant_evaluated()){
        std::cout << "is_constant_evaluated" << std::endl;
    }
    #endif
   
    return (a > b)? a:b;
}

//? C++20 introduces the keyword consteval for constexpr functions
//* it indicates that the function must evaluate at compile time otherwise it errors out
#if 0
consteval int great(int x, int y){
    return (x > y) ? x : y;
}
#endif


int main(){

    constexpr int x{5};
    constexpr int y{6};

    int a{1};
    int b{4};

    //? with the usage of a normal function we can'nt compute the result at compile time
    std::cout << max(x,y) << std::endl;

    //? a constexpr function will only evaluate at compile time if it used where a constexpr value is needed
    //* otherwise the compiler can decide whether it evaluates at compile time or runtime
    // x & y are constexpr values

    std::cout << greater(x,y) << std::endl; //! evaluate at COMPILE TIME or RUNTIME
    constexpr int greatest{greater(x,y)}; //! evalues at COMPILE TIME
    std::cout << greater(a,x) << std::endl; //a is non-constexpr //! evaluate at RUNTIME 

    //! in this case the function call will be evaluated at runtime because the arguments are non-constexpr values
    std::cout << greater(a,b) << std::endl; // a & b are non-constexpr values


    return 0;
}