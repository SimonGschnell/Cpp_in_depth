#include <iostream>
#include <string>
#include <string_view>

//? if the amount of objects cannot be known at compile time we have to dynamically allocate memory for new objects
//* instead of using static or automatic variables, we need to use dynamic variables

int main(){

//? using the keyword "new" requests memory from the os for the creation of an object and returns a pointer to it 
//* the following line requests an int amount (4bytes) of memory and returns a pointer to it that has not been used in this example
new int;

//* saves the returned pointer into a dynamic variable called ptr, now we can reuse the memory that has been allocated through the "new" keyword
int* ptr{new int};

//! while stack allocated objects are faster to use because the compiler already knows their address
//! while for heap allocated objects the address of the pointer has to read and then the address can be accessed
//? now we can dereference the pointer to assign a value to it
*ptr = 7;
std::cout << *ptr << std::endl;

//? dynamically requested address can also be directly assigned
int* ptr2 {new int {5}};
int* ptr3 {ptr2}; //? we can also let a pointer point to another pointer address
std::cout << *ptr2 << std::endl;

//? when the requested memory (pointer) is not needed any longer, we have to dispose the memory to avoid memory leaks
//* this is done using the "delete" keyword
//! the "delete" keyword only releases the reserved memory back to the os, the lvalue pointer is still usable afterwards and therefor we set its value to a nullptr
delete ptr2;
//! also ptr3 is now a dangling pointer because it was pointing to the address of ptr2, which was deleted 

//? ptr2 is currently a dangling pointer after its memory has been deallocated

//~ once memory was deallocated (returned to the os) there are no more guarantees what happens to the content of that memory
//* A pointer pointing to deallocated memory is called a dangling pointer, dereferencing or deleting a dangling pointer causes undefined behavior
// std::cout << *ptr2; //! undefined behavior, dereferencing a dangling pointer
// delete ptr2; //! undefined behavior, deleting a dangling pointer 
//~ Best Practice: Set deleted pointers to nullptr unless they are going out of scope immediately afterward
ptr2 = nullptr; 

//! if requesting memory with the new keyword fails because the os ran out of memory an exception is thrown and the program ends abruptly if the exception is not handled
//* we can use the std::nothrow constant between the new keyword and the object type, this will return a nullptr if the new keyword fails instead of throwing an excepiton
int* value { new (std::nothrow) int{55} };

//? null pointers are useful when dynamically allocating memory because they tell us if a pointer is pointing to memory or not
//* we can conditionally allocate memory with null pointers
if (!ptr2){ // checks if it is a null pointer
    ptr2 = new int; // allocates new memory for the pointer in case it is a null pointer
}

//? deleting a null pointer has no effect and therefore we dont have to check whether the pointer is not pointing to a null pointer
delete ptr2;
ptr2 = nullptr;
delete ptr2; // has no effect


//! dynamically allocated memory stays allocated until it is explicitly deallocated or the program ends and the operating system cleans the memory up
//* pointers follow normal scoping rules for local variables, which can create different scoping problems where allocated memory does not get deallocated
{   // start of a block scope
    int* scoped_ptr {new int{1}}; //~ dynamic allocation of memory
}   // scoped_ptr lvalue goes out of scope here and cannot be deleted anymore //! this is called memory leak

//? there are different ways how memory can leak
//* a pointer holding the address of dynamic allocated memory can be assigned a new value without deleting the old dynamic memory
int test {55};
int* test_ptr { new int }; // allocates dynamic memory
//~ this can be fixed by deleting the dynamic memory before reassinging a new address to the pointer
//! delete test_ptr; 
test_ptr = &test; // assignes the address of lvalue test without deleting the old requested dynamic memory

//* memory leak can also occur via double allocation
int* value_ptr { new int {}};
//~ also this can be fixed by deleting the old dynamic memory before assigning new dynamic memory
//! delete value_ptr;
value_ptr = new int{}; // new dynamic memory was requested and assigned without deleting the old dynamic memory

}