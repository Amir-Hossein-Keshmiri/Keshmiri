#include "shell.h"


bool is_empty(uint8_t *command)
{
    for (uint8_t i = 0; i < COMMAND_SIZE; i++)
    {
        if (*(command + i) != 0x00)
        {
            return false;
        }
    }

    return true;
}

bool search_command_list(char *command_expected, uint8_t *command, uint16_t command_exepted_size)
{
    for (uint8_t i = 0; i < command_exepted_size; i++)
    {
        if (command_expected[i] != *(command + i))
        {
            return false;
        }
    }

    return true;
}


void command_clear()
{
    clear_screen();

    print_operation_system_name();
}


void command_echo(uint8_t *command)
{
    for (uint8_t i = 5; i < COMMAND_SIZE; i++)
    {
        print_character(*(command + i), TEXT_COLOR_WHITE);
    }
}


void command_uname()
{
    print_string("Hi, this is a simple operation system created by Amir Hossein Keshmir :)", TEXT_COLOR_WHITE);
}


bool process_shell(uint8_t *command)
{
    uint16_t cursor_row = get_cursor_row();

    if (!is_empty(command))
    {
        if (search_command_list("clear", command, 5))
        {
            command_clear();

            return true;
        }

        if (cursor_row >= 21)
        {
            for (uint16_t i = cursor_row; i > 19; i -= 1)
            {
                shift_screen_to_up(i);
            }
        }

        move_cursor_to_new_line();
        
        if (search_command_list("echo ", command, 5))
        {
            command_echo(command);
        }
        else if (search_command_list("uname", command, 5))
        {
            command_uname();
        }
        else
        {
            print_string("Unknown command", TEXT_COLOR_WHITE);
        }

        move_cursor_to_new_line();

        print_operation_system_name();

    }
    else
    {
        if (cursor_row == 21)
        {
            shift_screen_to_up(21);
        }

        move_cursor_to_new_line();

        print_operation_system_name();
    }

    return false;
}
