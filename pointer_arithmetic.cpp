#include <iostream>

template <typename T,int N>
void traversing_pointer_arithmetic(T arr[N]){
	
    const int* end{ arr + N }; // end points to one-past-the-end element

	for (; arr != end; ++arr)           // iterate from begin up to (but excluding) end
	{
		std::cout << *arr << ' ';     // dereference our loop variable to get the current element
	}

}

//! range for loops are implemented somewhat in this manner, passing the start and end as parameters
void traversing_pointer_arithmetic(int* start, int* end){
	for (; start != end; ++start)           // iterate from begin up to (but excluding) end
	{
		int range_declaraion = *start ;     // here the variable is assigned the next element in the loop 
	}

}

int main(){

    //? pointer arithmetic allows us to use arithmetic operators to produce new memory addresses 
    //* given some pointer "ptr", ptr + 1 returns the address of the next object in memory
    //* if ptr is an int* and int is 4 bytes, ptr + 1 returns the address that is 4 bytes after ptr
    //* and ptr + 2 returns the address that is 8 bytes after ptr

    int x{1};
    int* int_ptr {&x};
    std::cout << "addition of memory\n" <<
    "memory address: " << int_ptr   << " - value: " << *int_ptr     << "\n" << 
    "memory address: " << int_ptr+1 << " - value: " << *(int_ptr+1) << "\n" << 
    "memory address: " << int_ptr+2 << " - value: " << *(int_ptr+2) << std::endl;
    
    //? pointer arithmetic also works when subtracting from a memory address
    std::cout << "subtraction of memory\n" <<
    "memory address: " << int_ptr   << " - value: " << *int_ptr     << "\n" << 
    "memory address: " << int_ptr-1 << " - value: " << *(int_ptr-1) << std::endl;
    
    //? ++ and -- will move the pointer and assign the pointer the new address
    //* because ++ptr = ptr = ptr + 1
    int* ptr {&x};
    std::cout << "++ptr:\n"
    << ptr << " - ";
    ++ptr;
    std::cout << ptr << std::endl;

    //? the subscript operator is implemented using pointer arithmetic
    //* subscripting the index 2 is the same as moving forward 2 memory address sizes of type T that is used as element type
    //~ the subscript operator evaluates arr[2] as *(arr+2)
    int arr[] {2,4,6};
    for(int i{0}; i < std::size(arr) ; i++){
        std::cout << arr[i] << std::endl;
        std::cout << *(arr+i) << std::endl;
    }
    //! this is the primary reason arrays are 0 based. because the compiler doesn't have to subract 1 whenever subscripting
    
    //? array indexes are relative positions and don't represent fixed elements within the array
    //* indexes are just offsets from the starting position
    //* if the starting position is not the start, the index does not represent an element in that fixed index position
    int* starting_pos{arr};
    std::cout << "strating from 0: arr[0]="<< starting_pos[0] << " - *(arr)=" << *(starting_pos)<< std::endl;
    starting_pos = (arr+1);
    std::cout << "strating from 1: arr[0]="<< starting_pos[0] << " - *(arr)=" << *(starting_pos)<< std::endl;
    //? negative subscription values are also possible resulting in: *((arr)+(-1))
    std::cout << "arr[-1]: "<< starting_pos[-1] << std::endl ;

    //! Favor subscripting when indexing from the start of the array (element 0), so the array indices line up with the element.
    //! Favor pointer arithmetic when doing relative positioning from a given element.
    
    traversing_pointer_arithmetic<int,3>(arr);

    return 0;
}