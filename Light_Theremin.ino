int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

// cpu light is connected to this pin
int const ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  // open light to indicate calibration is taking place
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // calibrate the sensor for five seconds
  while(millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  // turn off light to indicate calibration is over
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  tone(8, pitch, 20);
  delay(10);

}
