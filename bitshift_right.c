#include <stdio.h>

int main(){
    int value = 128;
    printf(" 128 >> 1 = %d\n", value>>1); // >> 1 is equal to divided by 2^1 (2)
    printf(" 128 >> 2 = %d\n", value>>2); // >> 1 is equal to divided by 2^2 (4)
    printf(" 128 >> 3 = %d\n", value>>3); // >> 1 is equal to divided by 2^3 (8)
     
    printf(" 128 |= (1<<1) = %d\n", value | (1<<1)); // | (1<<1) or between 010000000 | 00000010
    printf(" 128 |= (1<<2) = %d\n", value | (1<<2)); // | (1<<2) or between 010000000 | 00000100
    printf(" 128 |= (1<<3) = %d\n", value | (1<<3)); // | (1<<3) or between 010000000 | 00001000
    
}