#include "keyboard.h"

void process_key_code(uint32_t key)
{
    // Escape
    
    if (key == 0x01)
    {
        escape_pressed = true;
    }


    // Backspace
    
    if (key == 0x0e)
    {
        backspace_pressed = true;

        backspace();
    }


    // Tab

    if (key == 0x0f)
    {
        print_character(' ', TEXT_COLOR_BLACK);
        print_character(' ', TEXT_COLOR_BLACK);
        print_character(' ', TEXT_COLOR_BLACK);
    }


    // Enter

    if (key == 0x1c)
    {
        enter();
    }


    // Ctrl

    if (key == 0x1d)
    {
        ctrl_pressed = true;
    }


    // Shift left and right

    if ((key == 0x2A) || (key == 0x36))
    {
        if (shift_pressed == true)
        {
            shift_pressed = false;

        }
        else
        {

            shift_pressed = true;
        }
    }


    // Alt left

    if (key == 0x38)
    {
        if (alt_pressed == true)
        {
            alt_pressed = false;
        }
        else
        {
            alt_pressed = true;
        }
    }


    // Space

    if (key == 0x39)
    {
        print_character(' ', TEXT_COLOR_BLACK);
    }
    

    // Alt left

    if (key == 0x3A)
    {
        if (caps_pressed == true)
        {
            caps_pressed = false;
        }
        else
        {
            caps_pressed = true;
        }
    }


    for (uint8_t index = 0x00; index < 0x39; index += 1)
    {
        if ((index < 0x0e) || (index > 0x26 && index < 0x2a) || (index == 0x2b) || (index > 0x32 && index < 0x36))
        {
            if (key == index)
            {
                if (shift_pressed == true)
                {
                    print_character(array_key[index][1], TEXT_COLOR_WHITE);
                }
                else
                {
                    print_character(array_key[index][0], TEXT_COLOR_WHITE);
                } 
            }
        }


        if ((index > 0x0f && index < 0x1c) || (index > 0x1d && index < 0x27) || (index > 0x2b && index < 0x33))
        {
            if (key == index)
            {
                if ((shift_pressed == true) || (caps_pressed == true))
                {
                    print_character(array_key[index][1], TEXT_COLOR_WHITE);
                }
                else
                {
                    print_character(array_key[index][0], TEXT_COLOR_WHITE);
                } 
            }
        }
    }
}


void process_keyboard() {

    if (port_byte_input(0x64) & 0x01)
    {
        uint8_t code = port_byte_input(0x60);

        process_key_code(code);
    }
}
