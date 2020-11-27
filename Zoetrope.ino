// constants (pins)
const int directionPin = 4; // control direction
const int onOffPin = 5; // motor on & off
const int powerPin = 9; // motor speed
const int controlPin1 = 3; // communicate with h-bridge --> spin
const int controlPin2 = 2; // communicate with h-bridge --> spin
const int potPin = A0;

// remember switch states
// need to keep prev states bc only changes when pressed, otherwise keeps doing same motion
int directionState = 0;
int prevDirectionState = 0;
int onOffState = 0;
int prevOnOffState = 0;

// motor states
int motorEnabled = 0;
int motorDirection = 1;
int motorSpeed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(directionPin, INPUT);
  pinMode(onOffPin, INPUT);
  // these 3 are output because the arduino controls what happens there
  pinMode(powerPin, OUTPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  
  digitalWrite(powerPin, LOW);
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read info from sensors
  onOffState = digitalRead(onOffPin);
  delay(1);
  directionState = digitalRead(directionPin);
  motorSpeed = analogRead(potPin) / 4;

  // check on/off sensor for changes
  // if states are different & button was just pressed (high/1)
  // flip the motor on/off status
  if (onOffState != prevOnOffState) {
    // this line allows button to act as a trigger 
    // (switchstate changes when you let go but not motorstate because it is LOW)
    if (onOffState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }

  // check direction sensor for changes
  // if states are different & button was just pressed
  // flip the motor on/off status
  if (directionState != prevDirectionState) {
    // allows button to act as trigger
    if (directionState == HIGH) {
      motorDirection = !motorDirection;
    }
  }
  // based on changes in state from above code (0 or 1)
  // if switch is off, runs this code but nothing happens
  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1) {
    analogWrite(powerPin, motorSpeed);
  }
  else {
    analogWrite(powerPin, 0);
  }

  // save new state variables
  prevDirectionState = directionState;
  prevOnOffState = onOffState;

}
