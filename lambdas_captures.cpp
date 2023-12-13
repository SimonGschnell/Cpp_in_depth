#include <iostream>
#include <vector>



int main(){

    using namespace std::string_literals;
    std::vector<std::string> fruit_basket {"apple", "orange" , "banana"};
    int random_integer {55};
 
    //? lambdas capture clause "[]" are used to give a lambda access to variables available in the surrounding scope
    //~ lambdas only have access to global variables or variables with static scope/duration  
    //* we added the fruit_basket array to the capture of the lambda in order to use the variable inside of the lambda
    //! variables placed inside the capture of a lambda are actually cloned and put into the scope of the lambda
    auto lambda_fun {[fruit_basket](){ //* by default variables captured by a lambda are const values

        
        for( const auto& item : fruit_basket){
            std::cout << item << std::endl;
        }
    }};

    //? we can add the mutable keyword to the lambda to allow modification to the captured variables
    auto lambda_fun2 {[fruit_basket]() mutable { 
        //! even though we modified the second element in the list, the original list still is unchanged
        fruit_basket[1] = "foo";
        for( const auto& item : fruit_basket){
            std::cout << item << std::endl;
        }
    }};

    //? in order to pass an outer scope variable to the lambda by reference we have to add an & before the captured variable name
    //~ captured references are non-const by default unless the variable beeing captured is const itself
    auto lambda_capture_reference {[&fruit_basket]()  { 
        //? this time we actually change the original list because we captured a reference to the outside variable
        fruit_basket[1] = "bobo";
        for( const auto& item : fruit_basket){
            std::cout << item << std::endl;
        }
    }};

    //~ multiple variables can be captured by a lambda separating them by a comma
    //* the different captured variables can be passed by reference or by value
    auto lambda_capture_multiple{[&fruit_basket, random_integer]()  { 
        //? contains a referece to the outer scope fruit_basket 
        //? and contains a clone of the value of the outer scope random_integer variable with the same name
    }};

    //~ listing all used captured variables inside a lambda can be burdensome
    //? c++ supports default captures by value or by reference
    //* by specifying = insde the capture clause, every outside scope variable used in the lambda is cloned (passed by value) 
    auto lambda_capture_default{[=]()  { 
        //? contains clones of the captures
    }};

    //* by sepcifying & inside the capture close, every capture is passed as reference to the lambda
    auto lambda_capture_default2{[&]()  { 
        //? contains references to the captures
    }};

    lambda_fun();
    lambda_fun2();
    lambda_capture_reference();
    
    //* printing the original lambda function
    for(const auto& item : fruit_basket){
        std::cout << item << std::endl;
    }

}