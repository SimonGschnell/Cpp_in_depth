
#include <iostream>

//? foreward declarations for externally linked global variables
extern std::string global_string;
extern const int global_int;

//? no extern keyword needed to foreward declare a externally linked function
void global_function();

int main(){
    std::cout << global_string << std::endl;
    std::cout << "external link to const global variable with extern keyword: " << global_int<< std::endl;
    std::cout << "externally linked functions don't need the extern keyword to be foreward declared: "  << std::endl;
    global_function();
}