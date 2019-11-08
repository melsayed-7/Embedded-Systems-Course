int read_flame = A0;    
int led_pin = 9;      // select the pin for the LED
int sensor_value = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the led_pin as an OUTPUT:
  pinMode(led_pin, OUTPUT);
  pinMode(read_flame, INPUT);
  Serial.begin(9600);
}

void loop() {
  sensor_value = digitalRead(read_flame);

  if(sensor_value==HIGH)
  {
    digitalWrite(led_pin, HIGH);
  }
  else
  {
    digitalWrite(led_pin, LOW);
  }
}
