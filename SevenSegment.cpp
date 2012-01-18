/* SevenSegment.cpp
 *
 * Author: Spencer Bliven
 * License: Public Domain
 */
#include "Arduino.h" // For pre-1.0, use "WProgram.h"
#include "SevenSegment.h"


// Character table
const int numTable[][SEGMENTS] = {
  {  LOW,  LOW,  LOW,  LOW,  LOW, HIGH,  LOW}, //0
  { HIGH, HIGH, HIGH, HIGH,  LOW, HIGH,  LOW}, //1
  {  LOW, HIGH,  LOW,  LOW, HIGH,  LOW,  LOW}, //2
  {  LOW, HIGH, HIGH,  LOW,  LOW,  LOW,  LOW}, //3
  { HIGH,  LOW, HIGH, HIGH,  LOW,  LOW,  LOW}, //4
  {  LOW,  LOW, HIGH,  LOW,  LOW,  LOW, HIGH}, //5
  {  LOW,  LOW,  LOW,  LOW,  LOW,  LOW, HIGH}, //6
  {  LOW, HIGH, HIGH, HIGH,  LOW, HIGH,  LOW}, //7
  {  LOW,  LOW,  LOW,  LOW,  LOW,  LOW,  LOW}, //8
  {  LOW,  LOW, HIGH, HIGH,  LOW,  LOW,  LOW}, //9
  {  LOW,  LOW,  LOW, HIGH,  LOW,  LOW,  LOW}, //A
  { HIGH,  LOW,  LOW,  LOW,  LOW,  LOW, HIGH}, //b
  {  LOW,  LOW,  LOW,  LOW, HIGH, HIGH, HIGH}, //C
  { HIGH, HIGH,  LOW,  LOW,  LOW,  LOW,  LOW}, //d
  {  LOW,  LOW,  LOW,  LOW, HIGH,  LOW, HIGH}, //E
  {  LOW,  LOW,  LOW, HIGH, HIGH,  LOW, HIGH}, //F
  { HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH} //Off
};

SevenSegment::SevenSegment(int top, int topleft, int bottomleft, int bottom,
        int bottomright, int middle, int topright)
{
    _segPins[0] = top;
    _segPins[1] = topleft;
    _segPins[2] = bottomleft;
    _segPins[3] = bottom;
    _segPins[4] = bottomright;
    _segPins[5] = middle;
    _segPins[6] = topright;

    for(int i=0;i<SEGMENTS;i++) {
        pinMode(_segPins[i],OUTPUT);
    }
}

void SevenSegment::displayDigit(int d) {
  if(d<0 || d>LAST_NUM) {
    d= ERROR_NUM; //E for error
  }
  for(int seg=0;seg<SEGMENTS;seg++) {
    digitalWrite(_segPins[seg],numTable[d][seg]);
  }
}
