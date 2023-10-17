#include <iostream>

//? this (and usage inside blocks) is the only exception when using directives are convenient, to import the literal prefixes from the std
using namespace std::literals;

const int foo{5};

void using_declarations(){
    //? using declarations transforms qualified names to unqualified
    //! can make code more readable and is safe and acceptable in functions

    using std::cout;
    //? only std::cout was made unqualified not the rest
    cout << "using declarations" << std::endl;
    cout << "another print with using delclarations" << std::endl;

}


int main (){

    //? difference between qualified and unqualified names
    std::cout; //* identifier cout is qualified by the namespace std
    ::foo; //* foo is qualified by the global namespace

    int abc{};
    abc; //* abc is unqualified because it does not have a scoping qualifier

    using_declarations();

    //? using directives import all identifiers from a namespace into the scope of the using directive
    //! it's best to avoid using directives because of the potential risks it comes with (naming collisions)
    using namespace std;
    cout << "printing with unqualified cout from using directive" << endl;
    

    return 0;
}