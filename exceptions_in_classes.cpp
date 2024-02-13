#include <iostream>
#include <memory>

class Resource{
    public:
        Resource(){
            std::cout << "Resource was created" << std::endl;
        }
        ~Resource(){
            std::cout << "Resource was destroyed" << std::endl;
        }
};

class Base{
    private:
        int m_base{};
        //? class members are desctructed even if the constructor fails
        //* prefere doing resource allocation inside of the members and not in the constructor, those members can then clean up after themselves when they are destructed
        //? that is why RAII is so highly advocated
        Resource m_resource{};
        //? instead of creating classes our own to manage resources with the RAII principle, we can use RAII supported classes from the standard library
        //* RAII unique_ptr will be deallocated when the constructor of the class fails (no complicated cleanup procedures necessary)
        std::unique_ptr<int> m_unique_resource{};
    public:
        Base(int value): m_base{value} {
            if(value < 0){
                //? raises an exception in the constructor
                //! exceptions in the constructor fails the construction of the object and the Destructor will not be called to destroy the initialized properties properly
                throw 1;
            }
            
        }
        ~Base(){
            std::cout << "Base destructor was called" << std::endl;
        }
};

int main(){

    try{
        Base b{-1};
    }catch(int exception){
        std::cout << "int exception: " << exception << std::endl;
    }
    



    return 0;
}