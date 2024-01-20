#include <iostream>
#include <utility>
#include <memory>

//? A smart pointer is a class that manages dynamically allocated resources 
//? and ensures that the resources is deallocated properly at the end of its lifetime
//* smart pointers are never dynamically allocated and always allocated on the stack, 
//* so that it is guaranteed that the smart pointer goes out of scope properly

// C++11 comes with 3 important smart pointer classes
//* - std::unique_ptr
//* - std::shared_ptr
//* - std::weak_ptr

//? std::unique_ptr manages dynamically allocated objects that is not shared by with others
//! std::unique_ptr completely owns the object it manages
//* std::unique_ptr lives in the <memory> header

//? std::unique_ptr overloads the * and -> operator to allow seamlessly interaction with the underlying resource it is holding
//! when managing fixed arrays / dynamic arrays / C-style arrays, favor using std::vector or std::array over an unique_ptr

//? C++14 comes with an additional function std::make_unique that dynamically allocates the specified templated type for you
//* std::make_unique is also available in the <memory> library

class Resource{
    public:
    Resource(){
        std::cout << "Resource aquired" << std::endl;
    }
    ~Resource(){
        std::cout << "Resource deallocated" << std::endl;
    }
    friend std::ostream& operator<< (std::ostream& out , const Resource& res){
        out << "this is a resource";
        return out;
    }
};

//? std::unique_ptr can safely be returned from a function because it uses move semantics and in C++17 or newer the return would be elided
//* unique_ptr's should always be returned by value if there isn't a specific reason to use a pointer or reference
std::unique_ptr<Resource> createUniqueResource(){
    return std::make_unique<Resource>();
}

//? std::unique_ptr can be passed to functions by value to pass ownership
//! because std::unique_ptr has copy semantics disabled the argument has to be passed with std::move if it is a l-value
//* this function takes ownership of the smart pointer and goes out of scope at the end of the function, which isn't what we want normally
template <typename T>
void print_unique_ptr(std::unique_ptr<T> res){
    // we check if the unique_ptr doesn't own a nullptr before dereferencing it
    if(res)
    std::cout << *res << std::endl;
}

//? instead of moving the std::unique_ptr, we can just pass a pointer to the resource the smart pointer is pointing to
//* we get a pointer to the resource the smart pointer is pointing to with .get()
void printResource(const Resource* res){
    // we check if the pointer is not a nullptr before dereferencing it
    if(res)
    std::cout << *res << std::endl;
}

int main(){

    std::unique_ptr<Resource> res{new Resource()};
    std::unique_ptr<Resource> res2{};

    //? std::unique_ptr implicitly casts to bool, to indicate whether it holds any resource or not
    if(res){
        std::cout << "res has ownership over a resource: " << *res << std::endl;
    }
    std::cout << "is res null? " << (res? "no" : "yes") << std::endl;
    std::cout << "is res2 null? " << (res2? "no" : "yes") << std::endl;
    //res2=res; //! compiler error: copy assignment operator or std::unique_ptr is deleted
    //? std::move makes l-value res to a r-value reference and the move assignment operator of the unique_ptr is called instead
    res2=std::move(res); 
    std::cout << "is res null? " << (res? "no" : "yes") << std::endl;
    std::cout << "is res2 null? " << (res2? "no" : "yes") << std::endl;

    //? creating a unique_ptr with type deduction and std::make_unique<T>
    auto res3 {std::make_unique<int>(4)};
    if(res3){
        *res3 = 10;
        std::cout << *res3 << std::endl;
    }

    //! moving the smart pointer inside the function with std::move, res2 will lose its ownership
    print_unique_ptr(std::move(res3));
    //? only passes the underlying resource of the smart pointer to the function without losing ownership
    printResource(res2.get());

    



    return 0;
}//? unique_ptr properly deletes the resource it is managing when it goes out of scope here 