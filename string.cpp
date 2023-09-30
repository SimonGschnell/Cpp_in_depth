#include <iostream>
#include <string> //header for std::string & std::getline


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
    std::cout << "your name contains " << name.length() << " charactesr" << std::endl;


    return 0;
}