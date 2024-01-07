#include <iostream>

//! when arrays have to be resized, use std::vector instead

int main(){

    //? instead of dynamically allocating a single variable, we can also dynamically allocate arrays of variables
    //~ dynamically allocating an array allows us to choose the size at runtime/ does not require a constexpr length and does not need to be a fixed sized array
    //* the array form of new and delete is used (new[] and delete[])

    std::cout << "Enter the size of the dynamically allocated array: ";
    std::size_t size {};
    std::cin >> size;

    //? here we dynamically allocate an array using new int[] and we value initialize it with {}
    //! the length of dynamically allocated arrays has type size_t like most container types in the standard library
    //? because we are dynamically allocating the array we have much more memory that we can use, compared to an array created on the stack
    //! dynamically allocated arrays start their life as a pointer, which means just like decayed fixed array they don't know their length
    int* array { new int[size]{} };

    //* Starting with C++11 its possible to initialize dynamically allocated arrays with initialization lists
    // the lenth of the dynamically allocated arrays can be omitted when value initialization is used
    int* value_initialized_array { new int[]{1,2,3,4} };

    std::cout << "An array of size " << size << " has been dynamically allocated."  << std::endl;
    array[0] = 5;
    std::cout << array[0] << " has been added to the created array" << std::endl;

    //? if we want to deallocate the dynamically allocated array, we use delete[]
    //! using the normal delete for dynamically allocated arrays, will result in undefined behavior/ memory leak or crashes
    //* the delete[] keyword knows how much memory to delete because the new[] keyword keeps track of how much memory was reserved, this length information is not visible to the programmer
    delete[] array;
    //* we don't have to set the array to a null pointer because it goes out of scope immediately after, but it is best practice to always do so
    array = nullptr;

    return 0;
}