//Ankita Tank - 650388695

//Lab 6 - DD/MM/YY and TIME Display

// Description - what is this code supposed to do?
// Have your arduino get the date(mm/dd/yyyy) & time(hh/mm/ss) from the user via the serial monitor in the arduino software. 
// Date includes day , month and year
// Time includes hour,minutes and seconds
// You circuit/program should:
// print a prompt on the serial monitor,
// get input of date and time from user  
// display date  and time on the 16x2 display 
// keep accurate time on 16x2 display 
// include error checking for input that doesn't make sense (hours  not in range of 0 to 23, minutes not in range 0 to 59, month not range of 1 to 12, etc).

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// NO ASSUMPTIONS

// References - where did you find code snippets, ideas, inspirations? if no references used say: "no references used"
// https://www.arduino.cc/en/Reference/Serial#.UwYyzfldV8E
// ttps://www.arduino.cc/en/Serial/Available#.UwYy2PldV8E
// https://www.arduino.cc/en/Serial/ReadBytesUntil#.UwYy6_ldV8E 
// http://playground.arduino.cc/Code/Time#.UwYyQPldV8E
// https://www.pjrc.com/teensy/td_libs_Time.html
// https://github.com/hassanpasha5630/Arduino/blob/master/Lab6/sketch_oct19a/sketch_oct19a.ino  (This is wrong, I Just took bits and parts of the code) 


#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal.h>


//Global Varibles for the Time
int Hours;
int Min;
int Seconds_;

//Global Variables for the Date
int months;
int years;
int days;

//Prompt String in order for the user to Enter A Date and Time in a Specific Format
String Date = "Enter Date In The Following Format :  MM/DD/YYYY.";
String Time = "Enter Time In The Following Format :  HH/MM/SS      24Hour Clock.";

//Reading string for when the user inputs Data
String Date_Entered;
String Time_Entered;

LiquidCrystal LCD(12, 11, 5, 4, 3, 2);


//Set Up the LCD Screen Dimensions
void setup()
{
  LCD.begin(16, 2);
  Serial.begin(9660);
}


void loop()
{
  //Prompt for the Date first 
  Serial.println(Date);

  //Wait for while the date is entered, 
  while (1)
  {
    if (Serial.available() == 1)
    {
      break;
    }
  }


  //When the date is entered
  if (Serial.available() == 1)
  {
    //Store the Date
    //Check for the length of the Date string for if it is in the specified format.
    //If it is in the format, pass the date_string in the Check_Valid_Date to check for the bounds of the date and month.
    Date_Entered = Serial.readString();
    int size_Date = Date_Entered.length();
    Check_Valid_Date(Date_Entered);
    Serial.println(Date_Entered);


    //Invalid String entered, longer than necessary 
    if (size_Date > 10)
    {
      Serial.println("Not A Valid Day");
    }
  }

  //Prompt for the Time
  Serial.println(Time);

  //Wait while the user enters the time
  while (1)
  {
    if (Serial.available() == 1)
    {
      break;
    }
  }

  if (Serial.available() == 1)
  {  
    //After the user has Entered the Time, 
    //Strore the Time
    //Check if the Time entered by the user is in the correct format
    //pass the Time_String in the Check-Valid_Time function to check for the bounds of a 24 hour clock.
    Time_Entered = Serial.readString();
    Check_Valid_Time(Time_Entered);

    //Using the setTime function from Time.h (refere the Time library above in the headers)
    setTime(Hours, Min, Seconds_, days, months, years);
    clock();
    
    //Print the Valid time entered by the User
    Serial.print(Hours);
    Serial.print(" : ");
    Serial.print(Min);
    Serial.print(" : ");
    Serial.println(Seconds_);
  }
}


