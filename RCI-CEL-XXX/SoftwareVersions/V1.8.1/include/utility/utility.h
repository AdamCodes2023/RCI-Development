#include "M5StackMQTTFTP.h"

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

// send an NTP request to the time server at the given address
void sendNTPpacket(const char * address) {
  // set all bytes in the buffer to 0
  memset(packetBufferTime, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBufferTime[0] = 0b11100011;   // LI, Version, Mode
  packetBufferTime[1] = 0;     // Stratum, or type of clock
  packetBufferTime[2] = 6;     // Polling Interval
  packetBufferTime[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBufferTime[12]  = 49;
  packetBufferTime[13]  = 0x4E;
  packetBufferTime[14]  = 49;
  packetBufferTime[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); // NTP requests are to port 123
  Udp.write(packetBufferTime, NTP_PACKET_SIZE);
  Udp.endPacket();
}

void hexCharacterStringToBytes(byte *byteArray, const char *hexString) {
  bool oddLength = strlen(hexString) & 1;

  byte currentByte = 0;
  int byteIndex = 0;

  for (int charIndex = 0; charIndex < strlen(hexString); charIndex++) {
    bool oddCharIndex = charIndex & 1;

    if (oddLength) {
      // If the length is odd
      if (oddCharIndex) {
        // odd characters go in high nibble
        currentByte = nibble(hexString[charIndex]) << 4;
      } else {
        // Even characters go into low nibble
        currentByte |= nibble(hexString[charIndex]);
        byteArray[byteIndex++] = currentByte;
        currentByte = 0;
      }
    } else {
      // If the length is even
      if (!oddCharIndex) {
        // Odd characters go into the high nibble
        currentByte = nibble(hexString[charIndex]) << 4;
      }
      else {
        // Odd characters go into low nibble
        currentByte |= nibble(hexString[charIndex]);
        byteArray[byteIndex++] = currentByte;
        currentByte = 0;
      }
    }
  }
}

byte nibble(char c) {
  if (c >= '0' && c <= '9')
    return c - '0';

  if (c >= 'a' && c <= 'f')
    return c - 'a' + 10;

  if (c >= 'A' && c <= 'F')
    return c - 'A' + 10;

  return 0;  // Not a valid hexadecimal character
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