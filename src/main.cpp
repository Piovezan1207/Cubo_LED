#include <Arduino.h>


byte LED [3][10]= {{13,8,9,10,7,6,5,2,3,4},{12,8,9,10,7,6,5,2,3,4},{11,8,9,10,7,6,5,2,3,4} };

void setup() 
{
  for(byte i = 2; i <=13; i++) pinMode(i, OUTPUT);
  for(byte i = 0; i <= 2; i++) digitalWrite(LED[i][0], HIGH);
 
}

void loop() 
{
 
  
 
  

}
