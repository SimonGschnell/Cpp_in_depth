#include <iostream>
#include <string>
#include <string_view>

//~ the parentheses operator has to be defined as a member function
//* and it one of the only operators that take varying count of arguments

class Matrix {

    public:
        Matrix() = default;
        //? overloading () operator
        int& operator() (int row, int column);
        int operator() (int row, int column) const;
        //~ because the operator() can have varying arguments we can define multiple overloaded versions of the operator 
        //* for example operator() with no arguments
        void operator() (){ 
            //* this implementation will reset the matrix to all zero values
            for(auto& row : m_matrix){
                for (auto& col : row){
                    col = 0;
                }
            }
        }
    private:
        int m_matrix [4] [4]{}; 
};

int& Matrix::operator() (int row, int column){
    //? implementing the () operator to return the element at (row, column)
    return m_matrix[row][column];
}

//* overloaded version for const objects
int Matrix::operator() (int row, int column) const {
    return m_matrix[row][column];
}


class MyString{
    public:
        MyString (std::string_view s) : m_string{s}{}
        //? overloading the << operator to output the user-defined object using the underlying string data memberk
        friend std::ostream& operator<< (std::ostream& out , const MyString& s){
            out << s.m_string;
            return out;
        }
        //? instead of returning a string and creating the substring with std::string_substring which creates another copy of the string we use std::string_views and its substring function
        MyString operator() (int start, int end){
            std::string_view s_view {m_string};
            return MyString{s_view.substr(start,end)};
        }
    private:
        std::string m_string{};
};

int main(){

    Matrix m{};
    m(1,2) = 44;
    std::cout << m(1,2) << std::endl;
    //* reseting the matrix with the custom () overload
    m();
    std::cout << m(1,2) << std::endl;

    MyString s { "Hello, world!" };
    std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

    return 0;
}