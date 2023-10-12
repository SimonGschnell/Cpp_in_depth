#include <iostream>
#include "add_with_namespace.h"

int doSomething(int x, int y){
    return x + y;
}

//? user defined namespaces
//* program defined types start with capital letters
namespace CustomSpace {
    int doSomething(int x, int y){
        return x + y;
    }

    int globalDoSomething(int x, int y){
        //* calls the doSomething from the global namespace and not the CustomSpace namespace
        // because it is preceded with ::
        return ::doSomething(x,y);
    }
}    

//! now two functions don't cause a naming collision because they are separated by namespaces
namespace DifferentSpace {
    int doSomething(int x, int y){
        return x - y;
    }
}  

//? we can split identifiers of a namespace over multiple files 
//* when we include a std library we only include part of the std identifiers 
// here we expand the Add_Namespace identifiers
namespace Add_Namespace {
    constexpr std::string_view namespace_name {"Add_Namespace"};
}

//? we can also nest namespaces
namespace Level1 {
    namespace Level2 {
        int level {2};
    }
}

//? we can decide which version we want to use in the main function with:
//* the scope resolution operator
//* using statements

int main(){ 

    //* telling the compiler to use the doSomething function from the DifferentSpace namespace with the scope resolution operator 
    std::cout << DifferentSpace::doSomething(3,4) << std::endl;
    
    //? the scope resolution operator without providing a namespace defaults to the global scope
    //* here ::doSomething() is the same as doSomething()
    std::cout << ::doSomething(3,3)  << std::endl;

    //? using namespace identifiers from foreward declarations in header files
    std::cout << Add_Namespace::add(10,9) << std::endl;
    //? splitted namespace identifiers from multiple files
    std::cout << Add_Namespace::namespace_name << std::endl;

    //? we can access nested namespaces by declaring the whole path
    std::cout << Level1::Level2::level << std::endl;
    //? or we can create a namespace alias
    namespace LevelAlias = Level1::Level2;
    //* with the alias we can omit the whole nested namespace path
    std::cout << LevelAlias::level << std::endl;

    return 0;
}