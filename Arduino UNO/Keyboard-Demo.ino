  /* Arduino USB Keyboard HID demo
 * a/b/c Keys
 */

uint8_t buf[8] = { 
  0 };  /* Keyboard report buffer */

#define A 5
#define B 6
#define C 7

int state = 1;

void setup() 
{
  Serial.begin(9600);

  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  // Enable internal pull-ups
  digitalWrite(A, 1); 
  digitalWrite(B, 1);
  digitalWrite(C, 1); 

  delay(200);
}

void loop() 
{
  state = digitalRead(A);
  if (state != 1) {
    
    buf[2] = 0x04;    // Letter a
   
    Serial.write(buf, 8); // Ssend keypress
    releaseKey();
  } 

  state = digitalRead(B);
  if (state != 1) {
    
    buf[2] = 0x05;    // Letter b
    
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(C);
  if (state != 1) {
    
    buf[2] = 0x06;    // Letter c
    
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
  delay(500);
}
