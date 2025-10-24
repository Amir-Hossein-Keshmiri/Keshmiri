#ifndef DRIVERS_GRAPHICS_H
#define DRIVERS_GRAPHICS_H

#include "ports.h"

#include "../lib/math.h"

#include "../shell/shell.h"

#include "../include/type.h"
#include "../include/bool.h"
#include "../include/symbols.h"

#define VIDEO_MEMORY_ADDRESS                 0xb8000

#define SCREEN_WIDTH                         0x50       // 80
#define SCREEN_HEIGHT                        0x19       // 25

#define REG_SCREEN_CTRL                      0x3d4
#define REG_SCREEN_DATA                      0x3d5

#define BACKGAROUNDE_COLOR_BLACK             0x00
#define BACKGAROUNDE_COLOR_BLUE              0x10
#define BACKGAROUNDE_COLOR_GREEN             0x20
#define BACKGAROUNDE_COLOR_CYAN              0x30
#define BACKGAROUNDE_COLOR_RED               0x40
#define BACKGAROUNDE_COLOR_MAGENTA           0x50
#define BACKGAROUNDE_COLOR_BROWN             0x60
#define BACKGAROUNDE_COLOR_LIGHT_GRAY        0x70
#define BACKGAROUNDE_COLOR_GRAY              0x80
#define BACKGAROUNDE_COLOR_LIGHT_BLUE        0x90
#define BACKGAROUNDE_COLOR_LIGHT_GREEN       0xa0
#define BACKGAROUNDE_COLOR_LIGHT_CYAN        0xb0
#define BACKGAROUNDE_COLOR_LIGHT_RED         0xc0
#define BACKGAROUNDE_COLOR_LIGHT_MAGENTA     0xd0
#define BACKGAROUNDE_COLOR_LIGHT_YELLOW      0xe0
#define BACKGAROUNDE_COLOR_WHITE             0xf0

#define SCREEN_BACKGAROUNDE_COLOR            BACKGAROUNDE_COLOR_BLACK

#define TEXT_COLOR_BLACK                     0x00
#define TEXT_COLOR_BLUE                      0x01
#define TEXT_COLOR_GREEN                     0x02
#define TEXT_COLOR_CYAN                      0x03
#define TEXT_COLOR_RED                       0x04
#define TEXT_COLOR_MAGENTA                   0x05
#define TEXT_COLOR_BROWN                     0x06
#define TEXT_COLOR_LIGHT_GRAY                0x07
#define TEXT_COLOR_GRAY                      0x08
#define TEXT_COLOR_LIGHT_BLUE                0x09
#define TEXT_COLOR_LIGHT_GREEN               0x0a
#define TEXT_COLOR_LIGHT_CYAN                0x0b
#define TEXT_COLOR_LIGHT_RED                 0x0c
#define TEXT_COLOR_LIGHT_MAGENTA             0x0d
#define TEXT_COLOR_LIGHT_YELLOW              0x0e
#define TEXT_COLOR_WHITE                     0x0f

#define OPERATION_SYSTEM_NAME                "Keshmiri"

#define OPERATION_SYSTEM_NAME_SIZE           ((sizeof(OPERATION_SYSTEM_NAME) / sizeof(uint8_t)) + 0x03)

#define COMMAND_SIZE                         (SCREEN_WIDTH - OPERATION_SYSTEM_NAME_SIZE)


uint32_t starting_point_of_command = 0;

uint8_t *video_memory = (uint8_t *) VIDEO_MEMORY_ADDRESS;

uint32_t line_zero_one = 0;

uint32_t array_zero_one[SCREEN_HEIGHT][SCREEN_WIDTH];


uint32_t get_cursor_row();

uint32_t get_cursor_column();

void clear_screen();

void print_character(uint8_t character, uint8_t color_character);

void print_string(const char *string, uint8_t text_color);

void print_operation_system_name();

void move_cursor_to_new_line();

void shift_screen_to_up(int number);

void enter();

void  backspace();

void screen_start();

#endif
