#include <iostream>

struct test {
    int test;
    int test2;
};



//copy initialization
int a = 5;
//direct list initialization
int b {5};
//direct list initialization of struct test
test test_o {3,2};





int main(){
    // auto keyword is used to facilitate complex types
    //lambda with only return type (void)
    auto t = []()-> void{
            std::cout << "test"<<std::endl;
        };
    //lambda with capture-list , parameter and return type
    int multiplier = 3;
    auto multiplyBy3= [multiplier](int x)->int{
        return multiplier *x;
    };
    //lambda with just a parameter list
    //the return type is automatically determined
    auto addNumbers = [](int a, int b){
        return a+b;
    };

    t();
    std::cout << "lambda multiplyBy3(5) = " << multiplyBy3(5) << std::endl;
    std::cout << "lambda addNumber(5,6) = " << addNumbers(5,6) << std::endl;
    std::cout << "test_o.test : "<<test_o.test <<" test_o.test2 : " << test_o.test2 << std::endl;
    return 0;
}