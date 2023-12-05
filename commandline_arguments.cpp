#include <iostream>
#include <vector>
#include <sstream>

//? command line arguments are like parameters for functions but for whole programs

//* main function accepts an integer argc (argument count) that specifies how many command line arguments were passed
//* argv stands for argument vector and contains all command line arguments as C-like strings (char* pointers) in a C-like array (char array)
int main(int argc, char* argv[]){
    
    //! the program name it self is the first command line argument
    //? following command line arguments are separared by spaces
    //* command line arguments passed as strings "hello world" are seen as a single argument

    //? we can iterate through the command line arguments by printing the C-strings inside the argv array
    char** begin{argv};
    for(; begin != (argv+argc); ++begin){
        std::cout << *begin << std::endl;
    }

    //? command line arguments are parsed as C-style strings
    //* converting them to integers can be a little tricky

    //* initializing string stream variable with the first command line argument
    std::stringstream convert{argv[1]};

    int int_var{};
    //? we use the operator>> to store the argument into the int variable
    //* just like std::cin >> int_var
    //~ we add a if condition to check whether the operator>> succeeded
    if(!(convert >> int_var)){
        //* if not we set int_var to 0
        int_var=0;
    }

    std::cout << std::boolalpha << (typeid (int_var) == typeid (int)) << std::endl;




    return 0;
}