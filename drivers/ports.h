#ifndef DRIVERS_PORTS_H
#define DRIVERS_PORTS_H

#include "../include/type.h"

uint8_t port_byte_input(uint32_t port);

void port_byte_output(uint32_t port, uint8_t data);

#endif
