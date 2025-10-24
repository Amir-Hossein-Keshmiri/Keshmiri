#include "../drivers/graphics.h"
#include "../drivers/keyboard.h"

void main()
{
    screen_start();
    
    for (uint32_t k = 0; k < 1000000; k++) {}

    clear_screen();

    for (uint32_t k = 0; k < 1000000; k++) {}

    print_operation_system_name();

    while (true) {
    
        process_keyboard();
    }
}
