/* Arduino USB Keyboard HID demo
 * Volume+/Volume-/Mute keys
 */

uint8_t buf[8] = { 
  0 };   /* Keyboard report buffer */

#define PIN_VOLUME_UP 5
#define PIN_VOLUME_DOWN 6
#define PIN_MUTE 7

int state = 1;

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_VOLUME_UP, INPUT);
  pinMode(PIN_VOLUME_DOWN, INPUT);
  pinMode(PIN_MUTE, INPUT);
  // enable internal pull-ups
  digitalWrite(PIN_VOLUME_UP, 1); 
  digitalWrite(PIN_VOLUME_DOWN, 1); 
  digitalWrite(PIN_MUTE, 1); 

  delay(200);
}

void loop() 
{
  state = digitalRead(PIN_VOLUME_UP);
  if (state != 1) {
    buf[2] = 128;   // Volume up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_VOLUME_DOWN);
  if (state != 1) {
    buf[2] = 129;   // Volume down key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_MUTE);
  if (state != 1) {
    buf[2] = 127;   // Mute key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
}
