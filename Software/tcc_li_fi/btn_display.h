#ifndef btn_display_h
#define btn_display_h

#include <LiquidCrystal.h>

// columns supported by the hardware
#define DISPLAY_COLUMNS 16

// lines supported by the hardware
#define DISPLAY_LINES 2

// a mesaage can have the same number of chars as the display, plus the null character
#define MESSAGE_LINE_SIZE DISPLAY_COLUMNS + 1

// the cursor can be shown on all of the display columns, counting from zero
#define CURSOR_POS_COL_MAX DISPLAY_COLUMNS - 1

// the minimum column position for the cursor
#define CURSOR_POS_COL_MIN 0

// the cursor can be shown on all of the display lines, counting from zero
#define CURSOR_POS_ROW_MAX DISPLAY_LINES - 1

// the minimum line position for the cursor
#define CURSOR_POS_ROW_MIN 0

// maximun printable char value from the ACII table (32 = ~)
#define VALID_CHAR_MAX 126

// manimun printable char value from the ACII table (32 = Space)
#define VALID_CHAR_MIN 32

// time to wait (milliseconds) on edit mode, after the last command was entered, to enable display blinking
#define EDIT_BLINK_DEBOUNCE 1000u

// time to wait (milliseconds) before reading the next instruction
#define BTN_DEBOUNCE 200

// define a macro for each button
#define BTN_RIGHT  0
#define BTN_UP     1
#define BTN_DOWN   2
#define BTN_LEFT   3
#define BTN_SELECT 4
#define BTN_NONE   5


static LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // select the pins used on the LCD panel
static boolean editMessage = false;
static unsigned long lastCommand = 0u;
static signed int cursorCol = 0, cursorRow = 0;
static char displayMessage[DISPLAY_LINES][MESSAGE_LINE_SIZE];

#endif
