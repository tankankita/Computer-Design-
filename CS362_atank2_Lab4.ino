// Ankita Tank - 650388695

// LAB 4 - Checking the Brightness using a Photoresistor

// Create a circuit and sketch that will use a photoresistor and the 16x2 display. 
// The display should state the relative amount of light in the room (dark, partially dark, medium, partially light, fully lit.) 
// in the room, or fully lit, or somewhere in between should be displayed based on the value read from the photocell. 
// This involves you determining the range of values the photoresistor provides and then making reasonable ranges for the values being considered.

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// NO ASSUMPTION 

// References - where did you find code snippets, ideas, inspirations? if no references used say: "no references used"
// https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll
// https://learn.adafruit.com/photocells
// http://playground.arduino.cc/Learning/PhotoResistor

#include <LiquidCrystal.h> 

int Photo_Resistor_Value = 0;

LiquidCrystal LCD(12, 11, 5, 4, 3, 2);


//Set up the LCD
void setup()
{
  LCD.begin(16, 2);
  Serial.begin(9600);
} 

void loop()
{
  int Brightness_Value = analogRead(Photo_Resistor_Value);
  LCD.setCursor(0, 0);
  Serial.println(Brightness_Value);

  // For if the room is Dark  
  // Range <100
  if (Brightness_Value < 100)
  {
    LCD.print("Dark " + String(Brightness_Value));
  }
  
  // For if the room is Partial Dark  
  // Range >100 but less than 330
  else if (Brightness_Value > 100 && Brightness_Value < 330)
  {
    LCD.print("P Dark " + String(Brightness_Value));
  }
  
  // For if the room is Meduim  
  // Range >330 but < 500
  else if (Brightness_Value > 330 && Brightness_Value <= 500)
  {
    LCD.print("Meduim " + String(Brightness_Value));
  }

  // For if the room is Partially lit  
  // Range <700 but greater than 500
  else if (Brightness_Value > 500 && Brightness_Value <= 700)
  {
    LCD.print("P Lit " + String(Brightness_Value));
  }
  
  // For if the room is Fully Lit  
  // Range < 1023 (max rangeof the photo resister reading) but > 700
  else if (Brightness_Value <= 1023 || Brightness_Value > 700)
  {
    LCD.print("Fully lit " + String(Brightness_Value));
  }
  
  delay(1000);
  LCD.clear();
}
