// #include <Arduino.h>
// #include "LED.hpp"
// #include "Button.hpp"

// #define LED_PIN 6
// #define BTN_PIN 10

// int buttonPressCount = 0;
// LED LED1 = LED(LED_PIN);
// Button btn1 = Button(BTN_PIN,PullDOWN);

// void setup(){
//     LED1.turnOn();
// }

// void loop(){
//     while (!btn1.isDown()) { delay(10); } // Wait
//     while (btn1.isDown()) {delay(10); }//wait
//     buttonPressCount++;
//     if (buttonPressCount>=3) {
//         LED1.toggle();
//         buttonPressCount = 0;
//     }
// }
