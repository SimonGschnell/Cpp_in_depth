#include <iostream>

int main(){

    //? pointer arithmetic allows us to use arithmetic operators to produce new memory addresses 
    //* given some pointer "ptr", ptr + 1 returns the address of the next object in memory
    //* if ptr is an int* and int is 4 bytes, ptr + 1 returns the address that is 4 bytes after ptr
    //* and ptr + 2 returns the address that is 8 bytes after ptr

    int x{1};
    int* int_ptr {&x};
    std::cout << "addition of memory\n" <<
    "memory address: " << int_ptr   << " - value: " << *int_ptr     << "\n" << 
    "memory address: " << int_ptr+1 << " - value: " << *(int_ptr+1) << "\n" << 
    "memory address: " << int_ptr+2 << " - value: " << *(int_ptr+2) << std::endl;
    
    //? pointer arithmetic also works when subtracting from a memory address
    std::cout << "subtraction of memory\n" <<
    "memory address: " << int_ptr   << " - value: " << *int_ptr     << "\n" << 
    "memory address: " << int_ptr-1 << " - value: " << *(int_ptr-1) << std::endl;
    
    //? ++ and -- will move the pointer and assign the pointer the new address
    //* because ++ptr = ptr = ptr + 1
    int* ptr {&x};
    std::cout << "++ptr:\n"
    << ptr << " - ";
    ++ptr;
    std::cout << ptr << std::endl;

    //? the subscript operator is implemented using pointer arithmetic
    //* subscripting the index 2 is the same as moving forward 2 memory address sizes of type T that is used as element type
    //~ the subscript operator evaluates arr[2] as *(arr+2)
    int arr[] {2,4,6};
    for(int i{0}; i < std::size(arr) ; i++){
        std::cout << arr[i] << std::endl;
        std::cout << *(arr+i) << std::endl;
    }
    //! this is the primary reason arrays are 0 based. because the compiler doesn't have to subract 1 whenever subscripting
    
    
    return 0;
}