/* Arduino USB Keyboard HID demo
 * Cut/Copy/Paste Keys
 */

#define KEY_LEFT_CTRL  0x01
#define KEY_LEFT_SHIFT  0x02
#define KEY_RIGHT_CTRL  0x10
#define KEY_RIGHT_SHIFT 0x20

uint8_t buf[8] = { 
  0 };  /* Keyboard report buffer */

#define PIN_COPY 5
#define PIN_CUT 6
#define PIN_PASTE 7

int state = 1;

void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_COPY, INPUT);
  pinMode(PIN_CUT, INPUT);
  pinMode(PIN_PASTE, INPUT);
  // Enable internal pull-ups
  digitalWrite(PIN_COPY, 1); 
  digitalWrite(PIN_CUT, 1);
  digitalWrite(PIN_PASTE, 1); 

  delay(200);
}

void loop() 
{
  state = digitalRead(PIN_CUT);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL;   // Ctrl
    buf[2] = 27;    // Letter X
    // buf[2] = 123;    // Cut key: Less portable
    Serial.write(buf, 8); // Ssend keypress
    releaseKey();
  } 

  state = digitalRead(PIN_COPY);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL;   // Ctrl
    buf[2] = 6;    // Letter C
    // buf[2] = 124;    // Copy key: Less portable
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_PASTE);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL;   // Ctrl
    buf[2] = 25;    // Letter V
    // buf[2] = 125;    // Paste key: Less portable
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
