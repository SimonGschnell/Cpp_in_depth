#include <iostream>
#include <iterator>
#include <vector>

//? iterators are objects designed to traverse through containers without worrying how the data in the container is stored

//~ C++ iterators typically use operator++ to move to the next element and operator* to access the current element
//* the same as performing pointer arithmetic on a pointer and accessing the value of a pointer
//? in fact the simplest form of an iterator are pointers which only work for data stored sequentially in memory


int main() {

    //? the standard library offer iterator methods to iterate over containers
    const std::vector arr{3,2,8,1,2};
    //~ accessing the iterator methods of std::vector with .begin() and .end()
    auto begin = arr.begin();
    auto end = arr.end();

    //? operator++ used to move the iterator to the next element
    //! the operator!= is preferred over the operator< because more containers have an implementation for the operator
    for(;begin!= end; ++begin) {
        //? operator* used to access the value of the current iterator element
        std::cout << *begin << std::endl;
    }

    constexpr int arr2[]{3,6,6,7};
  
    //? for C-like arrays we have to use the std::begin() and std::end() functions inside the <iterator> library
    auto C_like_begin {std::begin(arr2)};
    auto C_like_end {std::end(arr2)};

    //~ also here using operator++ to move to the next element and operator* to access the elements value
    for(; C_like_begin!=C_like_end; ++C_like_begin){
        std::cout << *C_like_begin << std::endl;
    }

    //? ranged based for loops only work with types that have .begin() and .end() or ca be used with std::begin() and std::end()
    for(const auto& element : arr2){
        std::cout << "range-based-for-loop: " << element << std::endl;
    }

    //! iterator invalidation: when the memory space of the container changes while iterating over the container elements
    std::vector vec{0,1,2,3};
    for(auto ele : vec){
        if((ele %2)==0){
            //! push_back is method of the std::vector class that is able to invalidate an interator
            //* because push_back will do a memory reallocation if the capacity of the current container is too small to fit new elements
            //~ this leaves the iterator dangling once the memory of the container was reallocated
            vec.push_back(ele+1);
            
        }
        std::cout << "dangling iterator: " << ele << std::endl;
    }

    return 0;
}