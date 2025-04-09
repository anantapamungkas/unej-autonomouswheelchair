#include "DCMotor.h"

Motor::Motor(int pin1, int pin2, int freq) {
  pwmPin1 = pin1;
  pwmPin2 = pin2;
  frequency = freq;

  pinMode(pwmPin1, OUTPUT);
  pinMode(pwmPin2, OUTPUT);

  analogWriteFrequency(pwmPin1, frequency);
  analogWriteFrequency(pwmPin2, frequency);
}

void Motor::setSpeed(int speed) {
  speed = constrain(speed, -255, 255);

  if (speed > 0) {
    analogWrite(pwmPin1, speed);
    analogWrite(pwmPin2, 0);
  } else if (speed < 0) {
    analogWrite(pwmPin1, 0);
    analogWrite(pwmPin2, abs(speed));
  } else {
    analogWrite(pwmPin1, 0);
    analogWrite(pwmPin2, 0);
  }
}

void Motor::stop() {
  analogWrite(pwmPin1, 0);
  analogWrite(pwmPin2, 0);
}