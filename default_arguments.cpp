#include <iostream>

//? we can define default arguments for functions by providing fallback values for function parameters
//* equal sign must be used to specify a default argument
void print_greeting(std::string greeting = "Hello", std::string name = "Simon Gschnell"){
    std::cout << greeting << " " << name << std::endl;
}

//? all subsequent parameters after the first default argument must also be default arguments
//! following function won't compile, because a syntax like add(,4) is not supported
#if 0
int add(int x=10, int y){
    return x + y;
}
#endif

//? the default argument can be set in the forward declaration or in the function definition 
//! but not in both
//* best practice: define the default argument in the forward declaration because it is more seen and clear
int returnNumber(int num=3);

int returnNumber(int num){
    return num;
}

int main(){

    //* usage of the function with the values of default arguments
    print_greeting();
    //* usage of the function with 1 specified argument value
    print_greeting("Bounjour");
    //* usage of the function with specified argument values
    print_greeting("Ola", "Juan");

    //? default value for the default argument defined in the forward declaration
    std::cout << returnNumber() << std::endl;

    return 0;
}