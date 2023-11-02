#include <iostream>

//? scoped enumerations have 2 distinct differences from unscoped enumerations
//* their types do not be implicitly convert to numeric values
//* the types of the enumeration does not polute the outter scope

//? definition of a scoped enumeration
//* usage of the "class" keyword
enum class Color{
    red,
    green,
    blue,
    purple,
};

//? scoped enumerations act like a namespace for their enumerators
enum class Fruit {
    banana,
    apple, 
    orange,
};


int main(){

    Color rgb1 {Color::red}; //? types are now only usable through a qualified name
    Color rgb2 {Color::red};
    Fruit veggi {Fruit::banana};

    //if(rgb == veggi){  this would be evaluated to TRUE with unscoped enumeration types because they implicitly convert to their numeric value
    //? but scoped enumeration types don't implicitly convert to their numeric value
    //* it would be possible to convert scoped enumeration types explicitly with static_cast

    if(rgb1 == rgb2){ //* scoped enumeration types can be compared with their own type because no conversion is needed
        std::cout << "the same color" << std::endl;
    }

    
    

    return 0;
}