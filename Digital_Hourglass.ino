const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0;
int led = 2;
long interval = 2000; // (10 min)

void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i<=7; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(8, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();
  // if 10 min has passed since previous light turned on, turn next one on
  if (currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;

   //after time is up, flashes until switch is turned
    if (digitalRead(7) == HIGH) {
      if (switchState == prevSwitchState) {
        delay(interval);
        for (int x = 2; x <= 7; x++)
        {
          digitalWrite(x, LOW);
        }
        delay(500);
        for (int y = 2; y <= 7; y++)
        {
          digitalWrite(y, HIGH);
        }
        delay(500);
      }
    }
  }

  // allow the switch to turn all lights off
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    for (int j = 2; j <= 7; j++) {
      digitalWrite(j, LOW);
    }
    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;
}
