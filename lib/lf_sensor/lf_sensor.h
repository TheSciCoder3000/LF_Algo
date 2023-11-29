#include <Arduino.h>

class IRSensor
{
public:
    int s1, s2, s3, s4, s5;
    float innerWeight = 1500, outerWeight = 7000;
    float prevError = 0;
    int fullBlackCounter = 0;
    uint8_t ir1, ir2, ir3, ir4, ir5;
    void begin(uint8_t _ir1, uint8_t _ir2, uint8_t _ir3, uint8_t _ir4, uint8_t _ir5);
    void read();
    int getError();
    bool is90Left();
    bool is90Right();
    bool isIntersection();
    bool isOutLine();
    bool isInLine();
};