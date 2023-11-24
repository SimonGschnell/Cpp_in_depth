#include <iostream>
#include <vector>
#include <assert.h>

//? since vector uses size_type for its std::vector<T>::operator[] (subscript operator)
//* we can use unscoped enums to give the indexes meaning

namespace Students {
    enum Names: unsigned int //! defining to underlying type as unsigned int for indexing
    { 
      john, // 0
      sandra, // 1
      oliver, // 2
      peter, // 3

      // new enum types are added here

      //? the last enum type will always contain the value that equals to number of enum members
      //* therefore it can be used as the length 
      student_count // 4
    };
}

int main(){
    
    //? initializes the length of the vector the the number of enum members
    std::vector<int> grades (Students::student_count);

    //? when using a non-fixed sized vector we have to assert the length of the vector with the number of enum members
    std::vector<int> other_grades {5,6,6,7};
    //! if the container can be constexpr like std::array containers, we prefer to use static_assert instead
    assert(Students::student_count == other_grades.size());

    //* using enums enhances the logical meaning of indexes
    //! enums are also implicitly constexpr values which means there is no narrow conversion needed to size_t
    grades[Students::oliver] = 6; //? we update the grade that belongs to oliver

    //? when saving the enum type in a non-constexpr variable we lose the constexpr characteristic
    //* and then it depends on the underlying type of the enum
    //! this can be avoided by explicitly defining the underlying type of the unscoped enum 
    Students::Names index{Students::john};

    grades[index] = 1;


    //? in this loop student_count enum member was used as the length
    for(std::size_t i = 0; i < Students::student_count; i++){
        std::cout << grades[i] << std::endl;
    }
    for(const auto& element : grades){
        std::cout << element << std::endl;
    }

    return 0;
}