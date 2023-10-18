#include <iostream>

//? unnamed namespaces (anonymous namespace) are defined without a name
//* content inside unnamed namespaces are treated as part of the parent namespace (global namespace in this case)
//! all identifiers inside an unnamed namespace are automatically internally linked
//! this is the only way to make program-defined types internally linked
namespace {

    // would be external linked but unnamed namespace makes it internal linked
    void do_something(){
        std::cout << "something" << std::endl;
    }

    float g_pi{3.14f};
}

//? inline namspaces are used for version control
//* let's say we want to change the function times_three without breaking other code that uses this function
//? inline namespaces identifiers are also treated as part of the parent namespace but don't modify the linkage
inline namespace V1{
    
    int times_three(int x){
        std::cout << "V1" << std::endl;
        return x + x + x;
    }
}

namespace V2 {
    
    int times_three(int x){
        std::cout << "V2" << std::endl;
        return x *3;
    }
}

//? you can also nest a unnamed namespace inside a inline namespace
inline namespace Inside{
    namespace {
        std::string g_inside {"inside"};
    }
}

int main(){


    do_something(); //? unnamed namespace identifiers can be called without a namespace prefix

    //* all versions of times_three are externally linked
    std::cout << V1::times_three(5) << std::endl;
    std::cout << V2::times_three(5) << std::endl;
    std::cout << "without namespace prefix: \n" << times_three(5) << std::endl;
    
    std::cout << g_inside << std::endl;

    return 0;
}