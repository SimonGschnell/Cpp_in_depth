#include <iostream>
#include <string>
#include <string_view>
#include <initializer_list>

//? Template classes are instantiated in the same way template functions are
//* the compiler stencils out a copy upon demand, with the template parameter replaced by the actual data type the user needs, 
//* and then compiles the copy. If you don’t ever use a template class, the compiler won’t even compile it.

template <typename T>
class Array final{
    private:
        T* m_data;
        int m_length{};
    public:
        Array(int length){
            m_data = new T[length];
            m_length = length;
        }
        Array(std::initializer_list<T> list): Array(list.size()){
            int count =0;
            for(const auto& i : list){
                m_data[count] = i;
                count++;
            }
        }
        Array(const Array&) = delete;
        Array& operator=(const Array&) = delete;
        ~Array(){
            delete[] m_data;
        }
        T& operator[] (int value);

};

//? each templated member functions that have their definition outside of the class, needs its own template declaration 
template <typename T>
T& Array<T>::operator[] (int value){
    return m_data[value];
}

int main(){

    Array arr{1,2,3};
    Array arr2{1.5,2.5,3.5};
    Array arr3{"a", "b", "c"};
    std::cout << arr[2] << std::endl;
    std::cout << arr2[1] << std::endl;
    std::cout << arr3[0] << std::endl;


    return 0;
}