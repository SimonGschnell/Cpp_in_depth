#include <iostream>
#include <array>

enum StudentNames{
    Peter,
    Hans, 
    Simon,
    Charlie,
    Georg,

    Max_Students,
};

namespace Colors{
    enum Type{
        red,
        blue,
        green,
        max_colors,
    };

    //? we can use an constexpr array to hold the respresentational values for all enum members
    //* we use the string_view suffix to deducte the type and length 
    using namespace std::string_view_literals;
    constexpr std::array colorName{"red"sv, "blue"sv, "green"sv};

    static_assert(max_colors == colorName.size());
}

//? we now can define a function that will convert an Color::Type enum member into its string representation
constexpr std::string_view getColor(Colors::Type color){
    return Colors::colorName[color];

}

int main(){
    //? when we deduce the length of the array we might initalize less elements than the enum used for indexing
    constexpr std::array student_grades{33,11,77,55};

    //* we can prevent out of range/bound undefined behaviour will static checks 
    // std::cout << student_grades[Georg] << std::endl; //~ undefined behaviour

    // std::cout << std::get<Georg>(student_grades) << std::endl; //~ catches the undefined behaviour and throws error
    
    // static_assert(Max_Students == std::ssize(student_grades)); //~ catches the undefined behaviour and throws error

    //? it is not possible to use a foreach loop over the enumeration members of an enumeration
    //for(const auto& element : Colors::Type){
    //    std::cout << element << std::endl; 
    //}

    //? but we can use range based loops over enumerations
    //? therefore if we pack the enumeration members themselve into an array we can iterate over those array elements
    constexpr std::array colors{Colors::red,Colors::blue,Colors::green};
    for(const auto& element : colors){
        std::cout << getColor(element) << std::endl;
    }

    return 0;
}