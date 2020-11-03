#include <Arduino.h>
#include "ToggleButton.hpp"

ToggleButton::ToggleButton(int pinNum, ButtonType type = PullDOWN, BinaryDeviceState initialState = OFF){
    this->btn = new Button(pinNum,type);
    this->swState = initialState;
    this->lastBtnState = this->btn->getButtonState();
    this->attachedPins = (int*) malloc(maxNumAttachedPins*sizeof(int));
}

ToggleButton::~ToggleButton(){
    delete btn;
    delete attachedPins;
}

void ToggleButton::update(){
    ButtonState newState = this->btn->getButtonState();
    if (newState != lastBtnState){
        lastBtnState = newState;
        if (newState == UP){ // Activate on release
            if (swState == ON) swState = OFF;
            else swState = ON;
            updateAttachedPins();
        }
    }
}

BinaryDeviceState ToggleButton::getSwitchState(){
    return swState;
}

void ToggleButton::attachPinToSwitchOutput(int pinNum){
    for (size_t i = 0; i < numAttachedPins; i++)
        if (this->attachedPins[i]==pinNum) return;
    if (this->numAttachedPins==this->maxNumAttachedPins) return;
    this->attachedPins[numAttachedPins] = pinNum;
    numAttachedPins++;
    pinMode(pinNum,OUTPUT);
    digitalWrite(pinNum,swState==ON?HIGH:LOW);
}

void ToggleButton::updateAttachedPins(){
    if (swState==ON)
        for (size_t i = 0; i < numAttachedPins; i++)
            digitalWrite(attachedPins[i],HIGH);
    else
        for (size_t i = 0; i < numAttachedPins; i++)
            digitalWrite(attachedPins[i],LOW);
}
