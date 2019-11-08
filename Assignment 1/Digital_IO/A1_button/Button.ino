const int button_pin = 9;     
const int led_pin =  11;      

int button_state = 0;
int amp=127;
int timing=0;
void setup() {
  pinMode(button_pin, INPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {
  button_state = digitalRead(button_pin);
  if(button_state == HIGH && timing < 15 && amp<=255) 
    {
	analogWrite(led_pin, amp);
    }
  else if (button_state == HIGH && timing>15 && amp<=255) 
  {
    analogWrite(led_pin, amp);
    amp=amp+16;
  } 
  else if(amp>255 && button_state == HIGH)
  {
    analogWrite(led_pin, 0);
  }
  else if(button_state == LOW)
  {
    analogWrite(led_pin, 0);
    timing=0;
    amp=255;

  }
  timing=timing+1;
  delay(200);
}
