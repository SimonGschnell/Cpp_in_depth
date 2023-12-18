#include "overloading_operator_with_normal_functions.h"
#include <iostream>

//? compiling:
//* g++ -std=c++20 -o main overloading_with_normal_functions.cpp overloading_operator_with_normal_functions.cpp 

int main(){
    Person p1 {"John", 33};
    Person p2 {"simml", 12};
    std::cout << p1 + p2 << std::endl;
}