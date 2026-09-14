#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;
const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 1000;

void setup() {
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT);
  Serial.begin(115200);
  matrix.begin(); 
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
    if (led == 8) {
      matrix.loadSequence(LEDMATRIX_ANIMATION_TETRIS_INTRO);
      matrix.play(true); 
    }
  }
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }
    led = 2;
    previousTime = currentTime;
    matrix.play(false);
    matrix.clear();
  }
  prevSwitchState = switchState;
}
