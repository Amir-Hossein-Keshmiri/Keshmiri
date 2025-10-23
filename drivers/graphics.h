#ifndef DRIVERS_GRAPHICS_H
#define DRIVERS_GRAPHICS_H

#include "ports.h"

#include "../include/type.h"
#include "../include/bool.h"
#include "../include/symbols.h"

#define VIDEO_MEMORY_ADDRESS                 0xB8000

#define SCREEN_WIDTH                         0x50       // 80
#define SCREEN_HEIGHT                        0x19       // 25

#define REG_SCREEN_CTRL                      0x3D4
#define REG_SCREEN_DATA                      0x3D5

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
#define BACKGAROUNDE_COLOR_LIGHT_GREEN       0xA0
#define BACKGAROUNDE_COLOR_LIGHT_CYAN        0xB0
#define BACKGAROUNDE_COLOR_LIGHT_RED         0xC0
#define BACKGAROUNDE_COLOR_LIGHT_MAGENTA     0xD0
#define BACKGAROUNDE_COLOR_LIGHT_YELLOW      0xE0
#define BACKGAROUNDE_COLOR_WHITE             0xF0

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
#define TEXT_COLOR_LIGHT_GREEN               0x0A
#define TEXT_COLOR_LIGHT_CYAN                0x0B
#define TEXT_COLOR_LIGHT_RED                 0x0C
#define TEXT_COLOR_LIGHT_MAGENTA             0x0D
#define TEXT_COLOR_LIGHT_YELLOW              0x0E
#define TEXT_COLOR_WHITE                     0x0F

#define OPERATION_SYSTEM_NAME                "Keshmiri"

#define OPERATION_SYSTEM_NAME_SIZE           ((sizeof(OPERATION_SYSTEM_NAME) / sizeof(uint8_t)) + 0x03)

#define COMMAND_SIZE                         (SCREEN_WIDTH - OPERATION_SYSTEM_NAME_SIZE)


uint8_t *video_memory = (uint8_t *) VIDEO_MEMORY_ADDRESS;

uint32_t starting_point_of_command = 0;


uint32_t get_cursor();

void set_cursor(uint32_t input_cursor);

uint32_t get_cursor_row();

uint32_t get_cursor_column();

void clear_screen();

void print_character(uint8_t character, uint8_t color_character);

void print_string(const uint8_t *string, uint8_t text_color);

void print_operation_system_name();

void move_cursor_to_new_line();

#endif
