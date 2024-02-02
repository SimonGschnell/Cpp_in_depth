#include <iostream>
#include <string>
#include <string_view>

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
        //! if you want to have an empty deconstructor that is virtual you have to define it as default and mark it virtual
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
    //* only the Deconstructor of Base is called because the destructor is not virtual
    //! the Derived part which may contain dynamically allocated memory that has to be cleaned up will not be deconstructed
    delete b;
    
    //? We always mark destructors of the base class as virtual, to call every destructor in the inheritance hierarchy
    Derived* d2{new Derived{}};
    vBase* vb{d2};
    delete vb;

    return 0;
}