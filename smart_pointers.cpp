#include <iostream>

template <typename T>
class AutoPtr{
    public:
        AutoPtr(T* ptr): m_ptr{ptr}{
            std::cout << "resource allocated" << std::endl;
        }
        ~AutoPtr(){
            delete m_ptr;
            std::cout << "resource deallocated" << std::endl;
        }
        T operator*()const{
            return *m_ptr;
        }
        T* operator->()const{
            return m_ptr;
        }
    private:
        T* m_ptr;
};

int main(){
    AutoPtr<int> auto_ptr {new int{55}};
    std::cout << *auto_ptr << std::endl;

    return 0;
}