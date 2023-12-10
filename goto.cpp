#include <iostream>

//! goto statements should be avoided because of the logical complexity they can create
//* goto statements can be easily be replaced with continue or break statements

int main(){

    double input {};

loopLabel: // this is a statement label

    std::cout << "Please enter a positive number:";
    std::cin >> input;
    if(input < 0.0) goto loopLabel; // this is unconditional jump
    

    std::cout << "The entered number is: " << input << std::endl;
}