#include <iostream>

int generate_ID(){

    //? static lokal variables change their lifetime duration from automatic to static
    //! the variable will only be usable in the function scope and will life till the end of the program
    //* static lokal variables should be prefixed with s_ like g_ for globals
    static unsigned int s_id{0}; // the varaible will only be initialized on the first call
    
    return s_id++; // returns a copy of id and increments id for next call
}

//! static constant variables can be usefull when reading a computation heavy item from the database, that allows to reuse the retrieved item multiple times

int main(){


    std::cout << "id " << generate_ID() << std::endl;
    std::cout << "id " << generate_ID() << std::endl;
    std::cout << "id " << generate_ID() << std::endl;

    return 0;
}