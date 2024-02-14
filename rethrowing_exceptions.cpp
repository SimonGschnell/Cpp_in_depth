#include <iostream>
#include <exception>
#include <stdexcept>

//~ When rethrowing the same exception, use the throw keyword by itself

void rethrowing_exception_wrong(){
    try{
        throw std::runtime_error("runtime error");
    }catch(const std::exception& exception){
        //? if we want to log the exception at this point and want to handle the exception in the caller
        std::cout << exception.what() << std::endl;
        //* then we have to rethrow the exception
        //! if we rethrow the exception like this: 
        throw exception; //! the exception object will be copy initialized and returned, causing object slicing
    }
}

void rethrowing_exception_correct(){
    try{
        throw std::runtime_error("runtime error");
    }catch(const std::exception& exception){
        // log error
        std::cout << exception.what() << std::endl;
        //? C++ provides a way to rethrow the same exception that was caugth by using "throw"
        //* this doesn't copy initialize the returned value and avoid object slicing         
        throw;
    }
}

int main(){

    try{
        rethrowing_exception_wrong();
    }catch(const std::exception& exception){
        //! here we catch the sliced object std::exception and not an std::exception pointing to std::runtime_error
        std::cout << exception.what() << std::endl;
    }

    try{
        rethrowing_exception_correct();
    }catch(const std::exception& exception){
        //? here we catch the rethrown exception and no object slicing occurs
        std::cout << exception.what() << std::endl;
    }


    return 0;
}