#include "segment.h"

void setup() {
  init_7_IO();
  pinMode(A0, INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);

}

void loop() {
  int i=0;
  int dec = 1;
  int dig = 0;
  int valI,valM,valH;
  float scaledValI,scaledValM,scaledValH;
  while (1){
    i++;
    digit(i,dig);
    valM = analogRead(A0);
    valI = analogRead(A1);
    scaledValM = valM*5.0/1024;
    scaledValI = valI/1.953;
    Serial.print("I=");
    Serial.print(scaledValI);
    Serial.print(",L=");
    Serial.print(scaledValM);
    Serial.println();
    number(scaledValI,1000);
    
    if (i==30){
      i=-15;
      dec = !dec;
    }
    decimal(dec);
  }
}
