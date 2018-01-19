#include "segment.h"


SevenSegment::SevenSegment(){
  pinMode(ANODE1, OUTPUT);
  pinMode(ANODE2, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
}

SevenSegment::SevenSegment(char * v){
   SevenSegment();
   remap(v);
}

void SevenSegment::remap(const char * v){
  A = *v;
  B = *(v+1);
  C = *(v+2);
  D = *(v+3);
  E = *(v+4);
  F = *(v+5);
  G = *(v+6);
  H = *(v+7);
}

void SevenSegment::number(int n,int t){
  int i;
  int a,b;
  if (n < 0){
    a=-1;
    b=-n;
  } else{
    a=n/10;
    b=n%10;
  }
  for (i=0;i<t/5;i++){
     if (i%2){
       digit(a,1);
     }
     else{
       digit(b,0);
     }
     delay(5);
  }
}

void SevenSegment::decimal(char isOn){
  if (isOn){
    digitalWrite(H, LOW);
  }
  else{
    digitalWrite(H, HIGH);
  }
}

void SevenSegment::digit(int n, int number){

  if (number){
    digitalWrite(ANODE2, HIGH);
    digitalWrite(ANODE1, LOW);
  }
  else{
    digitalWrite(ANODE1, HIGH);
    digitalWrite(ANODE2, LOW);
  }
  switch (n){
  case 1:
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
  
  case 2:
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    break;
  
  case 3:
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    break;
  
  case 4:
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    break;
  
  case 5:
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    break;
  
  case 6:
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    break;
  
  case 7:
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
  
  case 8:
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    break;
  
  case 9:
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  break;
  
  case 0:
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    break;
  default:
    if (n<0 && n>-10){
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
    }
    else{
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
    }
    break;
  }
}
