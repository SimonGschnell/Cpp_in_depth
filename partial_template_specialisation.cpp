#include <algorithm>
#include <iostream>
#include <string_view>

template <typename T, int size> // size is the expression parameter
class StaticArray
{
private:
	// The expression parameter controls the size of the array
	T m_array[size]{};
    int m_length{size};

public:
	T* getArray() { return m_array; }

	const T& operator[](int index) const { return m_array[index]; }
	T& operator[](int index) { return m_array[index]; }
    int getSize() { return m_length; }
    void print();
};

template<typename T, int size>
void StaticArray<T, size>::print()
{
    for (int count{ 0 }; count < size; ++count)
        std::cout << m_array[count] << ' ';
    std::cout << std::endl;
}

/* //! functions do not support partial template specialization and therefore we cannot do the following
//~ a solution would be to partial specialize the template class and then define the specific implementation of the member function
template<>
template<int size>
void StaticArray<char, size>::print()
{
    for (int count{ 0 }; count < size; ++count)
        std::cout << array[count] << ' ';
}*/

//? partial specialization of the template class StaticArray with template type parameter T=char
template <int size> 
class StaticArray<char,size>
{
private:
	char m_array[size]{};
    int m_length{size};

public:
	char* getArray() { return m_array; }

	const char& operator[](int index) const { return m_array[index]; }
	char& operator[](int index) { return m_array[index]; }
    int getSize() { return m_length; }
    void print();
};

//! here we simply implement the member function of the partial specialized template class
template<int size>
void StaticArray<char, size>::print() {
    for (int count{ 0 }; count < size; ++count)
		std::cout << m_array[count];
    std::cout << std::endl;
}


//? how to partial specialize normal functions
template <typename T, int size>
void print(const StaticArray<T, size>& array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count] << ' ';
    std::cout << std::endl;
}

//? Override print() for fully specialized StaticArray<char, 14>
template <>
void print(const StaticArray<char, 14>& array)
{
	for (int count{ 0 }; count < 14; ++count)
		std::cout << array[count];
    std::cout << std::endl;
}

//! Partial specialization is only available for classes, normal functions and member functions cannot be partial specialized
//? instead we are overloading the function with a different template type
template <int size>
void print(const StaticArray<char, size>& array)
{
	for (int count{ 0 }; count < size; ++count)
		std::cout << array[count];
    std::cout << std::endl;
}

int main()
{

    // Declare a int array
    StaticArray<int,12> int12{};

    // fill int array with numbers
    for(int i{0}; i<int12.getSize() ; i++){
        int12[i] = i;
    }

    // Print the array
    //! the <int,12> version will stencil out a specific version of the print function and use the full template version
    print(int12);

    // Declare a char array
    StaticArray<char, 14> char14{};

    // Copy some data into it
    constexpr std::string_view hello{ "Hello, world!" };
    std::copy_n(hello.begin(), hello.size(), char14.getArray());

    // Print the array
    //! the <char,14> version will use the full template specialisation instead
    //! what happens when we want to create a StaticArray with the template type parameters <char,10> ?
    //! the template function would be called and not the full template specialisation 
    print(char14);

    //? calling print from the template class int12 stencils out a <int,12> version with the default print member function
    int12.print();
    //? version <char,14> will call the partial specialized template class StaticArray<char, int size> with its customized member function
    char14.print();

    return 0;
}