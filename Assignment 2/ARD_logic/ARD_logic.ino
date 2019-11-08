

const int trigger = 5; // PWM trigger
const int echo=3;// PWM Output 0-25000US,Every 50US represent 1cm
long duration; // defines variables
float distance;
int input;

// the pen numbers of the leds
int RED=11;
int GREEN=10;
int BLUE=9;
int YELLOW=8;


void setup()
{
 
  pinMode(trigger, OUTPUT); //Sets the trigger as an Output 
  pinMode(RED, OUTPUT); 
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT); 
  pinMode(YELLOW, OUTPUT); 
  
  pinMode(echo, INPUT); // Sets the echopin as an Input
  Serial.begin(9600); //configure baud rate of Serial communication to 9600 bps
}
void loop()
{
  digitalWrite(trigger, LOW); //Clears the triggerpen
  delayMicroseconds(2); // Sets the triggerpen on HIGH state for 10 micro seconds
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  duration=pulseIn(echo,HIGH);// Reads the echopin, returnsthe sound wave travel time in microseconds
  distance= duration*0.034/1050.0;//i got this formula by trying to map the potentiometer readings with the distance range;
  input=analogRead(A0);
  
  Serial.print("Distance Measured="); // Prints the distance on the Serial Monitor
  Serial.print(distance);
  Serial.println("cm");
  
  if (distance==2)
  {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);
    digitalWrite(YELLOW, HIGH);
    Serial.println("2 Cm High"); 
    Serial.println("1.5 Cm High");
    Serial.println("1 Cm High"); 
    Serial.println(".5 Cm High"); 
  }
  else if (distance>1.5)
  {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);
    digitalWrite(YELLOW, HIGH);
    Serial.println("2 Cm LOW"); 
    Serial.println("1.5 Cm High");
    Serial.println("1 Cm High"); 
    Serial.println(".5 Cm High"); 

  }
  else if (distance>1.0)
  {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
    digitalWrite(YELLOW, HIGH);
    Serial.println("2 Cm LOW"); 
    Serial.println("1.5 Cm LOW");
    Serial.println("1 Cm High"); 
    Serial.println(".5 Cm High"); 

  }
  else if (distance>.5)
  {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(YELLOW, HIGH);
    Serial.println("2 Cm LOW"); 
    Serial.println("1.5 Cm LOW");
    Serial.println("1 Cm LOW"); 
    Serial.println(".5 Cm High"); 
  }
  else if (distance<=.5)
  {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
    digitalWrite(YELLOW, LOW);
    Serial.println("2 Cm LOW"); 
    Serial.println("1.5 Cm LOW");
    Serial.println("1 Cm LOW"); 
    Serial.println(".5 Cm LOW"); 
  }


}
