#ifndef LED_CPP
#define LED_CPP
#include "BinaryDeviceState.enum.hpp"


/**
 * LED Controller Class
 * REMARK: 1. constructor handles pinmode selection!
 * REMARK: 2. pinNumber is abstracted and private
 */
class LED {
private:
    int pinNumber;
    /**
     * Sync State variable and pin digital value
     */
    void syncState();
    /**
     * Current state of LED, true=on, call syncState() to apply.
     */
    BinaryDeviceState state;
public:
    LED(int pinNum, BinaryDeviceState initState=OFF);
    ~LED();
    BinaryDeviceState getState();
    void turnOn();
    void turnOff();
    void toggle();
};

#endif