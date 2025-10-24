#ifndef DRIVERS_KEYBOARD_H
#define DRIVERS_KEYBOARD_H

#include "ports.h"
#include "graphics.h"

#include "../include/type.h"
#include "../include/bool.h"


bool escape_pressed = false;
bool backspace_pressed = false;
bool ctrl_pressed = false;
bool shift_pressed = false;
bool alt_pressed = false;
bool caps_pressed = false;


uint8_t array_key[][2] = {
    
    {' ', ' '},    // 0x00
    
    {' ', ' '},    // 0x01 ==> Escape
    
    {'1', '!'},    // 0x02
    {'2', '@'},    // 0x03 
    {'3', '#'},    // 0x04
    {'4', '$'},    // 0x05
    {'5', '%'},    // 0x06
    {'6', '^'},    // 0x07
    {'7', '&'},    // 0x08
    {'8', '*'},    // 0x09
    {'9', '('},    // 0x0A
    {'0', ')'},    // 0x0B
    {'-', '_'},    // 0x0C
    {'=', '+'},    // 0x0D
    
    {' ', ' '},    // 0x0E ==> Backspace
    
    {' ', ' '},    // 0x0F ==> Tab
    
    {'q', 'Q'},    // 0x10
    {'w', 'W'},    // 0x11
    {'e', 'E'},    // 0x12
    {'r', 'R'},    // 0x13
    {'t', 'T'},    // 0x14
    {'y', 'Y'},    // 0x15
    {'u', 'U'},    // 0x16
    {'i', 'I'},    // 0x17
    {'o', 'O'},    // 0x18
    {'p', 'P'},    // 0x19
    {'[', '{'},    // 0x1A
    {']', '}'},    // 0x1B
    
    {' ', ' '},    // 0x1C ==> Enter
    
    {' ', ' '},    // 0x1D ==> Ctrl
    
    {'a', 'A'},    // 0x1E
    {'s', 'S'},    // 0x1F
    {'d', 'D'},    // 0x20
    {'f', 'F'},    // 0x21
    {'g', 'G'},    // 0x22
    {'h', 'H'},    // 0x23
    {'j', 'J'},    // 0x24
    {'k', 'K'},    // 0x25
    {'l', 'L'},    // 0x26
    
    {';', ':'},    // 0x27
    
    {'\'', '"'},   // 0x28
    
    {'`', '~'},    // 0x29
    
    {' ', ' '},    // 0x2A ==> Shift left
    
    {'\\', '|'},   // 0x2B

    {'z', 'Z'},    // 0x2C
    {'x', 'X'},    // 0x2D
    {'c', 'C'},    // 0x2E
    {'v', 'V'},    // 0x2F
    {'b', 'B'},    // 0x30
    {'n', 'N'},    // 0x31
    {'m', 'M'},    // 0x32

    {',', '<'},    // 0x33
    {'.', '>'},    // 0x34
    {'/', '?'},    // 0x35

    {' ', ' '},    // 0x36 ==> Shift right

    {' ', ' '},    // 0x37 ==> Window
    
    {' ', ' '},    // 0x38 ==> Alt left
    
    {' ', ' '},    // 0x39 ==> Space

    {' ', ' '},    // 0x3A ==> Caps
};

void process_keyboard();

#endif
