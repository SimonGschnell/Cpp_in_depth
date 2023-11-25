#include <iostream>
#include <vector>

//! std::vector incorporates stack behavior
//? std::vector has many member functions that allow the user to use a vector similat to a stack
//* push_back pushes an element onto the stack
//* pop_back pops an element off the stack
//* back returns the element at the top of the stack

template <typename T>
void print_stack(const std::vector<T>& arr){
    if(arr.empty()){
        std::cout << "Empty stack";
        
    }

    for(const auto& element : arr){
        std::cout << element << " ";
    }
    std::cout << "\tstack pointer: " << arr.size() << " - capacity of the stack: " << arr.capacity() << std::endl;
}

int main(){

    std::vector<int> grades {};
    print_stack(grades);
    //? push back will reallocate and increase the contiguous memory of the vector if the capacity is not enough
    grades.push_back(1);
    print_stack(grades);
    grades.push_back(2);
    print_stack(grades);
    grades.push_back(3);
    print_stack(grades);
    grades.pop_back();
    print_stack(grades);
    grades.push_back(4);
    print_stack(grades);
    grades.push_back(5);
    print_stack(grades);
    grades.push_back(6);
    print_stack(grades);
    //? with the member function back, we can peek at which value the stack pointer is pointing to
    std::cout << "peek: " << grades.back() << std::endl;


    //? using parenthesis initialization will set the capacity and the length (uses resize)
    std::vector<int> numbers (3);
    //* same as
    // std::vector<int> numbers{};
    // numbers.resize(3);
    //* and therefore the stack pointer starts at 3 instead of 0
    numbers.push_back(1);
    print_stack(numbers);


    //! while .resize() will change the length and capacity (if necessary)
    //? .reserve() will only change the capacity and leave the length unchanged (this can be used to avoid many expensive reallocations)
    //* therefore .reverse() can be used to preallocate some memory where we can push elements onto without altering the stack pointer
    std::vector<char> letters{};
    print_stack(letters);
    letters.reserve(6);
    print_stack(letters);
    letters.push_back(97);
    print_stack(letters);
    letters.push_back(98);
    print_stack(letters);
    letters.push_back(99);
    print_stack(letters);
    letters.pop_back();
    print_stack(letters);

    

    return 0;
}