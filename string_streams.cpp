#include <sstream>
#include <iostream>
#include <string>

//? One of the primary uses of string streams is to buffer output for display at a later time, or to process input line-by-line

//? multiple string stream classes available:
//* istringstream (derived from istream)
//* ostringstream (derived from ostream)
//* stringstream (derived from iostream)
// wistringstream, wostringstream, wstringstream
int main(){

    //? creating a stringstream for both input and output
    std::stringstream ss;
    
    //? insertion operator to add a string to stringstream
    ss << "1234";
    ss << "asdf";

    //? reading the whole stringstream with .str()
    std::cout << ss.str() << '\n';

    //? initializing the stringstream with member function .str(value)
    //* overrides existing value
    ss.str("hello world");
    
    std::cout << ss.str() << '\n';

    std::string first{};
    std::string second{};
    //? using the extraction operator to extract string from the stringstream until the first whitespace 
    ss >> first;
    std::cout << first << '\n';
    ss >> second;
    std::cout << second << '\n';
    

    //? because the extraction and insertion operator knows how to work with all of the basic data types, we can convert the values of a stringstream directly to a base data type
    //* extraction operator
    std::stringstream sstr;
    sstr.str("1234 99.44");
    int num1{};
    double num2{};
    sstr >> num1 >> num2;
    std::cout << "num1: " << num1 << ", num2: " << num2 << std::endl;

    //* insertion operator
    int n1{104};
    double n2{8.8};
    std::stringstream sstream;
    sstream << n1 << " " << n2;
    std::cout << sstream.str() << std::endl;


    //? we can clear a stringstream by passing a empty string to the .str() member function
    std::stringstream stringStream;
    stringStream.str("hello world");
    stringStream.str(""); // with empty c-like string
    stringStream.str(std::string{}); // with empty string
    //? when clearing a stringstream it is also good to reset any error flags that may have been set
    //* .clear() returns the stream back to the ok state
    stringStream.clear(); 

    return 0;
}