#include <iostream>
#include <array>
#include <string_view>
#include <algorithm>
#include <functional>

//? Lambdas function are just like normal functions but they are just used once as a nested function inside another function
//~ lambdas are most often used as callback functions
//! lambdas have their own types and therefor can only be stored using type deduction auto 
//! or they can be stored inside a std::function or inside a function pointer where the lambda is implicitly converted to that type

//? how can we pass lambdas to functions if they have their own unknown type?
//* we can use std::function where the type is converted or we can use type templates 
//! a disatvantage of this approach is that the definiton of the function has to fully visible to use the funciton
template <typename T>
void execute_sum_lambda(int first, int second, const T& lambda_parameter){
    std::cout <<  lambda_parameter(first,second) << std::endl;
}

//~ instead when using std::function, the function can be forward declared in a header file and implemented in a cpp file
//? another advantage is that the std::function shows which types are passed as parameters and what is returned from the function
//! a disatvantage is that the lambda has to be always implicitly converted to the std::function which is a little overhead
void execute_sum_lambda(int first, int second, std::function<int(int,int)> fun){
    std::cout <<  fun(first,second) << std::endl;
}

int main(){
    //? lambdas are normally unnamed functions but we can store them in variables which make them named functions that can be reused
    //* the [] stand for the captureClause 
    //* the () stand for the parameters for the lambda expression
    //* the {} stand for the body with the logic of the lambda expression
    //? therefore a empty function receiving nothing and returning nothing looks like this
    auto lamda_ptr = [](){};

    //? here a lambda function that just adds two numbers
    //~ storing a lambda in a variable can make code more readable
    auto sum_lambda= [](int a,int b){return a+b;};

    //~ we can specify the return type of a lambda function with -> type after the parameters
    std::function lambda_with_return{[](int a, int b)->int{ return a+b;}};
    
    //? lambdas parameters can also be type deduced with the auto keyword, these types of lambdas are called generic lambdas
    auto generic_lambda {[](auto para1){ std::cout << para1 << std::endl;}};
    generic_lambda("string");
    generic_lambda(7);

    //! as of C++17 all lambdas are implicitly constexpr if they satisfy two requirements:
    //* the lambda must have no captures or all captures are constexpr
    //* the functions used inside the lambda itself have to be also constexpr, many standard library functions were not made constexpr

    //* printing the result of the called lambda function
    std::cout << "the result of the lambda call cum_lambda(3,4): " << sum_lambda(3,4) << std::endl; 
    
    
    using namespace std::string_view_literals;
    constexpr std::array<std::string_view,4> fruits{"apple"sv, "banana"sv, "walnut"sv, "lemon"sv};

    //~ we use std::find_if inside the alorithm library to find a string inside an array
    //* the funstion takes 3 parameters, the start of the array, the end of the array and a function that determines if the searched for value was found 
    //? for the function we use a lambda function that takes a std::string_view parameter and returns a boolean value
    auto found{ std::find_if(fruits.begin(),fruits.end(),[](std::string_view value){
        //* if the string does contain the word nut then we declare that the function find_if does have found a correct string
        return value.find("nut") != std::string_view::npos;
    })};

    //? if the found variable points to the end of the array we know that no desired value has been found
    if(found == fruits.end()){
        std::cout << "the desired value was not found" << std::endl;
    }else{
        //? otherwise we print the value that was found
        std::cout << "the desired value is: " << *found << std::endl;
    }


    //? how to pass lambdas to functions using std::function or template parameters in functions
    execute_sum_lambda(1,2,sum_lambda);
    //* here we pass a anonymous lambda instead
    execute_sum_lambda(4,1,[](int a,int b){return a-b;});


    return 0;
}