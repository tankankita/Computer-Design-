// Ankita Tank - 650388695

// Lab 5- Buzzer voice using potientiometer and light LED according to the photoresistor reading

// Description - what is this code supposed to do?
// This lab we will be experimenting with multiple inputs and outputs.  
// There will be two parts:
// 1) You will be using 4 LEDS and a photoresistor.  
// Put all 4 LEDs next to each (preferably the same color).  
// As the amount of light seen by the photoresistor decreases, increase the number of LEDs that are lit.  
// For example, if your circuit receives no light then all of the LEDs should light up.  
// As you continue to increase the amount of light, the number of LEDs that light up will decrease.  
// So when the photoresistor receives the half the amount of light, 2 LEDS should be lit up, and when there is no light, all 4 LEDs should be lit up.
// 2) In parallel with part 1, you will be using the the passive buzzer and the potentiometer.  
// Use the potentiometer as an analog input and have the output come from another analog pin.  
// Control the volume of the buzzer by adjusting the potentiometer.  
// Make sure to have code to control the output of the buzzer based on the potentiometer.

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// Assumed that potentiometer and photoresistor would give out readings in parallel and will not interupt the output while one is in process.

// References - where did you find code snippets, ideas, inspirations? if no references used say: "no references used"
// https://www.arduino.cc/en/Reference/AnalogWrite
// https://www.arduino.cc/en/Reference/Map
// https://www.arduino.cc/en/Reference/AnalogRead

// Pins each components are attached to
// potentiometer connected to analog pin 1
// Buzzer connected to PWD pin 5

int buzz = 5;
int potentiometer = 1;

int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;

int potenoutput = 0;
int photoresistor = 0;

void setup() 
 {
  // Set up Pinmode for all the components  
   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
   pinMode(led4,OUTPUT);
   
   // sets the pin as output
   pinMode(buzz,OUTPUT);
   
   pinMode(potentiometer, INPUT);
   pinMode(photoresistor, INPUT);
   
   Serial.begin(9600);  
 }
void loop() 
 {
    // Record the reading from the photoresistor
   int show = analogRead(photoresistor); 

    // Record the reading from the potentiometer
    potenoutput = analogRead(potentiometer);

   // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
    analogWrite(buzz, potenoutput/4);
  
    // Reading from the Potentiometer
    // range 0 to 50 if the room is dark
     if (show < 50)
     {
         digitalWrite(led1, HIGH);
         digitalWrite(led2, HIGH);
         digitalWrite(led3, HIGH);
         digitalWrite(led4, HIGH);     
     }
     // Reading from the Potentiometer
    // range 50 to 200 if the room is partially dark
      else if (show >= 50 && show < 200)
     {
         digitalWrite(led1, HIGH);
         digitalWrite(led2, HIGH);
         digitalWrite(led3, HIGH);
         digitalWrite(led4, LOW);
      }
   // Reading from the Potentiometer
    // range 200 to 500 if the room is partially lit
    else if (show >=  200 && show < 500)
     {
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
       digitalWrite(led3, LOW);
       digitalWrite(led4, LOW);  
     }
     // Reading from the Potentiometer
    // range 500 to 800 if the room is Normal bright 
    else if (show > 500 && show < 800)
    {
         digitalWrite(led1, HIGH);
         digitalWrite(led2, LOW);
         digitalWrite(led3, LOW);
         digitalWrite(led4, LOW);        
    }
     // Reading from the Potentiometer
    // range 800 to 1023 if the room is complete Bright
    else if (show > 800 && show < 1023 )
    {
          digitalWrite(led1, LOW);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
          digitalWrite(led4, LOW);
      }  
 }

    

