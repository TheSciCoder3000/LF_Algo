#include "lf_motor.h"

void LfMotor::begin(uint8_t enablePin, uint8_t inputA, uint8_t inputB)
{
  ePin = enablePin;
  inA = inputA;
  inB = inputB;

  pinMode(ePin, OUTPUT);
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
}

void LfMotor::drive(int speed)
{
  if (speed == 0)
  {
    analogWrite(ePin, 0);
    digitalWrite(inA, LOW);
    digitalWrite(inB, LOW);
  }
  else if (speed < 0)
  {
    analogWrite(ePin, -1 * speed);
    digitalWrite(inA, LOW);
    digitalWrite(inB, HIGH);
  }
  else
  {
    analogWrite(ePin, speed);
    digitalWrite(inA, HIGH);
    digitalWrite(inB, LOW);
  }
}
