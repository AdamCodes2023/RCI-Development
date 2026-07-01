#include "M5StackMQTTFTP.h"

int pingI2cAddress(byte address) {
  Wire.beginTransmission(address);
  return Wire.endTransmission();
}

void checkI2CDevices() {
  if (pingI2cAddress(0x48) == 0) {
    analogInOneSuccess = true;
  } else {
    analogInOneSuccess = false;
  }

  if (pingI2cAddress(0x49) == 0) {
    analogInTwoSuccess = true;
  } else {
    analogInTwoSuccess = false;
  }
  
  if (pingI2cAddress(0x1f) == 0) {
    analogOutOneSuccess = true;
  } else {
    analogOutOneSuccess = false;
  }

  if (pingI2cAddress(0x1c) == 0) {
    analogOutTwoSuccess = true;
  } else {
    analogOutTwoSuccess = false;
  }

  if (pingI2cAddress(0x38) == 0) {
    digitalInputSuccess = true;
  } else {
    digitalInputSuccess = false;
  }

  if (pingI2cAddress(0x39) == 0) {
    digitalOutputSuccess = true;
  } else {
    digitalOutputSuccess = false;
  }

  if (pingI2cAddress(0x3a) == 0) {
    digitalDebugSuccess = true;
  } else {
    digitalDebugSuccess = false;
  }
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

void recordRCIConfigurationData() {
  configString = groupID + "_GID;" + unitID + "_UID;" + IONum + "_ION;" + updateTime + "_UPT;" + consumerName + "_CN;" +
              *di_feeds[0] + ";" + *di_feeds[1] + ";" + *di_feeds[2] + ";" + *di_feeds[3] + ";" + *di_feeds[4] + ";" + *di_feeds[5] + ";" + *di_feeds[6] + ";" + *di_feeds[7] + ";" +
              *ai_feeds[0] + ";" + *ai_feeds[1] + ";" + *ai_feeds[2] + ";" + *ai_feeds[3] + ";" + *ai_feeds[4] + ";" + *ai_feeds[5] + ";" + *ai_feeds[6] + ";" + *ai_feeds[7] + ";" +
              do1_feed + "_DO1;" + do2_feed + "_DO2;" + do3_feed + "_DO3;" + do4_feed + "_DO4;" + do5_feed + "_DO5;" + do6_feed + "_DO6;" + do7_feed + "_DO7;" + do8_feed + "_DO8;" +
              ao1_feed + "_AO1;" + ao2_feed + "_AO2;" + ao3_feed + "_AO3;" + ao4_feed + "_AO4;" + ao5_feed + "_AO5;" + ao6_feed + "_AO6;" + ao7_feed + "_AO7;" + ao8_feed + "_AO8;" +
              df1ReadValue + "_DF1;" + df2ReadValue + "_DF2;" + df3ReadValue + "_DF3;" + df4ReadValue + "_DF4;" + df5ReadValue + "_DF5;" + df6ReadValue + "_DF6;" + df7ReadValue + "_DF7;" + df8ReadValue + "_DF8;" +
              af1ReadValue + "_AF1;" + af2ReadValue + "_AF2;" + af3ReadValue + "_AF3;" + af4ReadValue + "_AF4;" + af5ReadValue + "_AF5;" + af6ReadValue + "_AF6;" + af7ReadValue + "_AF7;" + af8ReadValue + "_AF8;" +
              heartbeatSubscriptionsString + "_HB;";

  preferences.begin(pnamespace);
  preferences.putString(configStringKey, configString);
  preferences.end();
  
  myFile = SD.open(sdConfigFileName, FILE_WRITE);
  myFile.print(configString);
  myFile.close();
}

void rebootEspWithReason(String reason) {
  Serial.println(reason);
  logForcedResetEvent(reason);
  delay(1000);
  ESP.restart();
}

void updateLocalTime() {
  if (getLocalTime(&timeinfo)) {
    timeinfo.tm_mon = timeinfo.tm_mon + 1;
    timeinfo.tm_year = timeinfo.tm_year + 1900;
  } else {
    Serial.println("NTP Time Sync FAILED....");
  }
}

bool checkTimeRoutine() {
  if (firstTimeGet || getTimeCurrentMillis - getTimePreviousMillis >= getTimeInterval) {
    ethClientSSL.clearWriteError();

    sendNTPpacket(timeServer); // send an NTP packet to a time server

    // wait to see if a reply is available
    delay(1000);
    if (Udp.parsePacket()) {
      udpHasTimePacket = true;
    }

    if (!udpHasTimePacket) {
      sendNTPpacket(timeServer2); // send an NTP packet to a time server

      // wait to see if a reply is available
      delay(1000);
      if (Udp.parsePacket()) {
        udpHasTimePacket = true;
      }
    }

    if (!udpHasTimePacket) {
      sendNTPpacket(timeServer3); // send an NTP packet to a time server

      // wait to see if a reply is available
      delay(1000);
      if (Udp.parsePacket()) {
        udpHasTimePacket = true;
      }
    }

    if (!udpHasTimePacket) {
      sendNTPpacket(timeServer4); // send an NTP packet to a time server

      // wait to see if a reply is available
      delay(1000);
      if (Udp.parsePacket()) {
        udpHasTimePacket = true;
      }
    }

    if (!udpHasTimePacket) {
      sendNTPpacket(timeServer5); // send an NTP packet to a time server

      // wait to see if a reply is available
      delay(1000);
      if (Udp.parsePacket()) {
        udpHasTimePacket = true;
      }
    }

    if (udpHasTimePacket) {
      // We've received a packet, read the data from it
      Udp.read(packetBufferTime, NTP_PACKET_SIZE); // read the packet into the buffer

      // the timestamp starts at byte 40 of the received packet and is four bytes,
      // or two words, long. First, extract the two words:

      unsigned long highWord = word(packetBufferTime[40], packetBufferTime[41]);
      unsigned long lowWord = word(packetBufferTime[42], packetBufferTime[43]);
      // combine the four bytes (two words) into a long integer
      // this is NTP time (seconds since Jan 1 1900):
      unsigned long secsSince1900 = highWord << 16 | lowWord;
      //Serial.print("Seconds since Jan 1 1900 = ");
      //Serial.println(secsSince1900);

      // now convert NTP time into everyday time:
      //Serial.print("Unix time = ");
      // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
      const unsigned long seventyYears = 2208988800UL;
      // subtract seventy years:
      unsigned long epoch = secsSince1900 - seventyYears;
      // print Unix time:
      //Serial.println(epoch);

      t = epoch;

      struct timeval tv;
      tv.tv_sec = epoch;
      tv.tv_usec = 0;
      settimeofday(&tv, NULL); // Inject into ESP32 system clock

      // Apply the Timezone string
      setenv("TZ", tzInfo, 1);
      tzset();

      updateLocalTime();

      logFileName = "/" + serialNumber + "_log_" + String(timeinfo.tm_year) + "_" + String(timeinfo.tm_mon) + ".csv";
      initializeLogFile();

      ntpMonth = String(timeinfo.tm_mon);
      ntpDay = String(timeinfo.tm_mday);
      ntpYear = String(timeinfo.tm_year);
      dateString = "DATE: " + ntpMonth + "/" + ntpDay + "/" + ntpYear;

      if (firstTimeGet) {
        firstTimeValue = t;

        logPowerOnEvent();
      }

      ethClientSSL.setVerificationTime((unsigned long) (epoch/86400UL) + 719528UL, 0);
      getTimePreviousMillis = getTimeCurrentMillis;
      firstTimeGet = false;
      udpHasTimePacket = false;

      preferences.begin(pnamespace);
      lastSavedMonthTracker = preferences.getInt(lastSavedMonthKey, -1);
      lastSavedYearTracker = preferences.getInt(lastSavedYearKey, -1);
      preferences.end();

      if (lastSavedMonthTracker != timeinfo.tm_mon || lastSavedYearTracker != timeinfo.tm_year) {
        //logFileName = "/" + serialNumber + "_log_" + String(timeinfo.tm_year) + "_" + String(timeinfo.tm_mon) + ".csv";
        //initializeLogFile();

        uploadLogFileName = serialNumber + "_log_" + lastSavedYearTracker + "_" + lastSavedMonthTracker + ".csv";
        logConnect();

        if (sentLogFTP) {
          preferences.begin(pnamespace);
          preferences.putInt(lastSavedMonthKey, timeinfo.tm_mon);
          preferences.putInt(lastSavedYearKey, timeinfo.tm_year);
          preferences.end();
        }
      }

      return true;
    }

    return false;
  }

  return true;
}