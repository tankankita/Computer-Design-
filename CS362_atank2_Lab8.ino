//RED1
int Ledred1 = 9;
int LedStatered1 = LOW;
int Buttonred1 = 8;
int currentbuttonstatered1 = LOW;
int prevbuttonstatered1 = LOW;

int red1=LOW;


//RED2
int Ledred2 = 10;
int LedStatered2 = LOW;
int Buttonred2 = 7;
int currentbuttonstatered2 = LOW;
int prevbuttonstatered2 = LOW;
int red2=LOW;
int rec=0;

//Blue 1
int Ledblue1 = 8;
int LedStateblue1 = LOW;
int buttonblue1 = 9;
int currentbuttonstateblue1 = LOW;
int prevbuttonstateblue1 = LOW;
int blue1=LOW;


void setup()
{
  Serial.begin(9600);
  
  pinMode(Buttonred1, INPUT);  
  pinMode(Buttonred2, INPUT);
  pinMode(buttonblue1, INPUT);

  
  pinMode(Ledred1, OUTPUT); 
  pinMode(Ledred2, OUTPUT);
    pinMode(Ledblue1, OUTPUT);


  digitalWrite(Ledred1, LOW);
  digitalWrite(Ledred2, LOW);
  digitalWrite(Ledblue1, LOW);



  

}


void loop()
{
  currentbuttonstatered1 = digitalRead(Buttonred1);
  currentbuttonstatered2 = digitalRead(Buttonred2);
    currentbuttonstateblue1 = digitalRead(buttonblue1);



  if (currentbuttonstatered1 != prevbuttonstatered1 && currentbuttonstatered1  == HIGH)
  {
    Serial.write(0); 
    red1=HIGH;   
  }

if (currentbuttonstatered2 != prevbuttonstatered2 && currentbuttonstatered2  == HIGH)
  {
  Serial.write(1);
      red2=HIGH;   
  }


if (currentbuttonstateblue1 != prevbuttonstateblue1 && currentbuttonstateblue1  == HIGH)
  {
  Serial.write(2);
    Serial.println(2);

      blue1=HIGH;   
  }
  
 
  if ((Serial.available() > 0) )
  { 
      rec=Serial.read();
   //Serial.println("this is rec " +rec);
   //Serial.print(rec, BYTE); 
    if ( LedStatered1 == LOW && rec==0)
    {
      digitalWrite(Ledred1, HIGH);
      LedStatered1 = HIGH;
    }
     else if(LedStatered1 == HIGH && rec==0)
    {   
      digitalWrite(Ledred1, LOW);     
      LedStatered1 = LOW;
    }
     
     if(LedStatered2 == LOW && rec==1 )
    {
      digitalWrite(Ledred2, HIGH);
      LedStatered2 = HIGH;
    }

    else if(LedStatered2 == HIGH && rec==1)
    {
      digitalWrite(Ledred2, LOW);
      LedStatered2 = LOW;
    }

  if(LedStateblue1 == LOW && rec==2 )
    {
      digitalWrite(Ledblue1, HIGH);
      LedStateblue1 = HIGH;
    }

    else if(LedStateblue1 == HIGH && rec==2)
    {
      digitalWrite(Ledblue1, LOW);
      LedStateblue1 = LOW;
    }
    
   }
    
  prevbuttonstatered1 = currentbuttonstatered1;
  prevbuttonstatered2 = currentbuttonstatered2; 
  prevbuttonstateblue1 = currentbuttonstateblue1; 

 
}
