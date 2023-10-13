#include <iostream>
#include <string>

//! don't allow shadowing for the compiler with the options:
//* -Wshadow OR -Wshadow=global OR -Wshadow=local
//? also -Wshadow=compatible-local which restricts shadowing if the shadowed variable has a compatible type

std::string scope_var{"global scope"};
int number{5};

int main(){

    std::string scope_var{"main scope"};
    
    {
        std::string scope_var{"inner scope"};
        int number{1};
        //? Variable shadowing occurs
        //* the identifier scope_var exists in the outer scope and also in the inner scope
        //! in this case the outer scope variable is hidden behind the inner scope variable and prints the inner scope variable
        std::cout << scope_var << std::endl;
        
        //? there is no possibility to access the outer scope main variable but we can access the global scope variable with the scope resolution operator 
        std::cout << ::scope_var << std::endl;

        // increment and print local number
        std::cout << ++number << std::endl;
        // increment and print global number
        std::cout << ++(::number) << std::endl;

    }


    return 0;
}