// we use double quotes "" for libraries that are located in the root folder 
//? preprocessor adds all forward declarations of add.h into main.cpp 
//! transitive includes happen when a header file includes another header file, both contents will be available in main.cpp
//* generally include all depending header files directly 
#include "add.h"
#include <iostream>

int main(){
    std::cout << " 3+6 = " << add(3,6) << '\n';
    return 0;
}