#include "overloading_operator_with_normal_functions.h"

//? implementation of the forward declared overloaded operator
int operator+(Person p1, Person p2){
    return p1.get_age() + p2.get_age();
}