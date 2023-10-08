#include <iostream>

int main (){

    int n1{1};
    int n2{1};

    //? the comma operator has the lowest precedence and has to be combined with ()
    std::cout << (++n1,++n2) << std::endl;

    //? the comma operator evaluates from left to right and returns the most right expression

    //! the precendence of , is even lower than the assignment operator
    n1 = 0,++n1;

    //? the following prints 1 because, n1 is assigned to 0 and then n1 is incremented in the right expression of the comma operator
    std::cout << n1 << std::endl;

    //? it is common convention to put the condition inside of parentheses, to make sure that the precedence is correct
    (n1 > 0) ? std::cout << "n1 is greater than 0" << std::endl : std::cout << "n1 is not greater than 0" << std::endl;
    //! also the conditional operator has a low precedence and need extra parentheses 
    //? the conditional operator has to return the same type no matter the outcome
    std::cout << ((n1>n2)? n1 : n2) << std::endl;
    return 0;
}