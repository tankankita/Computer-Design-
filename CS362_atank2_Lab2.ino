// Ankita Tank - 650388695

// Lab 2 - 2 Buttons functioning With 3 LEDs

// Description:
// Use two switches and three LEDs for this circuit. One switch will increment a 3-bit count, and the other switch should decrement the 3-bit count. 
// The 3-bit count will be displayed on the three LEDs in binary (a 1 is LED on).
// Your lights should increment (or decrement) by one each time the switch is pressed. 
// If we continually depress the switch, the lights should not run up (or down) to 7 (or 0) (i.e. it should only change the value once per button press).
// Also document what happens when you reach 7 and/or 0.

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// NO Assumptions 

// References - https://www.arduino.cc/en/Tutorial/Button


//LED PINS
int led1 = 13;
int led2 = 12;
int led3 = 11;

//BUTTONPINS  
int buttonIncrement = 8;
int buttonDecrement = 8;

//COUNTER TO KEEP A TRACK OF BITS
int counter = 0;

//CHECK THE STATE OF THE BUTTON 
//INITIALIZED LOW AT THE BEGINNING
int buttonIncrementPressed = LOW;
int buttonDecrementPressed = LOW;

void setup()
{
  //INITIALIZE LED TO OUTPUT
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
Serial.begin(9600);
  //INITIALIZE THE BUTTON FOR INPUT
  pinMode(buttonIncrement, INPUT);
  pinMode(buttonDecrement, INPUT);
}

void loop()
{

  int ButtonIncr;
  int ButtonDcr;
  int ledState1;
  int ledState2;
  int ledState3;

  //STORING THE STATE OF LEDS
  ledState1 = digitalRead(led1);
  ledState2 = digitalRead(led2);
  ledState3 = digitalRead(led3);

  //STORING THE STATE OF THE BUTTONS
  ButtonIncr = digitalRead(buttonIncrement);
   Serial.print(ButtonIncr);
  ButtonDcr = digitalRead(buttonDecrement);

  //IF EITHER OF THE BUTTONS ARE PRESSED,
  //RECORD THE COUNTER VALUE AND PERFORM ACCORDINGLY
  
  if (ButtonDcr != buttonDecrementPressed || ButtonIncr != buttonIncrementPressed)
  {
    if (ButtonIncr == HIGH)
    {
      Serial.print("7 pressed");
      counter++;
    }
    if (ButtonDcr == HIGH)
    {
            Serial.print("8 pressed");

      counter--;
    }

    if (counter == 0)
    {
      //COUNTER VALUE      => 0
      //COUNTER IN BITS    => 0    0    0
      //BIT REPRESENTATION => LOW LOW LOW
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }

    else if (counter == 1)
    {
      //COUNTER VALUE     => 1
      //COUNTER IN BITS    => 0    0    1
      //BIT REPRESENTATION => LOW LOW HIGH
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }

    else if (counter == 2)
    {
      //COUNTER VALUE      => 2
      //COUNTER IN BITS    => 0    1    0
      //BIT REPRESENTATION => LOW HIGH LOW
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
    }

    else if (counter == 3)
    {
      //COUNTER VALUE      => 3
      //COUNTER IN BITS    => 0    1    1
      //BIT REPRESENTATION => LOW HIGH HIGH
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
    }

    else if (counter == 4) 
    {
      //COUNTER VALUE      => 4
      //COUNTER IN BITS    => 1    0    0
      //BIT REPRESENTATION => HIGH LOW LOW
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
    }

    else if (counter == 5) 
    {
      //COUNTER VALUE      => 5
      //COUNTER IN BITS    => 1    0    1
      //BIT REPRESENTATION => HIGH LOW HIGH
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
    }

    else if (counter == 6) 
    {
      //COUNTER VALUE      => 6
      //COUNTER IN BITS    => 1    1    0
      //BIT REPRESENTATION => HIGH HIGH LOW
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    }

    else if (counter == 7)
    {
      //COUNTER VALUE      => 7
      //COUNTER IN BITS    => 1    1    1
      //BIT REPRESENTATION => HIGH HIGH HIGH
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    }

    //UNVALID --> SET IT TO '0'
    else if (counter < 0 || counter > 7)
    {
      counter = 0;
    }
  }
  buttonIncrementPressed = ButtonIncr;
  buttonDecrementPressed = ButtonDcr;
}
