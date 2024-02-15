#include <iostream>

//? in c++ all functions are either non-throwing or potentially throwing functions
//* non throwing function is one that promises not to throw an exception 
//* potentially throwing functions are those that may throw exceptions during execution

//? we can mark a function as non-throwing using the "noexcept" specifier
//! noexcept doesn't actually prevent the function from throwing exceptions, or calling other functions that throw exceptions
//! if exceptions exit a noexcept function std::terminate is called, exceptions inside noexcept functions should be handled internally and not exit the noexcept function
void greeting() noexcept { //* specified as non-throwing
    std::cout << "hello there!" << '\n';
    try{
        //? this is fine because it is handled internally by the catch block
        throw 3;
    }catch(int exception){}
    
}

void throwingFunction() {
   //? function is a potentially throwing function where exception are allowed to leave the function to the caller
   throw 1;
}

void throwingNoExceptFunction() noexcept {
    //! exception will leave the noexcept function and std::terminate will be called
    throw 1;
    std::cout << "Throwing function" << '\n';
}

void nonThrowingFunction() noexcept {
    try{
        //? we can call functions that throw exceptions inside noexcept functions as long as they are handled inside
        throwingFunction();
    }catch(int exception){
    }
    std::cout << "Non throwing function" << '\n';
}

int main(){

    greeting();
    nonThrowingFunction();
    throwingNoExceptFunction();



    return 0;
}