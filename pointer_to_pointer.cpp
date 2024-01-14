#include <iostream>

int main(){

    int value {5};

    //? pointer to an int
    int* ptr{&value};
    //? pointer to another pointer to an int
    int** ptrptr{&ptr};

    std::cout << *ptr << std::endl;
    std::cout << **ptrptr << std::endl;

    // pointers to pointers have a few uses, one of them is an array of pointers
    //? we dynamically allocate an array of pointers, the new keyword then returns the array of pointers as a pointer
    int** array {new int*[5]{}};

    return 0;
}