#include "btn_display.h"

static void updateCursor() {

    if (cursorCol > CURSOR_POS_COL_MAX) {
        cursorCol = CURSOR_POS_COL_MIN;
        cursorRow++;
    } else if (cursorCol < CURSOR_POS_COL_MIN) {
        cursorCol = CURSOR_POS_COL_MAX;
        cursorRow--;
    }

    if (cursorRow > CURSOR_POS_ROW_MAX) {
        cursorRow = CURSOR_POS_ROW_MIN;
    } else if (cursorRow < CURSOR_POS_ROW_MIN) {
        cursorRow = CURSOR_POS_ROW_MAX;
    }

    lcd.setCursor(cursorCol, cursorRow);
}

static int readLCDButtons() {

    int keyInput = analogRead(0); // read the value from the sensor
    int pressedKey;

    // the buttons, when read, are centered at these values: 0, 148, 377, 601, 937
    // add approx 50 to those values and check if the input is close

    if (keyInput > 1000) {
        // this is the first option for speed, since it's the most likely result
        pressedKey = BTN_NONE;
    } else if (keyInput < 50) {
        pressedKey = BTN_RIGHT;
    } else if (keyInput < 250) {
        pressedKey = BTN_UP;
    } else if (keyInput < 450) {
        pressedKey = BTN_DOWN;
    } else if (keyInput < 650) {
        pressedKey = BTN_LEFT;
    } else if (keyInput < 950) {
        pressedKey = BTN_SELECT;
        while (analogRead(0) < 950) {
            ;
        }
    } else {
        // default output (keyInput > 950 && keyInput < 1000)
        pressedKey = BTN_NONE;
    }

    return pressedKey;
}

static void controlCursor() {

    int pressedKey = readLCDButtons();

    switch (pressedKey) {
    case BTN_RIGHT:
        cursorCol++;
        break;
    case BTN_LEFT:
        cursorCol--;
        break;
    case BTN_UP:
        cursorRow--;
        break;
    case BTN_DOWN:
        cursorRow++;
        break;
    case BTN_SELECT:
        editMessage = true;
        break;
    case BTN_NONE:
    default:
        cursorRow = cursorRow; // do nothing
        break;
    }

    updateCursor();
}

static void writeLCDMessage() {
    unsigned char line;
    for (line = 0u; line < DISPLAY_LINES; line++) {
        lcd.setCursor(0, line);
        lcd.write(displayMessage[line]);
    }
}

static void updateMessage(char newLetter) {

    if (newLetter < VALID_CHAR_MIN) {
        newLetter = VALID_CHAR_MAX;
    } else if (newLetter > VALID_CHAR_MAX) {
        newLetter = VALID_CHAR_MIN;
    }

    displayMessage[cursorRow][cursorCol] = newLetter;
    writeLCDMessage();
}

static void controlMessage() {

    int pressedKey = readLCDButtons();
    char currentLetter = displayMessage[cursorRow][cursorCol];

    switch (pressedKey) {
    case BTN_UP:
        currentLetter++;
        lastCommand = millis();
        break;
    case BTN_DOWN:
        currentLetter--;
        lastCommand = millis();
        break;
    case BTN_SELECT:
        editMessage = false;
        lastCommand = 0;
        break;
    default:
        currentLetter = currentLetter; // do nothing
        break;
    }

    if (millis() > lastCommand + EDIT_BLINK_DEBOUNCE) {
        lcd.clear();
        displayCleared = millis();
    }

    if (millis() > displayCleared + BTN_DEBOUNCE) {
        updateMessage(currentLetter);
        updateCursor();
    }
}

static void loadDefaultMessage() {
    char firstLine[MESSAGE_LINE_SIZE] = "Testing li-fi wi";
    char secondLine[MESSAGE_LINE_SIZE] = "th two Arduino's";
    unsigned char i;

    for (i = 0; i < MESSAGE_LINE_SIZE; i++) {
        displayMessage[0][i] = firstLine[i];
        displayMessage[1][i] = secondLine[i];
    }
}

static void translateMessageToDisplay(unsigned char * message, unsigned char messageSize) {

    unsigned char i, line, col;

    for (i = 0; i < messageSize && message[i] != '\0'; i++) {
        line = i / DISPLAY_COLUMNS;
        col = i % DISPLAY_COLUMNS;
        displayMessage[line][col] = (char) message[i];
        displayMessage[line][col + 1] = '\0';
    }
}

void displayTextMessage(unsigned char * message, unsigned char messageSize) {
    translateMessageToDisplay(message, 33u);
    writeLCDMessage();
}

void translateDisplayMessage(unsigned char * message, unsigned char messageSize) {

    int i, j, k = 0;

    for (i = 0; i < DISPLAY_LINES; i++) {
        for (j = 0; j < MESSAGE_LINE_SIZE && displayMessage[i][j] != '\0'; j++) {
            if (k < messageSize) {
                message[k++] = (unsigned char) displayMessage[i][j];
            }
        }
    }

    if (k < messageSize) {
        message[k] = '\0';
    } else {
        message[messageSize - 1] = '\0';
    }
}

void enableDisplayControl() {

    if (editMessage) {
        controlMessage();
    } else {
        controlCursor();
    }

    if (millis() > cursorHidden + BTN_DEBOUNCE) {
        lcd.cursor();
        cursorShown = millis();
    }

    if (millis() > cursorShown + BTN_DEBOUNCE) {
        lcd.noCursor();
        cursorHidden = millis();
    }
}

void setupDisplay(boolean showDefaultMessage) {
    lcd.begin(DISPLAY_COLUMNS, DISPLAY_LINES); // start the library
    if (showDefaultMessage) {
        loadDefaultMessage();
        writeLCDMessage();
    }
}
