#include <PS2Keyboard.h>
#include <SPI.h>
#include <SD.h>

const int DataPin = 2;
const int IRQpin =  3; 
int pinCS = 53; // Pin 10 on Arduino Uno
const int chipSelect = 10;
File myFile;
PS2Keyboard keyboard;

void setup(){
  
  pinMode(pinCS, OUTPUT);
  //pinMode(10, OUTPUT);  

  delay(3000);
  if (!SD.begin(4)) {
    return;
  }
  keyboard.begin(DataPin, IRQpin);                                                
}

void loop(){
  if(keyboard.available()){
    char c = keyboard.read();
    delay(25);
    myFile = SD.open("test.txt", FILE_WRITE);
    myFile.print(c);
    myFile.close();
  }  

  else;
}

