// Ankita Tank - 650388695

// Lab 3 - Scrolling Text LCD 

// Display your name and your favorite quote appear on the 16x2 display, name on first line and quote on the second line. 
// The quote should not all fit on the screen and so should scroll across the screen. Your name should not scroll across the screen, only the quote should scroll.  
// Hint: I recommend writing your own scrolling, rather than using the library methods.

// References - https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//Dimensions of the LCD Screen
int Width = 16;
int Height = 2;

//Pointing the cursor at the bit
int StartCursor=0;
int EndCursor = 0;

//MAX Length of the cursor = Width of the LCD Screen
int Moving_Cursor = Width;

//The Quote and my Name.
String str1 = " orange to pink ";
String t1=" Transfer";
String str2 = " orange to red";

String t2="NO Transfer";
void setup() 
{
  lcd.begin(Width,Height); 
  lcd.print(str2);
  lcd.setCursor(0,1);
   lcd.print(t1);
   

}

void loop() 
{
  
  
  
  
  
  

  //For scrolling effect move keep the cursor going
  
}

