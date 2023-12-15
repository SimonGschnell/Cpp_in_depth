#include <iostream>
#include <vector>
#include <array>
#include <functional>

//! captured references to variables can be dangling if the referenced variable dies before the lambda
auto makeWalrus(const std::string& name)
{
  // Capture name by reference and return the lambda.
  //? the lambda will be returned with a dangling reference to name because it dies at the end of the function
  //~ this can be avoided by capturing the parameter by value which creates a clone inside the lambda
  return [&]() {
    std::cout << "I am a walrus, my name is " << name << '\n'; // Undefined behavior
  };
}

//? when lambdas are passed to a std::function, a copy of the lambda is made in the implementation of std::function
//! this can be avoided by passing the lambda insida a std::reference_wrapper, so only the reference_wrapper is copied and not the lambda inside it
//~ Standard library functions may copy function objects (lambdas are function objects)
void myInvoke(const std::function<void()>& fn)
{
    //? best practice is trying to avoid mutable lambdas, so these problems don't arise
    fn();
}


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
        }Standard library functions may copy function objects (reminder: lambdas are function objects).
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
    auto lambda_capture_default{[=]()  mutable { 
        //? captures random_integer by value
        ++random_integer; 
        std::cout << random_integer << std::endl;
        
    }};

    //* by specifying & inside the capture close, every capture is passed as reference to the lambda
    auto lambda_capture_default2{[&]()  { 
        //? captures fruit_basket by reference
        std::cout << fruit_basket[0] << std::endl;
    }};

    //* default captures can be combined with normal captures 
    //? captures fruit_basket by reference and everything else by value
    auto lambda_capture_default3{[=, &fruit_basket]()  { 
        std::cout << random_integer << fruit_basket[0] << std::endl;        
    }};

    //? variables can be created on the fly in the capture clause for lambdas 
    //* the type of the created variable that is only visible in the lambda is automatically deduced
    auto lambda_capture_default4{[first_fruit{fruit_basket[0]}]()  { 
        std::cout << first_fruit << std::endl;        
    }};

    lambda_fun();
    lambda_fun2();
    lambda_capture_reference();

    myInvoke(lambda_capture_default);
    myInvoke(lambda_capture_default);
    myInvoke(lambda_capture_default);
    //! std::ref can be used to create a std::reference_wrapper
    myInvoke(std::ref(lambda_capture_default));
    myInvoke(std::ref(lambda_capture_default));
    myInvoke(std::ref(lambda_capture_default));

    
    //* printing the original lambda function
    for(const auto& item : fruit_basket){
        std::cout << item << std::endl;
    }

}