// Ankita Tank
// CS362

// This program takes ASCII-encoded strings
// from the serial port at 9600 baud and graphs them. It expects values in the
// range 0 to 1023, followed by a newline, or newline and carriage return

// Created 20 Apr 2005
// Updated 24 Nov 2015
// by Tom Igoe
// This example code is in the public domain.

import processing.serial.*;

Serial myPort;        // The serial port
int xPos = 1;         // horizontal position of the graph
float inByte = 0;
float inByte2 = 0;

void setup () {
  // set the window size:
  size(400, 300);

  // List all the available serial ports
  // if using Processing 2.1 or later, use Serial.printArray()
 //println(Serial.list());

  // I know that the first port in the serial list on my mac
  // is always my  Arduino, so I open Serial.list()[0].
  // Open whatever port is the one you're using.
  myPort = new Serial(this, Serial.list()[1], 9600);

  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');

  // set inital background:
  background(0);
}
void draw () {
  // draw the line for the inByte reading which is Analog 0:

  stroke(127, 34, 255);
      line(xPos, height, xPos, height - inByte);

 // draw the line for the inByte2 reading which is Analog 1:
  stroke(255, 34, 255);
      line(xPos, height, xPos, height - inByte2);
      
  // at the edge of the screen, go back to the beginning:
  if (xPos >= width) {
    xPos = 0;
    background(0);
  } else {
    // increment the horizontal position:
    xPos++;
  }
}


void serialEvent (Serial myPort) {
  // get the ASCII string from the seral monitor for reading from analog 0:
  String inString = myPort.readStringUntil(' ');
  
  // get the ASCII string from the seral monitor for reading from analog 1:
  String inString2 = myPort.readStringUntil('\n');

  if (inString != null) {
    // trim off any whitespace:
    inString = trim(inString);
    // convert to an int and map to the screen height:
    inByte = float(inString);
    println(inByte);
    inByte = map(inByte, 0, 1023, 0, height);
  }
  
  if (inString2 != null) {
    // trim off any whitespace:
    inString2 = trim(inString2);
    // convert to an int and map to the screen height:
    inByte2 = float(inString2);
    println(inByte2);
    inByte2 = map(inByte, 0, 1023, 0, height);
  }
}