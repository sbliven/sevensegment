/* SevenSegment
 *
 * Demonstrates the SevenSegment library.
 *
 * Circut:
 * A common-anode 7-segment display.
 * Wire the Anode to VCC through a 1K resistor
 * Hook the other leads up to the Arduino, and modify the initialization line
 * accordingly.

 * Author: Spencer Bliven
 * License: Public Domain
 */
#include <SevenSegment.h>

// pins for top, topleft, bottomleft, bottom, bottomright, middle, topright
SevenSegment seg( 2,3,4,8,7,6,5 );

void setup() {
  // pin setup handled by SevenSegment initializer
}

void loop() {
  // Loop through all known digits (0-9, A-F, blank)
  for(int d=0;d<=LAST_NUM;d++) {
    seg.displayDigit(d);
    delay(500);
  }
}

// vi:syntax=c
