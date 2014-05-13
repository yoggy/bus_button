//
//  bus_button.ino
//  http://github.com/yoggy/bus_button
//
int pin_beep = 9;
int pin_button = 12;
int pin_led = 13;

int count = 0;

void setup() {
  pinMode(pin_beep, OUTPUT);
  pinMode(pin_button, INPUT_PULLUP);
  pinMode(pin_led, OUTPUT);
}

void loop() {
  if (read_button_status()) {
    count ++;
    if (count == 4) {
      play_1up();
      count = 0;
    }
    else {
      play_pingpong();
    }
  }
  digitalWrite(pin_led, LOW);
}

bool read_button_status(){
  int val = digitalRead(pin_button);
  return (val == LOW) ? true : false;
}

// see also... http://arduino.cc/en/Tutorial/Tone
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_D6  1175
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_G6  1568
#define NOTE_A6  1760
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_D7  2349
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_G7  3136
#define NOTE_A7  3520
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_D8  4699

#define play_beep(f,t) {tone(pin_beep, f, t); delay(t);}

void play_pingpong() {
  int t = 500;
  digitalWrite(pin_led, HIGH);
  play_beep(NOTE_E5, t);
  play_beep(NOTE_C5, t);
  delay(3000);
}

void play_1up() {
  int t = 120;
  digitalWrite(pin_led, HIGH);
  play_beep(NOTE_E6, t);
  play_beep(NOTE_G6, t);
  digitalWrite(pin_led, LOW);
  play_beep(NOTE_E7, t);
  play_beep(NOTE_C7, t);
  digitalWrite(pin_led, HIGH);
  play_beep(NOTE_D7, t);
  play_beep(NOTE_G7, t);

  for (int i = 0; i < 10; ++i) {
    digitalWrite(pin_led, LOW);
    delay(t*2);
    digitalWrite(pin_led, HIGH);
    delay(t*2);
  }  
}

