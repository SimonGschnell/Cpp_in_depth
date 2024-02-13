#include <iostream>
#include <memory>
#include <string>
#include <limits>
#include <exception> //? includes std::exception
#include <cstddef>
#include <stdexcept>

class Resource{
    public:
        Resource(){
            std::cout << "Resource was created" << std::endl;
        }
        ~Resource(){
            std::cout << "Resource was destroyed" << std::endl;
        }
};

//? using primitive types for exceptions is vague because it is hard to connect exceptions to the caller or reason their meaning
//* Creating classes that are meant to describe exceptions and provide context for what went wrong
//? Custom exception classes can also inherit from std::exception or std::runtime_error to have the same behavior as standard library exceptions
class BaseException: public std::exception {
    private:
        std::string m_description{};
    public: 
        BaseException(std::string_view description): m_description{description}{}
        const std::string& getError() const { return m_description; }
        //* https://en.cppreference.com/w/cpp/error/exception/what
        const char* what() const noexcept override { return m_description.c_str();}
};

//? custom exception inheriting from std::runtime_error
class CustomException: public std::runtime_error {
    public:
        //? no need to override .what because that's is done for us by std::runtime_error when we pass a message to its constructor
        CustomException(const std::string& message): std::runtime_error{message}{}
};

class Base{
    private:
        int m_base{};

        //? class members are desctructed even if the constructor fails
        //* prefere doing resource allocation inside of the members and not in the constructor, those members can then clean up after themselves when they are destructed
        //? that is why RAII is so highly advocated
        Resource m_resource{};
        
        //? instead of creating classes our own to manage resources with the RAII principle, we can use RAII-compliant classes from the standard library
        //* RAII unique_ptr will be deallocated when the constructor of the class fails (no complicated cleanup procedures necessary)
        std::unique_ptr<int> m_unique_resource{};

    public:
        Base(int value): m_base{value} {
            if(value < 0){
                //? raises an exception in the constructor
                //! exceptions in the constructor fails the construction of the object and the Destructor will not be called to destroy the initialized properties properly
                throw BaseException("value cannot be negative");
            }
            
        }
        ~Base(){
            std::cout << "Base destructor was called" << std::endl;
        }
};

class Derived: public Base{
    public:
        Derived(int value):Base{value}{}
};

int main(){

    try{
        Base b1{-1};

    }catch(const BaseException& exception) //? we catch the exception always by const reference to avoid expensive copies of class objects
    //! since BaseException is its own type, we can catch exceptions from the Base class and treat them differently from other exceptions
    {
        std::cout << "int exception: " << exception.getError() << std::endl;
    }

    //? exception thrown by derived classes
    try{
        throw Derived(1);
    }catch(const Base& exception){  
        //! because Derived inherits from Base, so they have a Derived is-a Base relationship, 
        //! therefore the Base catch block will handle the Derived error
        //? order is important when catching Derived versions, always start with the most derived class and end with the most basic class
        //~ because Derived is-a Base, but Base is not a Derived, and thus will fall through to the Base handler at the end
        std::cout << "Base was catched" << std::endl;
    }catch(const Derived& exception){
        std::cout << "Derived was catched" << std::endl;
    }


    //? The standard library also uses Exception classes and all of those inherit from a interface Base class called std::exception
    //* link to a list of all standard library exceptions : https://en.cppreference.com/w/cpp/error/exception
    try
    {
        std::string s;
        s.resize(std::numeric_limits<std::size_t>::max()); // will trigger a std::length_error or allocation exception
    }
    //? if we want to handle a specific exception from the standard library differently we can redirect to the corresponding catch block 
    //! every other standard library exception will fall through to the base catch clause
    catch (const std::length_error& exception){
        //* std::length_error inherits from the interface std::exception and also has its own version of .what()
        std::cout << "specifically handle std::length_error differently, message: " << exception.what() << std::endl;
    }
    //? This handler will catch std::exception and all the derived exceptions too
    catch (const std::exception& exception)
    {
        //? .what() is the virtual function from the std::exception interface
        std::cerr << "Standard exception: " << exception.what() << '\n';
    }
    
    try
    {
        //? std::runtime_error is a popular option when throwing a standard library exception because it has a constructor that accepts a customizable message
        //* std::runtime_error is inside the library <stdexception>
        throw std::runtime_error("raised runtime error");
    }
    //? catching exception with the base class
    catch (const std::exception& exception){
        std::cout << exception.what() << std::endl;
    }


    return 0;
}