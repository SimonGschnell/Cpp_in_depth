#include <iostream>
#include <string>
#include <string_view>
#include <exception>
//? Exceptions in C++ are imlemented with the 3 keywords:
//* throw, try, catch
//* throw = a throw statement is used to signal that an exception or error has occurred, also called raising an exception

int main(){

    //~ A try block must have at least one catch block immediately following it, but can have multiple catch blocks in sequence
    //? with the try keyword we are able to detect if exceptions were raised inside a block of code
    try{
        //? with the throw keyword we can raise an exception that can be customized
        throw -1; // throw a literal integer value
        //throw ENUM_INVALID_INDEX; // throw an enum value
        throw "Can not take square root of negative number"; // throw a literal C-style (const char*) string
        //throw dX; // throw a double variable that was previously defined
        //throw MyException("Fatal Error"); // Throw an object of class MyException

        //? exceptions disrupt the normal flow of execution, which means that if an exceptions is raised it will jump to the nearest catch block with matching exception type
        //* and any other statement after the point where an exception is raised will be skipped
        std::cout << "this never prints" << std::endl;

    //? with the catch keyword we are able to define a block of code (catch block) that handles exceptions for a single data type
    }catch(int err){ //* catch block that will catch integer exceptions
        std::cerr << "An integer exception was raised: " << err << std::endl;
    }catch(const std::string&) //? we can add multiple catch blocks in sequence, exceptions types will not be converted to match a catch block
    {
        std::cerr << "An string exception was raised: " << std::endl;
    }

    return 0;
}