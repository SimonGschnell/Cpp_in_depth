#include <cmath> 
#include <iostream>

// A modular square root function
double mySqrt(double value){

    if(value < 0){//? raises an exception when trying to take the square root of a negative number
        //* the function throws and exception but does not handle it itself, it delegates the exception to the caller to handle it (just like return codes)
        throw "Cannot take the square root of a negative number";
    }
    return std::sqrt(value);
}

//? Even though mySqrt raises an exception, it is not catched by the intermediate function wrapperMySqrt because the catch block does not handle any char* exception
//* therefore the function callstack is unwinded once more to the main function
//! also all local variables like val are destroyed and no return value is returned
double wrapperMySqrt(double value){
    double val{};
    try{
        val = mySqrt(value);
    }catch(int exception){
        std::cout << "int exception was found" << std::endl;
    }
    return val;

}

//* when trying to resolve an exception the function call stack is unwinded until it finds a matching handler
//* which means all the local variables are also destroyed when unwinding and no value is returned from the functions when unwinding
//? When processing exceptions, each function up the call stack is checked if the exception is handled and continues until either a handler is found,
//? or all of the functions on the call stack have been checked and no handler can be found.

int main()
{
    std::cout << "Enter a number: ";
    double x {};
    std::cin >> x;

    try{
        double sqrt_x = wrapperMySqrt(x);
        std::cout << "the square root of " << x << " is " << sqrt_x << std::endl;
    }catch(const char* exception){  
        //? the main function in the function call stack catches the exception because it has a appropriate catch block 
        std::cout << exception << std::endl;
    }
    //* execution continues after the matching catch block handled the raised exception
    std::cout << "end of main" << std::endl;
    

    return 0;
}