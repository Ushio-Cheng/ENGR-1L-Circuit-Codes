// #include <Arduino.h>

// int* readableDigitalPins;
// int* readableAnalogPins;
// const uint8_t analogPins[] = {A0,A1,A2,A3,A4,A5};
// const String analogPinName[] = {"A0","A1","A2","A3","A4","A5"};

// String* tryGetSerialInput();

// void opcodeRA(String* command);
// void opcodeDM(String* command);
// void opcodeDR(String* command);
// void opcodeDW(String* command);
// void opcodeAM(String* command);
// void opcodeAR(String* command);
// void opcodeAW(String* command);

// void setup(){
//     readableAnalogPins = (int*) malloc(sizeof(int)*50);
//     for (size_t i = 0;i<50;i++) readableAnalogPins[i] = -1;
//     readableDigitalPins = (int*) malloc(sizeof(int)*50);
//     for (size_t i = 0;i<50;i++) readableDigitalPins[i] = -1;
//     Serial.begin(9600);
//     while (Serial) {} // Wait for Serial
//     Serial.println("Hello.");
//     Serial.println("==========COMMANDS==========");
//     Serial.println("AM for pinMode ex.PM01I, PM12O");
//     Serial.println("AM for Analog pinMode ex.AM01I");
//     Serial.println("RA for readAll");
//     Serial.println("DR for digital read ex.DR1");
//     Serial.println("AR for analog read ex.AR1");
//     Serial.println("DW for digital Write");
//     Serial.println("AW for analog Write");;
//     Serial.println("============================");
// }

// void loop(){
//     String* command = tryGetSerialInput();
//     if (command!=nullptr){
//         switch ((*command)[0]) {
//             case 'R': case 'r':
//                 switch ((*command)[1]) {
//                     case 'A': case 'a':
//                         // opcode: RA
//                         opcodeRA(command);
//                         break;
//                     default: break;
//                 }
//                 break;
//             case 'D': case 'd':
//                 switch ((*command)[1]) {
//                     case 'R': case 'r':
//                         // opcode: DR
//                         opcodeDR(command);
//                         break;
//                     case 'W': case 'w':
//                         // opcode: DW
//                         opcodeDW(command);
//                         break;
//                     case 'M': case 'm':
//                         // opcode: DM
//                         opcodeDM(command);
//                         break;
//                     default: break;
//                 }
//                 break;
//             case 'A': case 'a':
//                 switch ((*command)[1]) {
//                     case 'R': case 'r':
//                         // opcode: AR
//                         opcodeAR(command);
//                         break;
//                     case 'W': case 'w':
//                         // opcode: AW
//                         opcodeAW(command);
//                         break;
//                     case 'M': case 'm':
//                         // opcode: AM
//                         opcodeAM(command);
//                         break;
//                     default: break;
//                 }
//                 break;
//             default: break;
//         }
//     }
//     delete command;
// }

// String* tryGetSerialInput() {
//     if (Serial.available()) {
//         String* inputString = new String();
//         while (Serial.available()) {
//             char inChar = (char)Serial.read();
//             // add it to the inputString:
//             *inputString += inChar;
//             // if the incoming character is a newline, set a flag so the main loop can
//             // do something about it:
//             while (inChar != '\n') {
//                 // Wait
//             }
//         }
//     } else {
//         return nullptr;
//     }
// }

// void opcodeRA(String* command){
//     String digitalBits;
//     for (size_t i = 0;i<14;i++){
//         if (i==0) digitalBits += "|";
//         digitalBits += "Pin#"+String(i)+" ";
//         bool canReadI = false;
//         for (size_t j = 0; j < 14; j++) {
//             if (readableDigitalPins[j]==i) {
//                 canReadI = true;
//                 digitalBits += String(digitalRead(i));
//             }
//         }
//         if (!canReadI) digitalBits += "?";
//         digitalBits+="|";
//     }
//     String analogValues;
//     for (size_t i = 0;i<6;i++){
//         if (i==0) analogValues += "|";
//         analogValues += "Analog#"+analogPinName[i]+" ";
//         bool canReadI = false;
//         for (size_t j = 0; j < 6; j++) {
//             if (readableAnalogPins[j]==analogPins[i]) {
//                 canReadI = true;
//                 analogValues += String(analogRead(analogPins[i]));
//             }
//         }
//         if (!canReadI) analogValues += "?";
//         analogValues+="|";
//     }
//     Serial.println("====================READ ALL REPORT====================");
//     Serial.println(digitalBits);
//     Serial.println(analogValues);
//     Serial.println("====================  REPORT END   ====================");
// }

// void opcodeDM(String* command){
//     int pinNum = command->substring(2,4).toInt();
//     char Param3 = command->charAt(4);
//     switch (Param3) {
//         case 'I':
//             pinMode(pinNum,INPUT);
//             int i = 0;
//             while (readableDigitalPins[i]>=0) i++;
//             readableDigitalPins[i] = pinNum;
//             break;
//         case 'O':
//             pinMode(pinNum,OUTPUT);
//             break;
//         default: break;
//     }
// }

// void opcodeDR(String* command){
//     int pinNum = command->substring(2,4).toInt();
//     bool canRead = false;
//     for (size_t j = 0; j < 14; j++) {
//         if (readableDigitalPins[j]==pinNum) {
//             canRead = true;
//             Serial.println("Pin#"+String(pinNum)+": "+String(digitalRead(pinNum)));
//         }
//     }
//     if (!canRead) Serial.println("This pin is not readable.");
// }

// void opcodeDW(String* command){
//     int pinNum = command->substring(2,4).toInt();
//     char Param3 = command->charAt(4);
//     bool canRead = false;
//     for (size_t j = 0; j < 14; j++) {
//         if (readableDigitalPins[j]==pinNum) {
//             canRead = true;
//         }
//     }
//     if (canRead) {
//         Serial.println("This pin is not writeable.");
//         return;
//     }
//     switch (Param3) {
//         case 'H':
//             digitalWrite(pinNum,HIGH);
//             break;
//         case 'L':
//             digitalWrite(pinNum,LOW);
//             break;
//         default: break;
//     }
// }

// void opcodeAM(String* command){
//     int pinNum = analogPins[command->substring(2,4).toInt()];
//     char Param3 = command->charAt(4);
//     switch (Param3) {
//         case 'I':
//             pinMode(pinNum,INPUT);
//             int i = 0;
//             while (readableAnalogPins[i]>=0) i++;
//             readableAnalogPins[i] = pinNum;
//             break;
//         case 'O':
//             pinMode(pinNum,OUTPUT);
//             break;
//         default: break;
//     }
// }

// void opcodeAR(String* command){
//     int i = command->substring(2,4).toInt();
//     int pinNum = analogPins[i];
//     bool canRead = false;
//     for (size_t j = 0; j < 14; j++) {
//         if (readableAnalogPins[j]==pinNum) {
//             canRead = true;
//             Serial.println("APin#"+String(analogPinName[i])+": "+String(analogRead(pinNum)));
//         }
//     }
//     if (!canRead) Serial.println("This pin is not readable.");
// }

// void opcodeAW(String* command){
//     int pinNum = analogPins[command->substring(2,4).toInt()];
//     String Param3 = command->substring(4);
//     int value = Param3.toInt();
//     bool canRead = false;
//     for (size_t j = 0; j < 14; j++) {
//         if (readableAnalogPins[j]==pinNum) {
//             canRead = true;
//         }
//     }
//     if (canRead) {
//         Serial.println("This pin is not writeable.");
//         return;
//     }
//     analogWrite(pinNum,value);
// }
