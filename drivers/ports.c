#include "ports.h"

uint8_t port_byte_input(uint32_t port)
{    
    uint8_t result;

    __asm__ volatile (

        "in %%dx, %%al" : "=a" (result) : "d" (port)
    );
    
    return result;
}

void port_byte_output(uint32_t port, uint8_t data)
{    
    __asm__ volatile (

        "out %%al, %%dx" : : "a" (data), "d" (port)
    );
}
