#include <iostream>
using namespace std::literals;

//? each type in the unscoped enumerations is defined in the scope where the enumeration is defined
//* if we would define a unscoped enumeration in the global scope all of its types would also be defined in the global scope
//! this can cause naming collisions

    //? definition for unscoped enumerations
    //* each enumerated type is considered to be a distinct type that can be distinguished
    //! enumerations are integral symbolic constants that hold an integral value
    enum Color{
        red, // integral value 0 
        green, // integral value 1
        blue, // integral value 2
        purple // integral value 3
    };

    //? the integral value of an enumeration type can also be set explicitly (negative and positive numbers)
    //* every following type where the integral value is not set will be 1 greater than the previous type
    enum Color2{
        color2_red = 3, // integral value 3
        color2_green, // integral value 4
        color2_blue = -2, // integral value -2
        color2_purple // integral value -1
    };

    //? we could avoid naming collisions with unscoped enumerations by defining them in a namespace
    namespace ShoeColor{
        enum ShoeColor{red,green,blue}; 
    }

    //? enums can be used for functions to make a choice between multiple options
    enum SortOrder
    {
        alphabetical,
        alphabeticalReverse,
        numerical,
    };

    void sortData(SortOrder order)
    {
        switch (order)
        {
            case alphabetical:
                // sort data in forwards alphabetical order
                break;
            case alphabeticalReverse:
                // sort data in backwards alphabetical order
                break;
            case numerical:
                // sort data numerically
                break;
        }
    }

    //? we can return string_views as constexpr
    constexpr std::string_view Color_to_string(Color color){
        switch (color){
            case red: return "red"sv; break;
            case green: return "green"sv; break;
            case blue: return "blue"sv; break;
            case purple: return "purple"sv; break;
            default: return "???"sv;
        }
    }

    //? we can also teach the << operator how to print user-defined enumerations
    #if 0
    std::ostream& operator<<(std::ostream& out, Color color)
    {
        switch (color)
        {
        case green: return out << "green";
        case red:   return out << "red";
        case blue:  return out << "blue";
        case purple:  return out << "purple";
        default:    return out << "???";
        }
    }
    #endif

int main(){

    //? There are two types of enumerations
    //* unscoped enumerations
    //* scoped enumerations

    //? usage of the unscoped enumerations
    Color apple{red};
    Color shirt{green};

    //? unscoped enumerations does not pollute the global scope this way
    ShoeColor::ShoeColor shoe_color{ShoeColor::red};

    //? we can use equality operators to test enumerations for equality
    if (shoe_color == ShoeColor::green){
        std::cout << "ShoeColor is green" << std::endl;
    }else if (shoe_color != ShoeColor::red){
        std::cout << "ShoeColor is not red" << std::endl;
    }else{
        std::cout << "ShoeColor surely not green" << std::endl;
    }

    //? when using an enumeration type it will be implicitly converted to its integral value if the operator does not know how to print a value of that enumeration type
    std::cout << "The type Color::green printed: " << Color::green << std::endl; // will convert Color::green to 1

    //? we can write our own enumeration to string conversion function and use it
    std::cout << "Color::purple converted to string: " << Color_to_string(Color::purple) << std::endl;

    //? by overloading the << operator we can print the enumeration types directly
    
    //* we can read in a enumeration type using static_cast to convert int values to the enumeration types
    //! int values will not implicitly convert to enumerated types thats why we need to cast
    int input_color_int{};
    std::cout << "please enter a color: ";
    std::cin >> input_color_int;
    Color input_color{static_cast<Color>(input_color_int)};
    
    std::cout << "the following color has been choosen: " << Color_to_string(input_color) << std::endl;

    return 0;
}