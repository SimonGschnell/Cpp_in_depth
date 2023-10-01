#include <iostream>
#include <string> //header for std::string & std::getline

using namespace std::string_literals; // access to std::string "s" suffix


int main(){

    //* the following is a c-style string literal
    //! there can introduce undefined behaviour due to replacing bigger strings into smaller buffers
    auto string_literal = "hello world";

    //? c++ uses std::string and std::string_view
    //* std::string doesn't have a fixed length of bytes, can be of different sizes
    std::string color{};
    std::string name {"Simon"};
    name = "SomeVeryLongName"; //std::string will adapt the size of the type

    //? std::string and std::cin
    //! operator>> returns up to the first whitespace
    //* when inputing "hello world" the first >> would contain "hello" and the second >> "world"

    #if 0
    std::cin >> name;
    //? input: "hello world" , output: "hello"
    std::cout << "your name is: " << name << std::endl;
    #endif

    //? std::ws (whitespace) ignores all leading whitespace characters
    //* std::ws does not preserve across calls
    
    //? use std::getline from <sting> for string user input
    std::cout << "enter your name: " << std::endl;
    std::getline(std::cin >> std::ws,name);
    std::cout << "enter your favorite color: " << std::endl;
    std::getline(std::cin >> std::ws, color);

    std::cout << "your name - " << name << ", your color - " << color << std::endl;

    //? getting the length of a std::string
    std::cout << "your name contains " << name.length() << " characters" << std::endl;

    //! it's discouraged to pass std::string to functions by value because that would create an expensive copy
    //? instead std::string_view is used for those situations

    //? std::strings in returns are fine because they support a move semantic
    //* objects that will be destroyed at the end of the function will be moved by value without making a copy
    //! that is how rust handles move and copy semantics differently and optimized for it

    std::cout << "this is a c-style string literal" << std::endl;
    std::cout << "this is a std::string by suffix 's'"s;

    return 0;
}