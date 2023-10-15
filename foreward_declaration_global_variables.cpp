
#include <iostream>

//* compilation command: 
// g++ -Werror -Wshadow -o main foreward_declaration_global_variables.cpp exposing_globals.cpp external_linkage.cpp

//? foreward declarations for externally linked global variables
extern std::string global_string;
extern const int global_int;

//? no extern keyword needed to foreward declare a externally linked function
void global_function();

//! foreward declarations of best practice global variables through getter method
std::string get_g_name();
std::string get_g_salutation();
//? product of globals that maintain modularity 
std::string greetings(std::string, std::string);

int main(){

    std::cout << "usage of best practice global variable: " << get_g_name() << std::endl ;
    std::cout << greetings(get_g_salutation(),get_g_name()) << '\n' << std::endl;

    std::cout << global_string << std::endl;
    std::cout << "external link to const global variable with extern keyword: " << global_int<< std::endl;
    std::cout << "externally linked functions don't need the extern keyword to be foreward declared: "  << std::endl;
    global_function();
}