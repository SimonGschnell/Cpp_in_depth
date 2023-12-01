#include <iostream>

//? in the most cases when a C-style array is used in an expression, the array is implicitly converted into a pointer to the element type
//* initialized with the address of the first element
//~ this is called array decay (or decay)
//! when an array decays it looses its length information, it turns from int[N] to int*

void pass_any_length_array(const int arr[]){ 
    std::cout << "size of decayed array, will be size of int* : " << sizeof(arr) << std::endl;
    std::cout << "does passed array have type int* : " << (typeid(arr) == typeid(const int*)) << std::endl;
}

int main(){

    int arr[3] {3,6,9};
    int long_arr[33] {1,2,3,4,5,6,7,8};
    auto deduced {arr}; // evaluation causes arr to decay into int*
    //? arr is of type int[]
    std::cout << std::boolalpha;
    std::cout << (typeid(arr) == typeid(int*)) << std::endl; //* prints false
    //? deduced got decayed into int*
    std::cout << (typeid(deduced) == typeid(int*)) << std::endl; //* prints true
    //? const C-style arrays will be decayed into (const int*)
    const int const_arr[55]{1,2,3};
    auto deduced_const_arr {const_arr};
    std::cout << (typeid(deduced_const_arr) == typeid(const int*)) << std::endl; //* prints
    
    //! an C-style array only doesn't decay in rare cases:
    //* argument to sizeof() , typeid()
    //* when taking the address of the array with &
    //* when passed as a member of a class type
    //* when passed by reference

    //? because arrays decay to a pointer when evaluated, the subscript operator[] is actually performed on the decayed array
    //* therefore the next two lines are eqivalent
    std::cout << arr[0] << std::endl;
    int* ptr {arr}; // decaying arr, same as passing &(arr[0]), address of the first element in the array
    std::cout << ptr[0] << std::endl;

    //? C-sytle arrays that are passed as arguments to a function get decayed to avoid expensive copies
    //? these are pass by addresses and any modification on the address will modify the original object
    //* to avoid modification on the original object, the parameter is defined as const
    pass_any_length_array(arr);
    pass_any_length_array(long_arr);

}