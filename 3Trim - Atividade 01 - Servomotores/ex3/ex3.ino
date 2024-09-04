#include <Servo.h>

Servo servoMotor;
int buttonPin = 2;
int buttonState = 0;


void setup() {
  servoMotor.attach(3);
  pinMode(buttonPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    delay(5000);
    servoMotor.write(0);
  }
  else if (buttonState == HIGH) {
    servoMotor.write(180);
  }
}
