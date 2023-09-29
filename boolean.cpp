#include <iostream>

int main(){

    bool t{true};
    bool f{}; // defalut list initialization value for boolean is false

    //? booleans are printed as numbers , 0 -> false, 1 -> true
    std::cout << t << '\n' << f << std::endl;

    std::cout << std::boolalpha; // boolean are printed as text
    std::cout << true << '\n' << false << std::endl;
    std::cout << std::noboolalpha; // deactivation of the sticky output manipulator

    bool untipical=4; //! copy initialization allows implicit type conversion from int to bool
    std::cout << untipical << std::endl;// any number that is not 0 will be treated as true


    //? reading booleans from input
    bool input{};

    std::cout << "please enter a boolean value:";
    //! cin only allows 0 or 1 as value for boolean otherwise it will silently fail
    #if 1
    //? also allows "true" or "false" as value for boolean
    //* boolalpha is a input manipulator in this case
    //* can be used to read true or false or to ouput true or false
    std::cin >> std::boolalpha; 
    #endif
    std::cin >> input;
    // 0 or 1 will be printed because boolalpha was disabled for the output
    std::cout << "you entered " << input << std::endl;

    

    return 0;
}