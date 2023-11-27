#include <Arduino.h>

class LfMotor
{
public:
    uint8_t ePin, inA, inB;
    void begin(uint8_t enablePin, uint8_t inputA, uint8_t inputB);
    void drive(int speed);
};