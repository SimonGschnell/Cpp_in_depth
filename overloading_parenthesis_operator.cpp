#include <iostream>

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

int main(){

    Matrix m{};
    m(1,2) = 44;
    std::cout << m(1,2) << std::endl;
    //* reseting the matrix with the custom () overload
    m();
    std::cout << m(1,2) << std::endl;

    return 0;
}