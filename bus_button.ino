//
//  bus_button.ino
//  http://github.com/yoggy/bus_button
//
int pin_beep = 11;
int pin_button = 12;
int pin_led = 13;

void setup() {
  pinMode(pin_beep, OUTPUT);
  pinMode(pin_button, INPUT_PULLUP);
  pinMode(pin_led, OUTPUT);
}

void loop() {
  if (read_button_status()) {
    digitalWrite(pin_led, HIGH);
    play_pinpong();
    delay(3000);
  }
  digitalWrite(pin_led, LOW);
}

bool read_button_status(){
  int val = digitalRead(pin_button);
  return (val == LOW) ? true : false;
}

void play_pinpong() {
  tone(pin_beep, 659, 500);  // E4
  delay(500);
  tone(pin_beep, 523, 500);  // C4
  delay(500);  
}

