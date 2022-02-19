// version : V2
// author : Louis
// lastest updata : 20200218

#include <Keyboard.h>
#include <Mouse.h>
#include "config.h"

const byte nRow = sizeof(rowPins);
const byte nCol = sizeof(colPins);
const byte nAnalog = sizeof(analogpin);

byte i,j;
bool lastPress[nRow][nCol];
int lastRotate[nAnalog];
//unsigned long previous_time;
//static unsigned long time = 0;

void setup() {
  Serial1.begin(9600);
//  while (!Serial);
  delay(3000);
  for (i = 0; i < nRow; i++) {
    pinMode(rowPins[i], INPUT);
    digitalWrite(rowPins[i], HIGH);
  }
  for (i = 0; i < nCol; i++) {
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], HIGH);
  }  
  for (i = 0; i < nRow; i++) {
    for (j = 0; j < nCol; j++) {
      lastPress[i][j]= false;
    }
  }
  for (i = 0; i < nAnalog; i++) {
      lastRotate[nAnalog]=0;
  }
  
  Keyboard.begin();
  Serial.println("Strat");
  Serial.println(String()+"nRow pin number = "+ nRow);
  Serial.println(String()+"nCol pin number = "+ nCol);
  Serial.println(String()+"nAnalog pin number = "+ nAnalog);
//  previous_time = millis();
}

void loop() {
  bool scanVal;
  int rotateVal;
  //安全設定
//  while(digitalRead(21)){delay(1000);}

  
  for (i=0; i < nRow; i++) {
    for (j=0; j < nCol; j++) {
      digitalWrite(colPins[j],LOW);
      scanVal = !digitalRead(rowPins[i]);
      if(scanVal && !lastPress[i][j]){
        Serial.print(keyMap[i][j]);
        presskey(keyMap[i][j]);
        lastPress[i][j]=true;
        digitalWrite(4, HIGH);
      }else if (!scanVal){
        lastPress[i][j]=false;
        digitalWrite(4, LOW);
      }
      digitalWrite(colPins[j],HIGH);
      delay(debounce_time);
    }
  }
  
  for (i=0; i<nAnalog; i++){
    rotateVal = analogRead(analogpin[i]);
    if (abs(rotateVal-lastRotate[i])>5){   
      Serial.println(rotateVal); 
      Mouse.begin();
      Mouse.move(0, 0, lastRotate[i]-rotateVal);
      Mouse.end();
      lastRotate[i] = rotateVal;
      

    }
  }
  
  Serial.println("");
  delay(30);
}



void presskey(char button){
  Keyboard.press(button);
  delay(10);
  Keyboard.release(button);
}
