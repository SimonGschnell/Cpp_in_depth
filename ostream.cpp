#include <iostream>
#include <iomanip>

//? The insertion operator (<<) is used to put information into an output stream

int main(){

    //* There are two ways to change the formatting options: flags, and manipulators
    //* To switch a flag on, use the setf() function

    //? turns the showpos flag on, which displays the + sign for positive numbers
    //* we are able to turn multiple flags on with the OR | operator 
    std::cout.setf(std::ios::showpos | std::ios::uppercase);
    
    std::cout << 10 << '\n';
    //? flags can be turned off with the unsetf() function
    std::cout.unsetf(std::ios::showpos);
    std::cout << 1234567.89f << '\n';

    //? A format group is a group of flags that perform similar (sometimes mutually exclusive) formatting options. 
    //* A format group named “basefield” contains the flags “oct”, “dec”, and “hex”, which controls the base of integral values
    //! to override other flags in a format group we have to use another version of setf() that uses two parameters, for the flag and the format group
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n';

    //? Another option is to use manipulators that automatically turn on and off the appropriate flags
    //* using manipulators is much easier than setting and unsetting flags
    std::cout << std::dec << 27 << '\n';
    
    std::cout.setf(std::ios::boolalpha); //? flag for boolalpha (lives in std::ios::boolalpha)
    std::cout << std::boolalpha; //? manipulator for boolalpha (lives in std::boolalpha)

    //? justifing prints in ostream
    //* setw() and width() only affect the next output statement, they are not permanent
    std::cout.fill('*');
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified (sign left, value right)

    return 0;
}