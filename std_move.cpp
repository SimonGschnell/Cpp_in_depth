#include <iostream>
#include <utility>
#include <string>
#include <vector>

//? C++11 introduced std::move inside the <utility> library that casts its argument into an r-value reference
//* this is useful to use move semantics on l-values

//? there is a move function variant, called std::move_if_noexcept(), which only creates a r-value reference out of an l-value if the value has a noexcept move constructor
//? otherwise it returns a copyable l-value

template <typename T>
//? this function makes multiple copies that would not be necesary to just swap 2 values
void custom_swap_function(T& a, T& b) {
    T tmp {a}; //* invokes copy constructor because a is an l-value
    a=b; //* invokes copy assignment because b is an l-value
    b=tmp; //* invokes copy assignment because tmp is an l-value
}

template <typename T>
//~ we can use std::move to convert the l-values to r-value references, which prioritizes the move semantics
void custom_move_swap_function(T& a, T& b){
    T tmp {std::move(a)}; //* move constructor
    a = std::move(b); //* move assignment
    b = std::move(tmp); //* move assignment
}

int main(){

    std::string a {"hello"};
    std::string b {"world"};
    std::cout << a << b << std::endl;
    custom_swap_function(a,b);
    std::cout << a << b << std::endl;

    //? we can also use move semantics when filling containers
    //~ std::vector supports move semantics
    //? std::move can also be useful when sorting an array, many algorithms have to swap elements which could lead to copies that can be replaced with moves
    std::vector<std::string> container{};
    std::string element {"Text"};
    container.push_back(element); //? uses the copy semantics of vector because element is an l-value 
    std::cout << "element: " << element << std::endl; //* element added to the container is left unchanged because it was copied
    std::cout << "container: " << container[0] << std::endl;
    container.push_back(std::move(element)); //? uses the move semantics of vector because element was converted to an r-value reference with std::move
    std::cout << "element: " << element << std::endl; // element is now empty because it's value was transferred //! but it could have been in any unspecified but valid state
    std::cout << "container: " << container[0] << " " << container[1] << std::endl;
    
    //? in which state should l-values, that were transformed into r-value references with std::move, be left behind? 
    //* - objects that have been moved from should be reset back to defalut or zero state
    //* - do whats most convenient, not constraint to clearing the moved-from object
    //~ C++ puts moved-from objects in a valid but unspecified state
    //! therefore it should be avoided to use values of moved-from objects
    //? it is safe to set or reset the value of a moved-from object after it has been moved


    return 0;
}