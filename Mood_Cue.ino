#include <Servo.h>
// create an object
Servo myServo;

// declare constants and variables
const int potPin = A0;
int potVal;
int angle;

void setup() {
  // put your setup code here, to run once:
  // associates object with pin & initiates sensor reading
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read sensor and print the value
  potVal = analogRead(potPin);
  Serial.print("potentiometer value: ");
  Serial.print(potVal);
  // calculate angle and print value
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  // based on the sensor, rotate the servo motor
  myServo.write(angle);
  delay(15);
}
