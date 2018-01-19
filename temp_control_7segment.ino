#include "segment.h"

SevenSegment ss;
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
  /*char newMap[8] = {4,5,8,6,7,3,2,9};
  ss.remap(newMap);*/
}

void loop() {
  int i=0;
  int dec = 1;
  int dig = 0;
  int valI,valM,valH;
  float scaledValI,scaledValM,scaledValH;
  while (1){
    i++;
    ss.digit(i,dig);
    valM = analogRead(A0);
    valI = analogRead(A1);
    scaledValM = valM*5.0/1024;
    scaledValI = valI/1.953;
    Serial.print("I=");
    Serial.print(scaledValI);
    Serial.print(",L=");
    Serial.print(scaledValM);
    Serial.println();
    ss.number(scaledValI,1000);
    
    if (i==30){
      i=-15;
      dec = !dec;
    }
    ss.decimal(dec);
  }
}
