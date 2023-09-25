#include <iostream>

//! we could also use the directive using to bring the std functions into the global scope but that is
//! discouraged because of naming conflicts
//? both the cout from std and the self defined one would conflict when using the directive using
// using namespace std;
// int cout(){ return 5; }

//introducing the collision function add which is already defined in the add.cpp file
//! when creating a project with add.cpp as a dependency the linker will error out

//? Both add functions from namespaces.cpp and add.cpp are defined in the global namespace and collide
int add(int x, int y){
    return 0;
}

int main(){
    //? C++ moved all of the standard library functions inside the std namespace to avoid collisions
    //? :: is called the scope resolution operator 
    std::cout << add(10,5) << '\n';
    return 0;
}