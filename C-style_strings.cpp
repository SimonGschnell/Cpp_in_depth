#include <iostream>
#include <cstring>

//! Avoid C-style string symbolic constants in favor of constexpr std::string_view.


int main(){

    //? C-like strings are built upon C-like arrays
    //* arrays containing multiple chars
    char c_string[] {"peter"};
    std::cout << c_string << std::endl;

    //? because it uses a C-like array, the value cannot be changed upon initialization
    //c_string = "adsf"; //! must be modifiable lvalue

    //? but the single elements of the C-like array can be changed
    c_string[1] = 'a';
    //? when passing c_string to the cout operator>> the c_string will decay to a pointer
    std::cout << c_string << std::endl;

    //? C-like strings and with a terminating \0 symbol which will be printed as an empty space
    //* this terminating symbol is used to remember the length of the string even if the underlying C-like array got decayed
    //~ terminating symbol '\0' is used both for the length and for iterating through the string
    for(char ele : c_string){
        if(ele == '\0'){std::cout << "here" << std::endl;}
        std::cout << ele << std::endl;
    }

    //? getting the length of an C-like string with std::size has caveats
    //* it can only be used on non-decayed C-like strings
    //* and returns the length of the underlying C-like array not the string
    //! the following line prints 6 even though the string has 5 characters (peter) because \0 is also in the underlying C-like array at the end
    std::cout << "length with std::size() of C-like string: " << std::size(c_string) << std::endl; //prints 6

    //? strlen a function inside the <cstring> library returns the length even of decayed C-like strings excluding the terminating symbol \0
    //* however the strlen function is slow because it has to traverse the whole string to know its length
    std::cout << "length with strlen() of C-like string: " << strlen(c_string) << std::endl; // prints 5

    //~ printing C-like strings
    
    int arr[]{1,2,3};
    char name[]{"simon"};
    char* name2 {"simon"};
    //? std::cout is implemented to print the whole string literal when it was passed a char*
    //* decays arr to int* and prints memory address of first element
    std::cout << arr << std::endl;
    //* decays name to char* BUT prints the whole string literal until \0
    std::cout << name << std::endl;
    //* is already a char* and also prints the whole string literal until \0
    std::cout << name2 << std::endl;
    //! What happens when the char* passed to std::cout does not have a terminating symbol \0
    //* depending on the implementation of the compiler it will read until it will find a null symbol somewhere else
    char test{'a'};
    std::cout << &test << '\n';
    //! if you explicitly want to print the address of a char* you have to cast it to a void* pointer
    //* because std::cout will not try to read the contents of a void pointer
    std::cout << static_cast<void*>(&test) << std::endl;


    return 0;
}