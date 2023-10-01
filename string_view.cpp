#include <iostream>
#include <string_view>
#include <string>

using namespace std::string_view_literals;

void print_name(std::string_view name);

int main () {

    //? to address the issue that std::string is expensive to initialize we use std::string_view
    //* lives in the <string_view> header


    //? the string_view type gives us a read_only access to a string literal
    //* this way we can avoid expensive string copies when we don't actually need to modify the string
    std::string_view name {"Simon Gschnell"};
    print_name(name);

    //? string_views can be created from all three types of strings
    // literals
    // std::strings
    // std::string_views
    std::string_view fromLiteral{"test"};
    std::string str = "test";
    std::string_view fromString{str};
    std::string_view fromStringView{fromString};

    //? all three types also implicitly type cast to string_view
    print_name("literalName"); // implicit cast from c-style string literal to string_view
    print_name(str); // implicit cast from std::string to string_view

    //? a string_view can be created with a suffix from the namespace std::string_view_literals
    std::string_view fromSuffix {"viewFromSuffix"sv};
    
    //* we can also change the view without expensive copy
    fromSuffix = "other string";


    //? string_view has full support for constexpr optimization
    constexpr std::string_view some_view {"hello world"};


    return 0;
}

//? function parameter does not do an expensive copy of the string
void print_name(std::string_view name) {

    std::cout << name << std::endl;
}