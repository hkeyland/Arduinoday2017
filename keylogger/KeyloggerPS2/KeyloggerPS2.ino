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

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  
  //while(!SD.begin(chipSelect));                                              // initialize the SD card
  Serial.println("Iniciando programa");
  keyboard.begin(DataPin, IRQpin);                                                
}

void loop(){
  if(keyboard.available()){
    char c = keyboard.read();
    delay(25);
    Serial.print(c);
    //while(!(myFile = SD.open("new.txt", FILE_WRITE)));
    myFile = SD.open("test.txt", FILE_WRITE);
    myFile.print(c);
    myFile.close();
  }  

  else;
}

