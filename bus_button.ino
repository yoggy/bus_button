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
    if (count % 21 == 0) {
      play_phrase4();
    }
    else if (count % 11 == 0) {
      play_phrase3();
    }
    else if (count % 7 == 0) {
      play_phrase2();
    }
    else if (count % 3 == 0) {
      play_phrase1();
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
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186

#define play_beep(f,t) {tone(pin_beep, f, t); delay(t);}

void play_pingpong() {
  int t = 500;
  digitalWrite(pin_led, HIGH);
  play_beep(NOTE_E5, t);
  play_beep(NOTE_C5, t);
  delay(3000);
}

void play_phrase1() {
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

void play_phrase2() {
  int t = 120;
  digitalWrite(pin_led, HIGH);
  play_beep(NOTE_FS6, t);
  play_beep(NOTE_F6 , t);
  digitalWrite(pin_led, LOW);
  play_beep(NOTE_D6 , t);
  play_beep(NOTE_GS5 , t);
  digitalWrite(pin_led, HIGH);
  play_beep(NOTE_G5 , t);
  play_beep(NOTE_DS6 , t);
  digitalWrite(pin_led, LOW);
  play_beep(NOTE_G6 , t);
  play_beep(NOTE_B6 , t);

  for (int i = 0; i < 10; ++i) {
    digitalWrite(pin_led, HIGH);
    delay(t*2);
    digitalWrite(pin_led, LOW);
    delay(t*2);
  }  
}

void play_phrase3() {
  digitalWrite(pin_led, HIGH);
  play_beep(2000, 120);
  play_beep(1000, 120);
  delay(2000);
}

void play_phrase4() {
  int t = 300;
  digitalWrite(pin_led, HIGH);
  play_beep(NOTE_F5 , t);
  play_beep(NOTE_A5 , t);
  play_beep(NOTE_C6 , t);
  play_beep(NOTE_F6 , t*4);
  delay(t);

  play_beep(NOTE_A5 , t);
  play_beep(NOTE_AS5, t);
  play_beep(NOTE_AS5, t);
  play_beep(NOTE_FS5, t*4);
  delay(t);

  for (int i = 0; i < 50; ++i) {
    digitalWrite(pin_led, LOW);
    delay(random(30, 200));
    digitalWrite(pin_led, HIGH);
    delay(random(30, 200));
  }  
}
