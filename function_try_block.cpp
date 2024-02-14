#include <iostream>

class Base{
    private:
        int m_base{};
    public:
        Base(int value): m_base{value}{
            if(value <= 0) throw 1;
        } 
};

class Derived: public Base{
    public:
        Derived(int value): Base{value}{
            //? how are we supposed to catch the exception raised by the failed creation of the Base object, when creation was done in the initialization list
        }
};

//? In order to catch exceptions that are raised when calling parent class constructors, we have to use function try blocks
//* function try blocks can capture exceptions that are raised from the initialization list or inside the body of the function
//! in contrast to normal catch blocks, function level catch blocks have to rethrow the new/original exception they cannot handle the exception themselves 
class Derived2: public Base{
    public:
        Derived2(int value) try : Base{value}{
        //* function try block captures everything inside the function including the intialization list    
        }catch(const int exception) {
            //! function level catch blocks have to rethrow the exception
            //? here we catch the failed creation of the parent Base object
            std::cout << "creation of Base failed" << std::endl;

            //* not rethrowing the exception with "throw" would still implicitly rethrow the exception at the end of the function catch block
            throw;
        }
};

int main(){

    try{
        Derived d{-1};
    }
    catch(const int exception){
        std::cout << "main catch block" << std::endl;
    }

    try{
        Derived2 d2{-1};
    }
    catch(const int exception){
        std::cout << "main catch block" << std::endl;
    }

    return 0;
}