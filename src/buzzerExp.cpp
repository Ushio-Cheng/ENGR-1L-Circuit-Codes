#include <Arduino.h>
#include "ToggleButton.hpp"
#include "LED.hpp"

#define BUZZER_PIN 5
ToggleButton tb1 = ToggleButton(2);
LED led1 = LED(4);

void updateAll();

void setup(){
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    updateAll();
    int freq = map(analogRead(A1),516,1023,16,8000);
    Serial.print("Frequency:");
    Serial.println(freq);
    if (tb1.getSwitchState()==ON) {
        led1.turnOn();
        tone(BUZZER_PIN,freq);
    } else {
        led1.turnOff();
        noTone(BUZZER_PIN);
    }
}

void updateAll(){
    tb1.update();
}