// #include <Arduino.h>

// #define LED_RED1 3
// #define LED_RGB1_R A0
// #define LED_RGB1_G A1
// #define LED_RGB1_B A2

// #define BTN1 5

// #define LEDR_RED 11
// #define LEDR_YELLOW 10
// #define LEDR_GREEN 9
// #define LEDR_BLUE 8

// void RGB1Write(int r, int g, int b);

// bool LED1_isOn = false;

// void setup(){
// 	pinMode(LED_RED1, OUTPUT);
// 	pinMode(LED_RGB1_R, OUTPUT);
// 	pinMode(LED_RGB1_G, OUTPUT);
// 	pinMode(LED_RGB1_B, OUTPUT);
// 	pinMode(LEDR_RED, OUTPUT);
// 	pinMode(LEDR_YELLOW, OUTPUT);
// 	pinMode(LEDR_GREEN, OUTPUT);
// 	pinMode(LEDR_BLUE, OUTPUT);
// 	pinMode(BTN1, INPUT);
// 	RGB1Write(0,0,0);
// }

// void loop(){
// 	// RGB1Write(239, 122, 122);
// 	// delay(400);
// 	// RGB1Write(243, 174, 95);
// 	// delay(400);
// 	// RGB1Write(251, 233, 78);
// 	// delay(400);
// 	// RGB1Write(114, 211, 76);
// 	// delay(400);
// 	// RGB1Write(68, 152, 201);
// 	// delay(400);
// }

// void flip_LED_RED_1(){
// 	if (LED1_isOn){
// 		digitalWrite(LED_RED1,LOW);
// 	} else {
// 		digitalWrite(LED_RED1,HIGH);
// 	}
// 	LED1_isOn = !LED1_isOn;
// }

// void RGB1Write(int r, int g, int b){
// 	analogWrite(LED_RGB1_R,r);
// 	analogWrite(LED_RGB1_G,g);
// 	analogWrite(LED_RGB1_B,b);
// }

// void activity2(){
// 	digitalWrite(3,HIGH);
// 	delay(5000);
// 	digitalWrite(3,LOW);
// 	delay(3000);
// 	for (size_t i = 0; i < 10; i++){
// 		digitalWrite(3,HIGH);
// 		delay(1000);
// 		digitalWrite(3,LOW);
// 		delay(1000);
// 	}
// 	delay(1000000);
// }