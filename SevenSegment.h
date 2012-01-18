/* SevenSegment.h
 *
 * Provides support for driving a seven-segment display directly from the
 * Arduino. This requires 7 pins, but doesn't need a separate controller chip
 * like a MAX7221.
 *
 * Author: Spencer Bliven
 * License: Public Domain
 *
 */
#ifndef SEVEN_SEGMENT
#define SEVEN_SEGMENT

#include "Arduino.h" // For pre-1.0, use "WProgram.h"


// Macros for some non-numeric digits which can be displayed
#define A_NUM 10
#define B_NUM 11
#define C_NUM 12
#define D_NUM 13
#define E_NUM 14
#define F_NUM 15
#define OFF_NUM 16
#define LAST_NUM OFF_NUM

// What to display if there's an error
#define ERROR_NUM E_NUM

// Number of segments to display
#define SEGMENTS 7

class SevenSegment
{
    public:
        SevenSegment(int top, int topleft, int bottomleft, int bottom,
                int bottomright, int middle, int topright);
        ~SevenSegment() {}
        void displayDigit(int d);
    private:
        int _segPins[SEGMENTS];
};

#endif SEVEN_SEGMENT

