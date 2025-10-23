#include "graphics.h"

uint32_t get_cursor()
{    
    port_byte_output(REG_SCREEN_CTRL, 0x0e);
    
    uint32_t output_cursor = port_byte_input(REG_SCREEN_DATA) shift_left 8;
    
    port_byte_output(REG_SCREEN_CTRL, 0x0f);
    
    output_cursor += port_byte_input(REG_SCREEN_DATA);
    
    return output_cursor * 2;
}

void set_cursor(uint32_t input_cursor)
{
    input_cursor /= 2;
    
    port_byte_output(REG_SCREEN_CTRL, 0x0e);
    
    port_byte_output(REG_SCREEN_DATA, (uint8_t) ((input_cursor shift_right 0x08) bit_and 0xff));

    port_byte_output(REG_SCREEN_CTRL, 0x0f);
    
    port_byte_output(REG_SCREEN_DATA, (uint8_t) (input_cursor bit_and 0xff));
}

uint32_t get_cursor_row()
{
    uint32_t cursor = get_cursor();

    return cursor / (SCREEN_WIDTH * 2);
}

uint32_t get_cursor_column()
{
    uint32_t cursor = get_cursor();

    return cursor % (SCREEN_WIDTH * 2);
}

void clear_screen()
{
    for (uint32_t i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT * 2); i += 2)
    {
        *(video_memory + i) = BACKGAROUNDE_COLOR_BLACK + TEXT_COLOR_BLACK;
    }

    set_cursor(0);
}

void print_character(uint8_t character, uint8_t color_character)
{
    uint32_t cursor = get_cursor();

    *(video_memory + cursor) = character;
    *(video_memory + cursor + 1) = SCREEN_BACKGAROUNDE_COLOR + color_character;

    set_cursor(cursor + 2);
}


void print_string(const uint8_t *string, uint8_t text_color)
{
    uint32_t index = 0;

    while (string[index] != 0)
    {
        print_character(string[index], text_color);

        ++index;
    }
}

void print_operation_system_name()
{
    print_string(OPERATION_SYSTEM_NAME, TEXT_COLOR_LIGHT_GREEN);

    print_character(' ', TEXT_COLOR_BLACK);
    print_character('#', TEXT_COLOR_LIGHT_CYAN);
    print_character('>', TEXT_COLOR_WHITE);
    print_character(' ', TEXT_COLOR_BLACK);

    uint32_t cursor = get_cursor();

    starting_point_of_command = cursor;
}

void move_cursor_to_new_line()
{
    uint32_t cursor = get_cursor();

    set_cursor((cursor / (SCREEN_WIDTH * 2) + 1) * (SCREEN_WIDTH * 2));
}
