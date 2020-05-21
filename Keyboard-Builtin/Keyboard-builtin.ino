include<Keyboard.h>

int x = 8;  // Set a button to pin 8
int y = 9;  // Set a button to pin 9
int z = 10;  // Set a button to pin 10

void setup()
{
  pinMode(x, INPUT);
  pinMode(y, INPUT);
  pinMode(z, INPUT);  
  digitalWrite(x, HIGH);
  digitalWrite(y, HIGH);
  digitalWrite(z, HIGH);  
}

void loop()
{
  if (digitalRead(x) == 0)  // if the button goes low
  {
    Keyboard.write('x');  // send a 'x' to the computer via Keyboard HID
    delay(100);  
  }
  if (digitalRead(y) == 0)  // if the button goes low
  {
    Keyboard.write('y');  // send a 'x' to the computer via Keyboard HID
    delay(100);  
  }
  if (digitalRead(z) == 0)  // if the button goes low
  {
    Keyboard.write('z');  // send a 'x' to the computer via Keyboard HID
    delay(100);  
  }
}
