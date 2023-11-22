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
    for(auto i =vec.size(); i >= 0 ; i--){
        //* undefined behavior when "i" decrements at 0
        //std::cout << vec[i] << std::endl; //! prints crazy stuff
    }
    
}


int main(){

    std::vector<int> grades {6,9,7,8,7,4};
    vector_average(grades);
    print_vector_reverse(grades);
    

    return 0;
}