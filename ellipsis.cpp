#include <iostream>
#include <cstdarg> //? needed to use ellipsis


//! ellipsis are very unsafe and produce undefined behavior many times when it is used
//* try to avoid them and replace them with other logic if possible

double findAverage(int count, ...){

    int sum{0};
    //? ellipsis are accessed through a std::va_list
    std::va_list list;
    //? va_list is initialized using va_start
    //* where the first parameter is the va_list and the second parameter is the last non-ellipsis parameter 
    va_start(list, count);

    //* looping through all the ellipsis values
    for(int i{0}; i < count; ++i){
        //? va_arg is used to access elements in the ellipsis
        //* where the first parameter is the va_list and the second parameter is the type of the element we want to access
        sum+= va_arg(list,int);
    }

    //? va_end is used to clean up the ellipsis and va_list
    va_end(list);

    return static_cast<double>(sum)/count;
}

int main (){
    
    std::cout << findAverage(3,1,2,3) << std::endl;
    std::cout << findAverage(6, 5,1,9,8,8,2) << std::endl;
    //! the problem with elipsis are that any argument types and be passed even if they make no sense with how the function is operating
    std::cout << findAverage(2, 'a', 'a') << std::endl;
    //? this errors are not catched and undefined behaviour happens
    std::cout << findAverage(2, "asdg", "asdf") << std::endl;
    //! ellipsis also don't know how many parameters were passed and the amount of parameter has to identified by the logic of the implementer
    //? in our case we know the amount of parameters because the non-ellipsis first parameter we pass to the function is used to keep track of the amount of parameters 
    //~ another way to know how many parameters were passed to an ellipsis is to use a sentinel value
    //* a sentinel value is like the termination value for strings \0



    return 0;
}