// Ankita Tank - 650388695

// Lab 7 - Count Down interrupts 
 
// Description - what is this code supposed to do?
// Write a program for the arduino that utilizes interrupts.
// When no button has been pressed your 16x2 display should say something like "We have been waiting for X seconds", where X will be updated as time goes on.
// When the first button is pressed, the display should display “Interrupt received! Press button 2 to continue”
// When the user presses button 2 the display goes back to displaying "We have been waiting for X seconds", and restarts the time a 0 seconds.

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// I Assumed that this could be done with out using interrupts which is much easier

// References - where did you find code snippets, ideas, inspirations? if no references used say: "no references used"
// https://www.arduino.cc/en/Reference/attachInterrupt
// https://www.youtube.com/watch?v=sF9zetmwRZ8
// https://www.youtube.com/watch?v=CRJUdf5TTQQ
// https://www.youtube.com/watch?v=C4kM16MKINA
// http://playground.arduino.cc/Code/Interrupts

#include<LiquidCrystal.h>

//Set up LCD
LiquidCrystal lcd(12,11,5,4,6,7);

// button set up below for both interrupts
const int Pin_stop = 3;
const int Pin_Resume = 2;

//Counter to check seconds
int seconds;

//Keep time in Milliseconds
unsigned long int Time_In_MilliSeconds;
int volatile Stop_pressed;


void setup()
{
  //Set up the lcd and pins
  Serial.begin(9600);
  lcd.begin(16,2); 

  //Enter 
  pinMode(Pin_stop,INPUT_PULLUP);
  pinMode(Pin_Resume,INPUT_PULLUP);
  
  //set the constant.
  Time_In_MilliSeconds =0;
  seconds=0;
  Stop_pressed=0;

  //Interrupt pins set to rising
  attachInterrupt(digitalPinToInterrupt(Pin_stop), Func_StopTimer, RISING);
  attachInterrupt(digitalPinToInterrupt(Pin_Resume), Func_ResumeTimer, RISING);
}


void loop()
{
  if(!Stop_pressed)
  {
    updatetime();
    
  }
  delay(200);
}


void Func_StopTimer()
{
  //Stop button has been pressed
  Stop_pressed=1;

  //Print To LCD
  lcd.clear();
  lcd.print("Stopped Timer");

  //Serial Print To Debug
  Serial.println("Your Timer Is Stopped");

}


void Func_ResumeTimer()
{
  //Resume button has been pressed
  //Set the Stop button to 0 
  Stop_pressed=0;

  //Set time in Milliseconds to compare with the counter
  Time_In_MilliSeconds=millis();

  //Serial Print To Debug
  Serial.println("Timer Resetted");
}


void updatetime()
{
  // Set a unsigned long int to the time we have in the seconds count down
  unsigned long int Current_Time_In_Milliseconds = millis()-Time_In_MilliSeconds;

  //if its not the same time
  // Clear LCD to print the seconds 
  // print to lcd the cpounter 
  if((Current_Time_In_Milliseconds/1000) !=seconds)
  {
    //Set seconds to the current time in seconds
    seconds=Current_Time_In_Milliseconds/1000;

    //print the second to the lcd.
    //Countdown timing 
    lcd.clear();
    lcd.print("Waiting for -> ");
    lcd.setCursor(0,1);
    lcd.print(seconds);
    lcd.print(" seconds.."); 
  }
}















