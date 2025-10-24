#ifndef LIB_MATH_H
#define LIB_MATH_H


#include "../include/type.h"


static uint32_t seed = 0;


void set_seed(uint32_t number);

uint32_t random();

uint32_t max_min(uint32_t max, uint32_t min, uint32_t number);


#endif
