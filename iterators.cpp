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
    for(;begin!= end; ++begin) {
        //? operator* used to access the value of the current iterator element
        std::cout << *begin << std::endl;
    }

    return 0;
}