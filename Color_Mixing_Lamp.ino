// constants for digital pins that connect to lights
const int greenLedPin = 9;
const int redLedPin = 10;
const int blueLedPin = 11;

// constants for digital pins that connect to sensors
const int greenSensorPin = A0;
const int redSensorPin = A1;
const int blueSensorPin = A2;

// stores the light level of each led
int greenValue = 0;
int redValue = 0;
int blueValue = 0;

// stores the sensor readings
int greenSensorValue = 0;
int redSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read sensor values, delay since sensors take time to read
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);

  // print sensor values
  Serial.print("Raw sensor values \t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t blue: ");
  Serial.println(blueSensorValue);

  // convert sensor readings to brightness value
  greenValue = greenSensorValue / 4;
  redValue = redSensorValue / 4;
  blueValue = blueSensorValue / 4;

  // print LED light levels
  Serial.print("Mapped sensor values \t green: ");
  Serial.print(greenValue);
  Serial.print("\t red: ");
  Serial.print(redValue);
  Serial.print("\t blue: ");
  Serial.println(blueValue);

  // set the brightness of the LED lights
  analogWrite(greenLedPin, greenValue);
  analogWrite(redLedPin, redValue);
  analogWrite(blueLedPin, blueValue);
}
