#include <iostream>
#include <vector>
#include <ranges>

//! it is not possible to get the index of an element inside a range based loop
//* because it also can loop over containters that do not operate with indexes
//? however it is easy to keep track of a user-defined index by incrementing a counter variable each iteration

int main(){

    std::vector<int> array{1,2,3,4} ;
    
    //? usage of a range based loop
    for(int element : array){
        std::cout << element << std::endl;
    }

    //? range based loops are often used with the auto keyword to deduce the type of the array elements 
    for(auto element : array){
        std::cout << element << std::endl;
    }

    //! to avoid expensive copies when iterating over an array with the range based loop
    //* we use const references
    for(const auto& element: array){
        std::cout << element << std::endl;
    }

    //? it was hard to use a range based loop to iterate a container in reverse order
    //* C++20 added std::views::reverse() in the <ranges> library that can be used for that purpose
    /* 
    for(const auto& element : std::views::reverse(array)){
        std::cout << element << std::endl;
    } */


    return 0;
}