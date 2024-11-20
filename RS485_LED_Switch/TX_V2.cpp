#include <SoftwareSerial.h>

#define buttonPin 13
SoftwareSerial RS485(2, 3);

void setup() {
  Serial.begin(9600);
  RS485.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  
  long int success_count;
  long int error_count;
  int success_rate;
  char returnVal;
  char inputVal;
  
  if (digitalRead(buttonPin) == 0) {
    inputVal = 'L';
    RS485.write(inputVal);
  } else {
    inputVal = 'D';
    RS485.write(inputVal);
  }

  returnVal = RS485.read();
  if(returnVal != intputVal)
    error_count++;
  else
    success_count++;
  success_rate = error_count / (success_count + error_count) * 100;

  Serial.print(returnVal);
  Serial.print(" : ");
  Serial.print(inputVal);
  Serial.print(" ; ");
  Serial.print(error_count);
  Serial.print("-");
  Serial.print(success_count);
  Serial.print(":  ");
  Serial.print(success_rate);
  Serial.println("%");
  
}