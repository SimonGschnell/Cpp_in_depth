#include <iostream>
#include <string>
#include <functional>

//? functions have their own lvalue function type
//* just like variables, functions live at an assigned address in memory
//! when a function is called with () execution jumps to that address in memory

//~ function pointers are mainly used for passing functions to other functions
//~ these type of functions are called callback functions 

int foo();
int goo();
double double_foo();
double mixed_fn(int a, std::string b);


//~ function used as callback function
int add(int a, int b){
    return a+b;
}
int subtract(int a, int b){
    return a-b;
}

//? example of a function taking another function as a parameter
//* we can also give the function parameter a default function to call
void execute_operation_on_ints(int a, int b, int(*f_p)(int, int)=add){
    std::cout << f_p(a, b) << std::endl;

}



int main(){

    //? definition of a function pointer:
    //* this is a function pointer that points to a function that takes no parameters and returns an integer
    //~ the parentheses around fnc_ptr are neccessary for precedence reasons
    int (*fnc_ptr)(); 
    //? function pointers can also be constant, therefore have to be initalized at definition
    int (*const fnc_ptr_const)(){&foo}; 

    
    
    //? we get the address of a function like we get addresses of variables with the & symbol
    int (*fnc_foo)(){&foo};
    //? the & symbol can also be omitted because function types are implicitly converted to function pointers, (the same is not true for fundamental types)
    int (*fnc_foo2)(){foo}; 

    //? the function pointer has to match with the return type and parameters of the function it is pointing to
    //fnc_foo= &double_foo; //! double (*)() cannot be assigned to int (*)()
    //? an example of a function pointer that returns double and has two parameters of type int and std::string
    double (* mixed)(int, std::string){&mixed_fn};

    //~ there are two ways to use the function pointers
    //* explicit dereferencing the function pointer
    std::cout << (*mixed)(1,"test") << std::endl;
    //* implicit dereferencing the function pointer
    std::cout << fnc_foo() << std::endl;

    //! default parameters do not work for function pointers because function pointers are executed at runtime 
    //? while default function parameters are substituted at compile time

    //? it is possible changing to which function the function pointer is pointing to
    fnc_foo=&goo;

    //! which is not true for const function pointers
    // fnc_ptr_const=&goo; //! error: must be modifiable lvalue
    std::cout << fnc_foo() << std::endl;


    //? how to use functions that take other functions as arguments
    execute_operation_on_ints(3,4,&add);
    execute_operation_on_ints(3,4,&subtract);
    //* using the default value of the third fucntion parameter
    execute_operation_on_ints(3,4);

    return 0;
}

int foo(){
    return 5;
}

int goo(){
    return 10;
}

double double_foo(){
    return 1.1;
}

double mixed_fn(int a, std::string b){
    std::cout << b << std::endl;
    return a;
}