//Fucntion to check for the Valid Date, Check the bounds.
void Check_Valid_Date(String Date)
{
  //Local String variables to parse the Date String.
  String String_Month;
  String String_Day;
  String String_Year;


  //Parse the month and store it in the Global int w.r.t its info 
  String_Month = Date.substring(0, Date.indexOf("/"));
  months = String_Month.toInt();
  
 //Parse the Day and store it in the Global int w.r.t its info 
  String_Day = Date.substring(5, Date.indexOf("/") + 1);
  days = String_Day.toInt();

  //Parse the year and store it in the Global int w.r.t its info 
  String_Year = Date.substring(6);
  years = String_Year.toInt();


  //Checking for the  bounds of the ints entered.
  //Checkng for months if it is in the bound 1-12
  //If not, go back to teh loop() and prompt for the Date again
  if ((months > 12) || (months < 1))
  {
    Serial.println("Invalid Date. Try Again! ");
    loop();
  }


  //Check for the month with respect to the Date entered to see if it is in bound.
  //if it is, Ask for the Time,
  //if not valid, Ask for the Date again.
  else if ((months == 4) || (months == 6) || (months == 9) || (months == 11))
  {
    if ((days > 30) || (days < 1))
    {
      Serial.println("Invalid Date. Try Again! ");
      loop();
    }
  } 
  else if ((months == 1) || (months == 3) || (months == 5) || (months == 7) || (months == 8) || (months == 10) || (months == 12))
  {
    if ((days > 31) || (days < 1))
    {
      Serial.println("Invalid Date. Try Again! ");
      loop();
    }
  }
  else if (years % 4 == 0)
  {
    //leap year
    if (months == 2)
    {
      if (days > 29)
      {
        Serial.println("Invalid Date. Try Again! ");
        loop();
      }
    }
  }
  else if (months == 2)
  {
    if (days > 28)
    {
      Serial.println("Invalid Date. Try Again! ");
      loop();
    }
  }
}
void Check_Valid_Time(String Time_String_Userinput)
{
  String Hours_String;
  String Minutes_String;
  String Seconds_String;
  
  Hours_String = Time_String_Userinput.substring(0, Time_String_Userinput.indexOf("/"));
  Minutes_String = Time_String_Userinput.substring(5, Time_String_Userinput.indexOf("/") + 1);
  Seconds_String = Time_String_Userinput.substring(6);

  
  Hours = Hours_String.toInt();
  Min = Minutes_String.toInt();
  Seconds_ = Seconds_String.toInt();
  if ((Hours < 0) || (Hours > 23) || (Min < 0) || (Min > 59) || (Seconds_ < 0) || (Seconds_ > 59))
  {
    Serial.println("Invalid Time. Try Again !");
    Serial.println(Time);
    while (1)
    {
      if (Serial.available() == 1)
      {
        break;
      }
    }
    if (Serial.available() == 1)
    {
      Time_Entered = Serial.readString();
      Check_Valid_Time(Time_Entered);
      Serial.print(Hours);
      Serial.print(" : ");
      Serial.print(Min);
      Serial.print(" : ");
      Serial.println(Seconds_);
    }
  }
}
void clock()
{
  while (1)
  {
    time_t t = now();
    Serial.print(hour(t));
    Serial.print(minute(t));
    Serial.print(second(t));
    Serial.println();
    Serial.println(day(t));
    Serial.println(month(t));
    Serial.println(year(t));
    delay(1000);
    LCD.clear();
    Dates_Function(month(t), day(t), year(t));
    Time_Function(hour(t), minute(t), second(t));
  }
}
void Dates_Function(int m, int d, int y)
{
  LCD.setCursor(10, 0);
  LCD.print(y);
  LCD.setCursor(9, 0);
  LCD.print("/");
  LCD.setCursor(7, 0);
  LCD.print(d);
  LCD.setCursor(5, 0);
  LCD.print("/");
  LCD.setCursor(3, 0);
  LCD.print(m);
}


void Time_Function(int h, int m, int s)
{
  LCD.setCursor(10, 1);
  if (s < 10)
  {
    LCD.print("0");
  }
  LCD.print(s);
  LCD.setCursor(9, 1);
  LCD.print("/");
  LCD.setCursor(7, 1);
  LCD.print(m);
  LCD.setCursor(5, 1);
  LCD.print("/");
  LCD.setCursor(3, 1);
  LCD.print(h);
}
