#include <iostream>
#include <iomanip>

void print_1to5_with_padding(char padding_character);

int main(){

    int i{5};
    //* printing numbers in reverse order
    while ( i >0 ){
        int j{i};
        while ( j > 0){
            std::cout << j << " ";
            --j;
        }
        std::cout << std::endl;
        --i;
    }

    print_1to5_with_padding(' ');
    print_1to5_with_padding('X');
    print_1to5_with_padding('-');
    print_1to5_with_padding('_');


    return 0;
}

void print_1to5_with_padding(char padding_character){
    int i=1;
    //? printing to stdout right justified with std::right 
    std::cout << std::right;
    while ( i <=5 ){
        int j{1};
        //? sets the width of the printed statement, has to be reset for every output
        //* imported from the iomanip library
        std::cout << std::setw(10);
        if ( padding_character == 'X' || padding_character == '-' || padding_character == '_'){
            std::cout << std::setfill(padding_character);
        }
        std::string print{""};
        while ( j <= i){
            //? we can convert an integer to a string with the to_string function from the std library
            //* it is not possible to static cast an int to string
            print += std::to_string(j) + " ";
            ++j;
        }
        std::cout << print << '\n';
        ++i;
    }
    //? flushes the output at the end
    std::cout << std::flush; 
}