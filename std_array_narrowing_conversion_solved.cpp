#include <iostream>
#include <array>


int main(){
    //? std::array also uses std::size_t as the indexing and length type (std::size_t is a large unsigned integral type)
    //* signed integrals conversion are narrowing conversions
    //! except for constexpr integrals, signed conversions are not narrowing because the value is known at compile time
    constexpr std::array<int,5> arr{1,2,3,4,5};
    std::array<int,5> non_constexpr_arr{1,2,3,4,5};

    //? getting the size of an std::array
    //! every option returns a constexpr size value even if the std::array itself is not constexpr!
    //* with .size() member function (returns std::size_t)
    std::cout << arr.size() << std::endl;
    //* with static function std::size() (calls member function .size())
    std::cout <<  std::size(arr) << std::endl;
    //* with c++20 static function std::ssize() (returns the signed counterpart of std::size_t which is std::ptrdiff_t)
    std::cout <<  std::ssize(arr) << std::endl;

    //? arr.size() returns a constexpr unsigned std::size_t value
    constexpr int length{arr.size()}; //* which can be converted to signed int without narrow conversion because it is constexpr
    constexpr int length2{non_constexpr_arr.size()}; //? same for non-constexpr std::arrrays

    //? indexing std::array
    //* while the .at() member function does bound checking at runtime and the subscript operator has no bounds checking at all
    //* std::get() template function which takes a non-type template argument does bounds checking at compile time
    std::cout << "std::get<1>(arr): " << std::get<1>(arr) << std::endl;
    //? the non-type template argument has to be constexpr
    constexpr std::size_t index{2};
    std::cout << "std::get<index>(arr): " << std::get<index>(arr) << std::endl;
    //std::get<6>(arr) //! throws compiler error because bounds of the array are checked at compile time with std::get
    //? inside the implementation of std::get is a static_assert which checks if the non-type argument is smaller than the array length

    return 0;
}