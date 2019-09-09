int touch = A2; 
int red = 11; 
int green=10;
int blue=9;
int val = 0,change=0,brightness=0; 
void setup()
{
  pinMode(touch, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);//The baud rate is 9600
}
void led_off()//All lights are off
{
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
}
void loop()
{
  val = analogRead(touch); //Read the voltage value of port A2 and assign it to val
  Serial.println(val);
  if (val > 500)
  {
    switch(change)
  {  
    case 0 :analogWrite(red, brightness);break;
    case 1 :analogWrite(green, brightness);break;
    case 2 :analogWrite(blue, brightness);break;
    case 3 :analogWrite(red, brightness);analogWrite(green, brightness);analogWrite(blue, brightness);break;
  } 
      delay(5);
      if(brightness<255)
        brightness++;
  }
  else
  {
    if(brightness!=0)
    {
      change++;
      if(change == 4)
        change=0;
      brightness=0;
    }
    led_off();
  }  
}
