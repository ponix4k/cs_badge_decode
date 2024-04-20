#include <Arduino.h>
void foo()
{
  Serial.print("Hello World!");
}

// Settings
int maxCount = 256;
int timer = 8000;
int bitVal = 0;

// Declare pins
int pin0 = 12; //d9
int pin1 = 11; //pd6
int pin2 = 10; //pb0
int pin3 = 9;
int pin4 = 8;
int pin5 = 4;
int pin6 = 6;
int pin7 = 5;

const int ledPin[] = {pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7}; // Define the pins connected to LEDs
const int resetPin = 19;

void allOn()
{
  for (int i = 0; i < 8; i++) 
  {
    digitalWrite(ledPin[i], HIGH);
  }
}
void allOff()
{
  for (int i = 0; i < 8; i++) 
  {
    digitalWrite(ledPin[i], LOW);
  }
}

void setup() 
{
  Serial.begin(9600);
  for (int i = 0; i < 9; i ++)
    {
      pinMode(ledPin[i],OUTPUT);
    }

  allOn();
  allOff();
}

void resetBadge()
{
  
  Serial.println("#############");
  Serial.println("# RESETTING #");
  Serial.println("#############");
  Serial.println(bitVal);

}

void displayBinary(byte numToShow)
{
  for(int i = 0; i < 8; i++)
  {
    if(bitRead(numToShow, i)==1)
    {
      digitalWrite(ledPin[i], HIGH);
    }
    else
    {
      digitalWrite(ledPin[i], LOW);
    }
  }
}

void loop()
{
  for(int counter = 0; counter < maxCount; counter++)
  {
    bitVal = counter;
    digitalWrite(resetPin,HIGH);
    displayBinary(counter);
    resetBadge();
    delay(timer);
  }
}