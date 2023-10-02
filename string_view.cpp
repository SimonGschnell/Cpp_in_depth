#include <iostream>
#include <string_view>
#include <string>

using namespace std::string_view_literals;
using namespace std::string_literals;

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

    //! warning - string_view is dependent on the object being viewed
    //! if the object is modified or destroyed while the view is still being used we encounter undefined behavior
    //? Rust solves this by imposing a rule where not both a reference and a mutable reference can be used at the same time

    //* example
    std::string_view sv{};

    { // creates a nested block
        std::string s{"undef_behavior"};
        sv = s;
    } // variable s goes out of scope here
    
    std::cout << sv << std::endl; //? undefined behavior

    std::string s2{"first_value"s};
    sv = s2;
    s2 = "second_value"; //! we modify the value on which the view was pointing

    std::cout << sv << std::endl; //? undefined behavior
    //* we can REVALIDATE the string_view by assigning sv the new string value
    sv = s2;
    std::cout << sv << std::endl; //* valid

    //? undefined behavior also occurs when initializing a string_view with a string comming from a return value
    //* returned strings are temporary values and therefore undefined behavior occurs
    //? undefined behavior also occurs when returning a string_view that points to a local function variable that goes out of scope at the end of the function
    //* string_views that contain literals or are parameters are OK to return form a function

    //? we can modify string_views with view modification functions
    std::string_view view{"hello world"};
    view.remove_prefix(1); // remove_prefix removes characters from the beginning of the string
    std::cout << view << std::endl;
    view.remove_suffix(6); // remove_suffix removes characters from the end of the string
    std::cout << view << std::endl;
    view = "hello world"; // bringing the view back to the original state
    std::cout << view << std::endl;

    //? modifying the view does not change the string being viewed
    //! when modifying the string_view suffix it is no longer null terminated
    //* usually a string_view not being null terminated does not matter


    return 0;
}

//? function parameter does not do an expensive copy of the string
void print_name(std::string_view name) {

    std::cout << name << std::endl;
}