int buttons[6];

int notes[] = {262, 294, 330, 349};

void setup() {
  Serial.begin(9600);
  buttons[0] = 2;

}

void loop() {
  int keyVal = analogRead(A0);
  Serial.println(keyVal);
  if(keyVal >= 1020 && keyVal <= 1024){
    tone(8, notes[0]);
  }
  else if(keyVal >= 1000 && keyVal <= 1010){
    tone(8, notes[1]);
  }
  else if(keyVal >= 490 && keyVal <= 515){
    tone(8, notes[2]);
  }
  else if(keyVal >= 15 && keyVal <= 25){
    tone(8, notes[3]);
  }
  else{
    noTone(8);
  }
}
