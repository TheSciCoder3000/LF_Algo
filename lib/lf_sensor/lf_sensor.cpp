#include "lf_sensor.h"

void IRSensor::begin(uint8_t _ir1, uint8_t _ir2, uint8_t _ir3, uint8_t _ir4, uint8_t _ir5)
{
    ir1 = _ir1;
    ir2 = _ir2;
    ir3 = _ir3;
    ir4 = _ir4;
    ir5 = _ir5;
    pinMode(ir1, INPUT);
    pinMode(ir2, INPUT);
    pinMode(ir3, INPUT);
    pinMode(ir4, INPUT);
    pinMode(ir5, INPUT);
}

void IRSensor::read()
{
    s1 = digitalRead(ir1) == 1 ? 0 : 1;
    s2 = digitalRead(ir2) == 1 ? 0 : 1;
    s3 = digitalRead(ir3) == 1 ? 0 : 1;
    s4 = digitalRead(ir4) == 1 ? 0 : 1;
    s5 = digitalRead(ir5) == 1 ? 0 : 1;

    if ((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
    {
        fullBlackCounter++;
    }
    else
    {
        fullBlackCounter = 0;
    }

    // Serial.print(s1);
    // Serial.print(" | ");
    // Serial.print(s2);
    // Serial.print(" | ");
    // Serial.print(s3);
    // Serial.print(" | ");
    // Serial.print(s4);
    // Serial.print(" | ");
    // Serial.print(s5);
    // Serial.print("\r");
}

int IRSensor::getError()
{

    // if (isOutLine())
    //     return prevError;

    // return (s1 * -outerWeight) + (s2 * -innerWeight) + (s3 * 0) + (s4 * innerWeight) + (s5 * outerWeight);
    return (s2 * -innerWeight) + (s3 * 0) + (s4 * innerWeight);
}

bool IRSensor::is90Left()
{
    read();
    if ((s1 == 1) && (s2 == 1))
        return true;
    return false;
}

bool IRSensor::is90Right()
{
    read();
    if (((s5 == 1) && (s4 == 1)) || ((s1 == 1) && (s3 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 1)))
        return true;
    return false;
}

bool IRSensor::isInLine()
{
    read();
    if (s2 == 1 || s3 == 1 || s4 == 1)
        return true;
    return false;
}

bool IRSensor::isIntersection()
{
    read();
    if ((s1 == 1) && (s3 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
        return true;
    return false;
}

bool IRSensor::isOutLine()
{
    read();
    if ((s1 == 0) && (s3 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
        return true;
    return false;
}