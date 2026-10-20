#include "M5StackRadio.h"

int pingI2cAddress(byte address) {
  Wire.beginTransmission(address);
  return Wire.endTransmission();
}

void fillCharArray(char* charArray, String string) {
  for (int i = 0; i < string.length(); i++) {
    charArray[i] = string[i];
  }
  charArray[string.length()] = '\0';
}

/*
void toggleResetClock() {
  digitalWrite(25, HIGH); // sets the digital pin 25 on
  delay(50);
  digitalWrite(25, LOW);  // sets the digital pin 25 off
  delay(50);
}
*/

void rebootEspWithReason(String reason) {
  Serial.println(reason);
  delay(1000);
  ESP.restart();
}