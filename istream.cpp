#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

int main(){

    char buff[5];
    //? we can use manipulators to modify streams 
    //* setw that limits the number of characters to read from a stream
    //* any remainding characters will be left in the stream until the next extraction
    std::cout << "enter some string:" << '\n';
    std::cin >> std::setw(5) >> buff;
    std::cout << buff << '\n';

    //? flushes std::cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max()-1, '\n');

    //? the extraction operator >> skips whitespaces (blanks, tabs, newlines)
    /*
    char c{};
    while(std::cin >> c){
        std::cout << c;
    } */

    /* std::cout << "enter another string:" << '\n';
    std::cin >> std::setw(5) >> buff; */
    //? cin.get member function can be used to get a single character from the stream, including whitespaces
    /* while(std::cin.get(c)){
        std::cout << c;
    } */

    //? std::cin.get also has a string version that takes a max of characters
    //! but the .get functions cannot read newlines and will skip reading entirely if they encounter one
    /*  std::cin.get(buff,5);
    std::cout << buff << '\n'; */

    //? newlines can be read with std::cin.getline() which will extract and discard the newline characters
    std::cout << "enter a string for the .newline function" << '\n';
    std::cin.getline(buff,5);
    std::cout << buff << '\n';

    //? there is another version of getline() that lives outside of the istream class but rather in the <string> library
    //* this version of getline() is used to read a std::string from the input stream
    std::cout << "enter a string for the std::newline function" << '\n';
    std::string text{};
    std::getline(std::cin,text);
    std::cout << text << std::endl;

    //? there are other usefull input stream functions that are available
    //* ignore() discards the first character in the stream.
    //* ignore(int nCount) discards the first nCount characters.
    //* peek() allows you to read a character from the stream without removing it from the stream.
    //* unget() returns the last character read back into the stream so it can be read again by the next call.
    //* putback(char ch) allows you to put a character of your choice back into the stream to be read by the next call.
}