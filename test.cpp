#include <iostream>
#include <vector>

//? what differentiates std::vector from other container classes is that it can resize itself after it has been instantiated

//* std::array and C-style arrays are both fixed-size arrays where 
//* the length of the array must be known at the point of instantiation and cannot be changed after
//! fixed-sized arrays can be constexpr and can be static_asserted on, because of that trait

//* std::vector is a dynamic array (resizeable array) whose size can be changed after instantiation

int main(){
    
    std::vector<int> array{1,2,3};
    std::cout << "array size :" << array.size() << std::endl;
    std::cout << "the capacity of the array: " << array.capacity() << std::endl;

    //? vector can be resized with the resize function 
    //! resizing requires reallocation which is typically expensive
    array.resize(5);
    std::cout << "array size :" << array.size() << std::endl;

    //? std::vector can also return the capacity of the container
    //* which is how many elements have been allocated in memory (whereas length is how many elements are in active use)
    //! the following line prints 6 because the size was doubled from 3 to 6 in memory 
    //! but only 5 are in active use because we called array.resize(5)
    std::cout << "the capacity of the array: " << array.capacity() << std::endl;
    //? the subscript operator and the .at function will operate on the length of the array and not the capacity
    //! which means index 5 which would be in the range of the containers capacity is considered as out of bounds
    //std::cout << array.at(5) << std::endl; //! throws out_of_range error

    //* prints all elements
    for(const auto& element : array){
        std::cout << element << std::endl;
    }

    array.resize(2);
    std::cout << "size of array: " << array.size() << " capacity of array: " << array.capacity() << std::endl;
    //? when shrinking a vector, the capacity will remain the same to avoid expensive reallocation
    //! however if we also want to shrink the capacity explicitly, we have to call the member function shrink_to_fit()
    array.shrink_to_fit();
    std::cout << "AFTER calling shrink_to_fit - size of array: " << array.size() << " capacity of array: " << array.capacity() << std::endl;
    

    //* procedure of resizing
    // - The std::vector acquires new memory with capacity for the desired number of elements. These elements are value-initialized.
    // - The elements in the old memory are copied (or moved, if possible) into the new memory. The old memory is then returned to the system.
    // - The capacity and length of the std::vector are set to the new values.

    return 0;
}