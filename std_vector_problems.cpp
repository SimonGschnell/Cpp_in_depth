#include <iostream>
#include <vector>
#include <iterator>
//! container types and their subscription operator were implemented using unsigned integers


int main(){
    //? size_type is a nested typedef used as the type for the length of a container class
    //* most of the times size_type is an alias for std::size_t
    std::cout << sizeof(std::vector<int>::size_type) << std::endl;

    int signed_int {5};
    constexpr int signed_int_constexpr {5};

    //! produces error or warning because narrowing conversion is used to convert a signed int into a unsigned int
    unsigned int unsigned_int{signed_int}; 
    //? however if we are using a constexpr value, a conversion is safe because the compiler can guarantee it or halt the compilation
    unsigned int unsigned_int2{signed_int_constexpr}; 

    //? .size() can be used to get the length of a container 
    std::vector<int> my_vector(5);
    //* the length returned from .size() has the type unsigned T::size_type (T stands for the used container)
    std::cout << "size of the definition: std::vector<int> vec1(5) --> " << my_vector.size() << std::endl;
    
    //? when working with c-like arrays there is global function defined in <vector> or <iterator> called std::size(), which will also return the size of non-decayed C-arrays
    //* non-decayed means that the array was not converted into a pointer
    int Carray[3] ={1,2,3};
    std::cout << std::size(Carray) << std::endl; //! only available in C++17 and above

    //? if we want to store the now returned size value of a container in a signed integer we get a compiler warning or error
    //* because size_type (alias for size_t) was implemented as a unsigned int and those narrowing conversion happens
    int size_of_a_vector {my_vector.size()};
    //? this can be avoided by explicitly casting the returned unsigned size to signed int
    int sizeOfVec {static_cast<int>(my_vector.size())};

    //? since C++20 std::ssize() was introduced, another global function that will return the size of a collection as a signed integer
    // int signed_sizeOfVec {std::ssize(my_vector)};

    for(int& ele : my_vector){
        static int index{0};
        ele = ++index;
    }
    //! the subscription operator [] does not do bound checking
    std::cout << my_vector[my_vector.size()-1] << std::endl;
    //? we can do bound checking using the .at() member function, bounds are checked at runtime (exception occurs)
    //! .at() is slower than the subscription operator and therefore less used because the index can be verified before usage as index
    try{
        std::cout << my_vector.at(6) << std::endl;
    }catch(std::out_of_range& e){
        std::cout << e.what() << std::endl;
    }

    //? to conclude the topic, the subscription operator expects an size_type argument
    //* and when passing a signed integer - a narrowing conversion is made
    int index {2};
    my_vector[index]; //? narrow conversion from signed int to unsigned size_type
    std::size_t index2{2}; //! storing unsigned data can be dangerous
    my_vector[index2]; //? no conversion is done 

    return 0;
}