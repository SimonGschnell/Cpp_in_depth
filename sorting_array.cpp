#include <iostream>
#include <utility>
#include <array>
#include <vector>
#include <functional> // containes reference_wrapper

//~ implementation of our own swap function using references
//* modifying the parameters directly means using an out parameter
void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

//~ implementation of a selection sort with reference_wrapper
template <typename T>
void selection_sort_in_place(T& arr){
    std::reference_wrapper smallest{arr[0]};
    for(std::size_t i{0}; i < std::size(arr); i++){
        smallest = arr[i];
        for(std::size_t j{i+1}; j < std::size(arr); j++){
            if(arr[j] < smallest){ smallest = arr[j]; }
        }
        swap(arr[i], smallest.get());
        std::cout << arr[i] << std::endl;
    }
}

int main () {

    int x{3};
    int y{6};

    std::cout << x << y << std::endl;
    //? std::swap is a utility function in the <utility> library that swaps the values of 2 variables
    std::swap(x, y);
    std::cout << x << y << std::endl;

    std::vector arr{5,1,9,10,4,3};
    std::array arr2{35,1,2,3,99,0};
    int arr3[]{6,5,4,3,2,1};
    selection_sort_in_place(arr);
    selection_sort_in_place(arr2);
    selection_sort_in_place(arr3);
    

}