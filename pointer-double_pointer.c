#include <stdio.h>

int main(){
    /* int names[10];
    for(int i =0; i < 10; i++){
        names[i] = i;
        printf("names[%i] = %i\n",i,names[i]);
    }
     */

    int a = 10;
    //address of a variable can be specified with &
    printf("address of a = %p\n",&a);
    int* a_ptr = &a;
    //value of the pointer is the address of the variable
    printf("a_ptr shows to = %p\n",a_ptr);
    //address of the pointer itself
    printf("address of a_ptr = %p\n",&a_ptr);
    //creating a double pointer
    int** a_ptr_double = &a_ptr;
    //value of the double pointer is the address of the pointer a_ptr
    printf("a_ptr_double shows to = %p\n",a_ptr_double);
    //address of the double pointer itself
    printf("address of a_ptr_double = %p\n",&a_ptr_double);
    printf("value of a = %i\n",a);
    printf("value of a_ptr = %i\n",*a_ptr);
    printf("value of a_ptr_double = %i\n",**a_ptr_double);

    return 0;
}