#include <iostream>
#include <string>
#include <string_view>

//~ marking every desctructor virtual comes with a cost, each class also has to store an extra virtual pointer:
//! Rule of thumb: if you intent your class to be inherited from, use a virtual desctructor to avoid memory leaks when deleting a pointer to the base class
//? if you don't intent your class to be inherited from, make the class final, so that other classes can't inherit from the class and the destructor does not have to be marked virtual

class Resource{
    public:
        Resource(){
            std::cout << "Resource aquired" << std::endl;
        }
        ~Resource(){
            std::cout << "Resource deallocated" << std::endl;
        }
};

class Base{
    public:
        Base() {}
        ~Base(){
            std::cout << "Base Destructor called" << std::endl;
        }
    private:
        
};

class vBase{
    public:
        vBase() {}
        virtual ~vBase(){
            std::cout << "vBase Destructor called" << std::endl;
        }
        //! if you want to have an empty desctructor that is virtual you have to define it as default and mark it virtual
        //virtual ~vBase() = default;
    private:
        
};

class Derived : public Base, public vBase{
    public:
        Derived():m_data{new Resource{}}{
            
        }
        virtual ~Derived(){
            std::cout << "Derived Destructor called" << std::endl;
            delete m_data;
        }
    private:    
        Resource* m_data{};
};

int main(){
    Derived* d{new Derived{}};
    
    Base* b{d};
    
    //? when trying to delete b which is a Base pointer to d a dynamically allocated Derived object
    //* only the Desctructor of Base is called because the destructor is not virtual
    //! the Derived part which may contain dynamically allocated memory that has to be cleaned up will not be desctructor
    delete b;
    
    //? We can mark destructors of the base class as virtual, to call every destructor in the inheritance hierarchy
    Derived* d2{new Derived{}};
    vBase* vb{d2};
    delete vb;

    return 0;
}