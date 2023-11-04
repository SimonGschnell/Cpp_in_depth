#include <iostream>
#include <utility>

//! just like function templates, class templates are exempt from the one-definition rule
//! and should be defined in the header file to make them available to all code files where their usage is required


//? class templates are similar to function templates
//* we can define a dynamic type that can be used for data members
template <typename T>
struct Pair {
    T first{};
    T second{};
};

//? the same as for function templates we can ourself define how a specific type should be implemented on the struct 
//* this is also what would have been created by the compiler when using the struct with std::string as template typename
//  Pair<std::string> pair{};
template<>
struct Pair<std::string>{
    std::string first{};
    std::string second{};
};

//? using class templates makes it possible to overload functions that use the struct type as parameter
//* because not only does the return type vary but also the class template typename used for the struct
constexpr int max(Pair<int> p){
    return p.first < p.second ? p.second : p.first;
}

constexpr double max(Pair<double> p){
    return p.first < p.second ? p.second : p.first;
}

//? using function template in combination with class template allows us to cover every type 
//* including the two max definitions before
template <typename T> T max( Pair<T> p ){
    return p.first < p.second ? p.second : p.first;
}

template <typename T, typename U> void print_pair( std::pair<T,U> p ){
    std::cout << (p.first < p.second ? p.second : p.first) << std::endl;
}

int main(){

    Pair<int> p_int {1,8};
    Pair<double> p_double {4.3,3.9};

    std::cout << max(p_int) << std::endl; //? will use the overloaded int method
    std::cout << max(p_double) << std::endl; //? will use the overloaded double method

    std::cout << max<double>(p_double) << std::endl; //? we can also be explicit about whether to take the function template

    std::cout << max(Pair<std::string>{"simon", "patrick"}) << std::endl; //? will use the function template max function
    
    //? the utility library includes a class template for pairs that should be used over custom pair types
    std::pair<int,double> pair_var { 55, 61.3};
    print_pair(pair_var);

    return 0;
}