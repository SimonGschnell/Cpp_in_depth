#include <iostream>
#include <string>
#include <string_view>
#include <cassert>


struct Person{
    int age{};
    std::string name{};
};

enum class Type{
    Type_Int,
    Type_Float,
    Type_Person,
};

void print_pointer(void* pointer, Type type){

    switch(type){
        case Type::Type_Int: std::cout << *static_cast<int*>(pointer) << std::endl; 
        break;
        case Type::Type_Float: std::cout << *static_cast<float*>(pointer) << std::endl;
        break;
        case Type::Type_Person: std::cout << static_cast<Person*>(pointer)->age << static_cast<Person*>(pointer)->name  << std::endl;
        break;
        default: std::cerr << "Unknown type, not able to print pointer"; break;
    }
}

int main(){

    int nValue{5};
    float fValue{5.5};
    Person p{ 11, "simon"};

    //? special pointer, that can be pointed at objects of any type
    void* voidptr {};
    //* all of the following assignments are valid for the void pointer
    voidptr = &p;
    voidptr = &nValue;
    voidptr = &fValue;
    

    //! The void pointer doesn't know what type it is pointing to, it is illegal to dereference a void pointer to access the underlying value
    // std::cout << *voidptr << std::endl; //! illegal
    //* however if we static cast the void pointer to the correct type of pointer, we are again allowed to use it like a normal pointer
    //? it is the task of the programmer to keep track of which type the void pointer is pointing to
    std::cout << *static_cast<float*>(voidptr) << std::endl;


    int* intptr {&nValue};
    float* floatptr {&fValue};
    Person* personptr {&p};
    //? using a function that can print pointer of different types
    print_pointer(intptr, Type::Type_Int);
    print_pointer(floatptr, Type::Type_Float);
    print_pointer(personptr, Type::Type_Person);

    //! deleting a void pointer results in undefined behavior because the type is not known
    //* the pointer has to be casted to the appropriate type first in order to delete it
    //~ the void pointer has to actually point to a dynamically allocated resource in order to be deleted
    int* resource {new int{100}};
    voidptr = resource;
    delete static_cast<int*>(voidptr);

    //! it is not possible to perform pointer aritmethic with void pointers becasue the pointer using pointer arithmetic must know the underlying type 

    return 0;
}