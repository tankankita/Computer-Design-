// Ankita Tank - 650388695

// Lab 9- Graphs using processing. Print the graph of any 2 analog read values simulatinously.

// Connect two analog devices to the arduino and plot the data received on the computer using processing.
// Data could be displayed in two separate graphs  or both on one graph .
// Some analog devices that you might already have include:
// potentiometer
// thermistor 
// photo resistor
// force sensitive resistor

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// NO ASSUMPTION

// References - where did you find code snippets, ideas, inspirations? if no references used say: "no references used"
// https://www.arduino.cc/en/Tutorial/Graph


void setup() 
{
// Set the serial monitor.
 Serial.begin(9600);
}

void loop() 
{

  // According to My thought process to print the readings to the serail motinor as a line
  // output of my analog reads would be in format "A0 A1"
  
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.print(analogRead(A1));
  Serial.println();
  delay(5);

  // In the proccessor, there would be 0.005 second of a delay so as to keep the data keep more running 
  // graphs showing more changes than ususal 1 sec delay.

}
