#include <iostream>

int main(){
    int number {7};
    //printing to the console with cout will store the data in a buffer
    //we can concatenate the data with the insertion operator <<
    //when the buffer is full it will be flushed to the output 
    //? std::endl will put a newline at the end of the string and flush the buffer
    //! for performance reason one would not like to flush the buffer at every newline
    //? we can increase performance by simply using \n for a newline
    std::cout << "(flushed by endl (per line)) value of Number is: " << std::endl;
    std::cout << number << std::endl;

    //only flushed at the end of the last line, instead of a flush for each line
    std::cout << "(not flushed by endl) value of Number is: \n";
    std::cout << number << '\n';

    //cin stands for character input and is used to read input from keyboard with the extraction operator >>
    //? The input must be stored in a variable to be used
    int x{}; //direct list initialization with default value 0 
    std::cin >> x;

    std::cout << "You entered " << x << '\n';

    


    return 0;
}