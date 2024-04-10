const int pin0 = 2;
const int pin1 = 3;
const int pin2 = 4;
const int pin3 = 5;
const int pin4 = 8;
const int pin5 = 10;
const int pin6 = 11;
const int pin7 = 12;
const int resetPin = 29;
const int ledPins[] = {pin0, pin1, pin2 ,pin3, pin4, pin5, pin6, pin7}; // Define the pins connected to LEDs
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]); // Calculate the number of LEDs


void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void turnOn(int ledIndex) {
  if (ledIndex >= 0 && ledIndex < numLeds) {
    digitalWrite(ledPins[ledIndex], HIGH); // Turn on the LED
  }
}

void turnOff(int ledIndex) {
  if (ledIndex >= 0 && ledIndex < numLeds) {
      digitalWrite(ledPins[ledIndex], LOW);// Turn off the LED
    }
  }

void turnOnAll() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH); // Turn on all LEDs
    }
  }
  
void turnOffAll() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW); // Turn off all LEDs
    }
  }

void blink(int ledIndex, int duration) {
  turnOn(ledIndex); // Turn on the specified LED
  delay(duration);
  turnOff(ledIndex);
  delay(duration);
  }

void rebootRemote() {;
  digitalWrite(resetPin,LOW);
  delay(10);
  digitalWrite(resetPin, HIGH);
  }
  
void loop() {
  turnOnAll();
  delay(10000);
  turnOffAll();
  rebootRemote();
  Serial.println(); // Print a newline character to indicate the end of data
}
