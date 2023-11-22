#include <iostream>
#include <vector>

//? we can combine template functions, arrays and loops for efficient data handling
template <typename T> 
void vector_average(const std::vector<T>& vec){
    double average{};
    for(int i =0; i < vec.size() ; i++){
        average += vec.at(i);
    }
    average /= static_cast<int>(vec.size());

    std::cout << "average grade: " << average << std::endl;
}

//! but because std::vector::size_type is defined as unsigned int the following could occur
template <typename T> 
void print_vector_reverse(const std::vector<T>& vec){
    double average{};
    //! index "i" was type deduced using the type from the .size() function which is unsigned
    //! therefore when "i" arrives to 0 it will wrap around, causing unsigned int overflow
    for(auto i =(vec.size()-1); i >= 0 ; i--){
        //! endless loop
        //* undefined behavior when "i" decrements at 0
        //std::cout << vec[i] << std::endl; //! prints crazy stuff
    }
    
}

template <typename T>
void printArray(const std::vector<T>& arr)
{
	//? the index type should use the same type as the std::vector<T>::size_type
    //* as long no custom allocator is used for the vector std::size_t can be used directly because size_type is default a alias for size_t
	for (std::size_t index { 0 }; index < arr.size(); ++index)
		std::cout << arr[index] << ' ';
    
    std::cout << "\n";

    //? when working with not to long arrays it is fine to convert the unsigned index to int
    //* for longer arrays, std::ptrdiff_t is used, which is the signed counterpart of std::size_t
    for (int index { 0 }; index < arr.size(); ++index)
		std::cout << arr[index] << ' ';

    std::cout << "\n";

    //? its common to create an alias for std::ptrdiff_t for better readability
    using Index = std::ptrdiff_t;
    for (Index index{ 0 }; index < static_cast<Index>(arr.size()); ++index)
        std::cout << arr[index] << ' ';

    std::cout << "\n";

    //? C++20 way, is to use std::ssize which returns the size of the array as a signed integer
    for (auto i{std::ssize(arr)}; i >= 0; i--)
        std::cout << arr[i] << ' ';

    std::cout << std::endl;
    
}


int main(){

    std::vector<int> grades {6,9,7,8,7,4};
    vector_average(grades);
    //print_vector_reverse(grades);
    printArray(grades);

    return 0;
}