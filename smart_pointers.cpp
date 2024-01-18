#include <iostream>

class Resource{
    public:
    Resource(){
        std::cout << "resource aquired" << std::endl;
    }
    ~Resource(){
        std::cout << "resource deallocated" << std::endl;
    }
    void print(){
        std::cout << "resource" << std::endl;
    }
};

template <typename T>
class AutoPtr{
    public:
        AutoPtr(T* ptr): m_ptr{ptr}{
            
        }
        ~AutoPtr(){
            delete m_ptr;
            
        }

        //! without defining a own copy constructor and overloading the operator= this class has a critical flaw
        //! because the default copy constructor only does shallow copies and therefore multiple copies will point to the same resource and all try to delete the same
        //? but pointers don't normally copy the resource they get assigned or get initialized with
        //* therefore we can use move semantics, move semantics transfers ownership of the object rather than making a copy

        //? implementing move semantics for the copy constructor
        AutoPtr(AutoPtr& ptr){
            m_ptr = ptr.m_ptr;
            ptr.m_ptr = nullptr;
        }
        //? implements move semantics for the operator=
        AutoPtr* operator= (AutoPtr& ptr){
            if(this == &ptr){
                return *this;
            }
            //? deleting a nullptr is ok, as it does nothing
            delete m_ptr;
            m_ptr = ptr.m_ptr;
            ptr.m_ptr = nullptr;
            
            return *this;
        }
        
        T operator*()const{
            return *m_ptr;
        }
        T* operator->()const{
            return m_ptr;
        }
        bool isNull()const {
            if(m_ptr == nullptr)return true;
            return false;
        }
    private:
        T* m_ptr;
};

int main(){
    AutoPtr auto_ptr {new Resource};
    std::cout << std::boolalpha;
    std::cout << auto_ptr.isNull() << std::endl;
    
    //? instead of shallow copying the auto_ptr it moves ownership of the resource
    AutoPtr auto_ptr2 =auto_ptr;
    std::cout << auto_ptr.isNull() << std::endl;
    
    

    return 0;
}