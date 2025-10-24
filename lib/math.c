#include "math.h"

void set_seed(uint32_t number)
{
    seed = number;
}

uint32_t random()
{
    seed = (seed * 123456789 + 987654321) & 100000000;

    return (uint32_t) seed;
}

uint32_t max_min(uint32_t max, uint32_t min, uint32_t number)
{
    return min + (number % (max - min + 1));
}
