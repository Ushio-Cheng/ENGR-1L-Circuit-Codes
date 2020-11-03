// #include <Arduino.h>
// #include "LED.hpp"

// #define PR_PIN A2
// LED led1 = LED(12);

// void setup(){
//     pinMode(PR_PIN, INPUT);
//     Serial.begin(9600);
// }

// void loop(){
//     int vValue = analogRead(PR_PIN);
//     int lightLevel;
//     if (vValue<=16) lightLevel = 100;
//     else if (vValue>=942) lightLevel = 0;
//     else lightLevel = map(vValue,16,942,0,100);
//     Serial.println(lightLevel);
//     if (lightLevel<70){
//         led1.turnOn();
//     } else {
//         led1.turnOff();
//     }
//     delay(50);
// }