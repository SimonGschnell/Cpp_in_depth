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

}