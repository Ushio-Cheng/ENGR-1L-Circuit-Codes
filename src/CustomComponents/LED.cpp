#include "LED.hpp"
#include <Arduino.h>

LED::LED(int pinNum, BinaryDeviceState initState) {
    this->pinNumber = pinNum;
    this->state = initState;
    pinMode(pinNum,OUTPUT);
    // Force the current state to match what is stored in variable
    syncState();
}
LED::~LED() { }

void LED::syncState(){
    if (state==ON) digitalWrite(pinNumber,HIGH);
    else digitalWrite(pinNumber,LOW);
}


BinaryDeviceState LED::getState(){
    return state;
}

void LED::turnOn(){
    state = ON;
    syncState();
}

void LED::turnOff(){
    state = OFF;
    syncState();
}

void LED::toggle(){
    if (state==ON) turnOff();
    else turnOn();
}