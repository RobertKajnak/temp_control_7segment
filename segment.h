#ifndef segment_h
#define segment_h

#include "arduino.h"

class SevenSegment{ 
  private:
  char A = 4;//4 
  char B = 5;//5
  char C = 8;//8
  char D = 6;//6
  char E = 7;//7
  char F = 3;//3
  char G = 2;//2
  char H = 9;
  char ANODE1 = 10;
  char ANODE2 = 11;

  public:
  SevenSegment();
  ///invokes remap on init
  SevenSegment(char *);
  ///should contain the values for the A->H segments in order
  ///e.g. {2,3,4,5,6,7,8,9}
  void remap(const char * values);
  void number(int value,int duration);
  void decimal(char isOn);
  void digit(int value, int display_number);
};

#endif
