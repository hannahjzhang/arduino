int notes[] = {261.63, 293.665, 329.628, 349};

void setup() {
  // put your setup code here, to run once:
  // open serial communication
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int keyVal = analogRead(A0);
  Serial.println(keyVal);

  // determine what note to play
  // all the 4 switches connects to one analog pin
  // each have diff voltages bc of the diff resistors
  if (keyVal == 1023) {
    tone(8, notes[0]); 
  }
  else if (keyVal >= 990 && keyVal <= 1010) {
    tone(8, notes[1]);
  }
  else if (keyVal >= 505 && keyVal <= 515) {
    tone(8, notes[2]);
  }
  else if(keyVal >= 5 && keyVal <= 10) {
    tone(8, notes[3]);
  }
  else {
    noTone(8);
  }
}
