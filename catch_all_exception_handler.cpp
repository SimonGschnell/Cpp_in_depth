#include <iostream>

//! if a exception was raised and does not get handled by any function
//* it is optional if the function call stack is unwinded or not in this case, and at the end a std::terminate is always called
//* if the function call stack is not unwinded, the local variables are not properly destroyed

int main(){

    try{
        //? raise an integer exception
        throw 5;
    }
    //* this catch block will only catch double exceptions, not integer exceptions
    catch(double exception){
        std::cout << "double exception was caught" << std::endl;
    }
    //* the ellipsis operator ... is used to catch any type of exception
    //? catch all handler
    //! catch all handler are always last in the catch sequence chain, so that other specific types can be handled by the appropriate exception handler
    catch(...){
        //* the catch all handler ensures that the function call stack is unwinded properly
        //? the catch all handler is often left empty
        std::cout << "exception of unknown type was caught" << std::endl;
    }
    


    return 0;
}