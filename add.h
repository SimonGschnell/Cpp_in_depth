// alternative to header guards
// #pragma once 


//? header guards OR include guard
//* header guards prevent a program to include the header file multiple times 
//* which lead to name collision
#ifndef ADD_H
#define ADD_H

//forward declarations of add.cpp functions
int add(int x, int y);


#endif

