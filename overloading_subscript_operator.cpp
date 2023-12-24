#include <iostream>

//? overloading the subscript operator requires to use member function for overloading

class IntList{
    public:
        //? we can overload the subscript operator to redirect indexing from the user-defined object to the data member list
        //! we return a reference to the indexed element so that it can also be modified by the caller who indexed the list
        //~ returning by value or returning a const reference would not allow the user to modify the indexed element
        int& operator[](int index){
            return m_list[index];
            //! return const_cast<int&>(getIndex(index));
        }
        //? now const objects of the class IntList would not be able to use the subscript operator because the overloaded function would be able to modify data members
        //* therefore a explicit version for const objects is necessary
        //* the non-const version will be used by non-const objects and the const version by the const objects
        const int& operator[](int index) const {
            //? readonly version of the operator[]
            //* this function could also return by value if the type is cheap to copy
            return m_list[index];
            //! return getIndex(index);
        }
    private:
        int m_list[10]{0,1,2,3,4,5,6,7,8,9};

        //~ if the implementations for the two different subscript overloaded functions versions would be complex and long
        //* then we could use private member function that returns a const reference and remove the const characteristic with const_cast<>()
        const int& getIndex( int value ){
            return m_list[value];
        }
};
 

int main () {

    IntList my_list {};
    const IntList const_int_list {};
    //? accessing the second index of the underlying data member list of my_list object
    
    std::cout << my_list[2] << std::endl;
    //? my_list[2] returns a reference to the indexed integer element and allows us to modify its value
    //* inorder to assign a value to my_list[2] it actually has to return a lvalue (references are lvalues)
    my_list[2] = 22;
    std::cout << my_list[2] << std::endl;
    
    // const_int_list[1] = 100; //! compiler error: expression must be a modifiable lvalue
    //? uses the const verion of the overloaded[] operator because it is called on a const object
    std::cout << const_int_list[1] << std::endl;

    return 0;
}