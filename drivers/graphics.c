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


void print_string(const char *string, uint8_t text_color)
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

bool run_command()
{
    uint8_t command[COMMAND_SIZE];

    for (uint32_t i = 0; i < COMMAND_SIZE; i += 1)
    {
        command[i] = *(video_memory + starting_point_of_command + (i * 2));
    }

    return process_shell(command);
}


void shift_screen_to_up(int number)
{
    uint32_t cursor = get_cursor();

    for (uint32_t i = (2 * SCREEN_WIDTH); i < ((2 * SCREEN_WIDTH) * (number + 2)); i += 2)
    {
        if (number + 2 >= SCREEN_HEIGHT)
        {
            *(video_memory + i) = 0x00;
        }
        else
        {
            *(video_memory + i - (2 * SCREEN_WIDTH)) = *(video_memory + i);
            *(video_memory + i - (2 * SCREEN_WIDTH) + 1) = *(video_memory + i + 1);
        }
    }

    set_cursor(cursor - (2 * SCREEN_WIDTH));
}


void enter()
{
    run_command();
}

void  backspace()
{
    uint32_t cursor = get_cursor();

    uint32_t cursor_column = get_cursor_column();

    if (cursor_column > (OPERATION_SYSTEM_NAME_SIZE * 2))
    {
        *(video_memory + cursor - 2) = 0x00;
    
        set_cursor(cursor - 2);
    }
}

void show_zero_one()
{
    clear_screen();

    for (uint32_t i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (uint32_t j = 0; j < SCREEN_WIDTH; j++)
        {
            if (array_zero_one[i][j] == 1)
            {
                uint32_t rand = random();

                rand = max_min(10000, 0, rand);

                if (rand % 2 == 0)
                {
                    print_character('0', TEXT_COLOR_LIGHT_GREEN);
                }
                
                if (rand % 2 == 1)
                {
                    print_character('1', TEXT_COLOR_LIGHT_GREEN);
                }
            }
            else
            {
                print_character(' ', TEXT_COLOR_LIGHT_GREEN);
            }
        }
    }
}

void screen_start()
{
    for (uint32_t i = 0; i < SCREEN_HEIGHT; i++)
    {
        uint32_t rand_1 = random();

        rand_1 = max_min(10000, 0, rand_1);

        for (uint32_t j = 0; j < (rand_1 % 10); j++)
        {
            uint32_t rand_2 = random();

            rand_2 = max_min(10000, 0, rand_2);

            if (array_zero_one[0][rand_2 % SCREEN_WIDTH] == 0)
            {
                array_zero_one[0][rand_2 % SCREEN_WIDTH] = 1;
            }
        }

        for (int32_t j = line_zero_one; j >= 0; j--)
        {
            for (int32_t k = 0; k < SCREEN_WIDTH; k++)
            {
                if (array_zero_one[j][k] == 1)
                {
                    array_zero_one[j + 1][k] = 1;
                }
            }
        }

        for (uint32_t j = 0; j < 100000; j++) {}

        line_zero_one += 1;

        show_zero_one();
    }
}
