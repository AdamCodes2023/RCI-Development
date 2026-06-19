#include "M5StackRadio.h"

void inputToOutputCopyRoutine() {
  //TEST DIGITAL IO FUNCTIONALITY
  if (digitalInputSuccess) {
    pcfr0Test = int(pcfr.digitalRead(0));
    pcfr1Test = int(pcfr.digitalRead(1));
    pcfr2Test = int(pcfr.digitalRead(2));
    pcfr3Test = int(pcfr.digitalRead(3));
    pcfr4Test = int(pcfr.digitalRead(4));
    pcfr5Test = int(pcfr.digitalRead(5));
    pcfr6Test = int(pcfr.digitalRead(6));
    pcfr7Test = int(pcfr.digitalRead(7));
  }

  if (digitalOutputSuccess) {
    pcfw1.digitalWrite(0, !bool(pcfr0Test));
    pcfw1.digitalWrite(1, !bool(pcfr1Test));
    pcfw1.digitalWrite(2, !bool(pcfr2Test));
    pcfw1.digitalWrite(3, !bool(pcfr3Test));
    pcfw1.digitalWrite(4, !bool(pcfr4Test));
    pcfw1.digitalWrite(5, !bool(pcfr5Test));
    pcfw1.digitalWrite(6, !bool(pcfr6Test));
    pcfw1.digitalWrite(7, !bool(pcfr7Test));
  }

  //if (digitalDebugSuccess) {
    //pcfw2.digitalWrite(0, !bool(pcfr7Test));
    //pcfw2.digitalWrite(1, !bool(pcfr7Test));
  //}


  //TEST AD5665R DAC SCALABILITY
  if (analogInOneSuccess) {
    testadc0 = ads1115.readADC_SingleEnded(0);

    //M5.Lcd.drawString(String(testadc0), 0, 210, 1);
    //M5.Lcd.drawString(String(int(testadc0 * 2.048)), 0, 210, 1);
    //M5.Lcd.drawString(String(int(testadc1 * 2.048)), 0, 210, 1);

    testadc0 = int(testadc0 * 2.048);
    if (testadc0 < 0) {
      testadc0 = 0;
    }
    if (testadc0 > 65535) {
      testadc0 = 65535;
    }

    testadc1 = ads1115.readADC_SingleEnded(1);
    testadc1 = int(testadc1 * 2.048);
    if (testadc1 < 0) {
      testadc1 = 0;
    }
    if (testadc1 > 65535) {
      testadc1 = 65535;
    }

    testadc2 = ads1115.readADC_SingleEnded(2);
    testadc2 = int(testadc2 * 2.048);
    if (testadc2 < 0) {
      testadc2 = 0;
    }
    if (testadc2 > 65535) {
      testadc2 = 65535;
    }

    testadc3 = ads1115.readADC_SingleEnded(3);
    testadc3 = int(testadc3 * 2.048);
    if (testadc3 < 0) {
      testadc3 = 0;
    }
    if (testadc3 > 65535) {
      testadc3 = 65535;
    }
  }

  if (analogInTwoSuccess) {
    testadc4 = ads1115second.readADC_SingleEnded(0);
    testadc4 = int(testadc4 * 2.048);
    if (testadc4 < 0) {
      testadc4 = 0;
    }
    if (testadc4 > 65535) {
      testadc4 = 65535;
    }

    testadc5 = ads1115second.readADC_SingleEnded(1);
    testadc5 = int(testadc5 * 2.048);
    if (testadc5 < 0) {
      testadc5 = 0;
    }
    if (testadc5 > 65535) {
      testadc5 = 65535;
    }

    testadc6 = ads1115second.readADC_SingleEnded(2);
    testadc6 = int(testadc6 * 2.048);
    if (testadc6 < 0) {
      testadc6 = 0;
    }
    if (testadc6 > 65535) {
      testadc6 = 65535;
    }

    testadc7 = ads1115second.readADC_SingleEnded(3);
    testadc7 = int(testadc7 * 2.048);
    if (testadc7 < 0) {
      testadc7 = 0;
    }
    if (testadc7 > 65535) {
      testadc7 = 65535;
    }
  }


  if (analogOutOneSuccess) {
    Wire.beginTransmission(0x1f);
    Wire.write(byte(0));
    Wire.write(byte(testadc0 >> 8));
    Wire.write(byte(testadc0));
    Wire.endTransmission();
  
    Wire.beginTransmission(0x1f);
    Wire.write(byte(1));
    Wire.write(byte(testadc1 >> 8));
    Wire.write(byte(testadc1));
    Wire.endTransmission();

    Wire.beginTransmission(0x1f);
    Wire.write(byte(2));
    Wire.write(byte(testadc2 >> 8));
    Wire.write(byte(testadc2));
    Wire.endTransmission();
  
    Wire.beginTransmission(0x1f);
    Wire.write(byte(3));
    Wire.write(byte(testadc3 >> 8));
    Wire.write(byte(testadc3));
    Wire.endTransmission();
  }

  if (analogOutTwoSuccess) {
    Wire.beginTransmission(0x1c);
    Wire.write(byte(0));
    Wire.write(byte(testadc4 >> 8));
    Wire.write(byte(testadc4));
    Wire.endTransmission();
  
    Wire.beginTransmission(0x1c);
    Wire.write(byte(1));
    Wire.write(byte(testadc5 >> 8));
    Wire.write(byte(testadc5));
    Wire.endTransmission();

    Wire.beginTransmission(0x1c);
    Wire.write(byte(2));
    Wire.write(byte(testadc6 >> 8));
    Wire.write(byte(testadc6));
    Wire.endTransmission();
  
    Wire.beginTransmission(0x1c);
    Wire.write(byte(3));
    Wire.write(byte(testadc7 >> 8));
    Wire.write(byte(testadc7));
    Wire.endTransmission();
  }
}

void configConnect() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("RECEIVING", 65, 120, 1);
  M5.Lcd.drawString("CONFIG INFO", 60, 170, 1);

  delay(500);

  //GET CONFIG INFO?
  String response = String("");

  String FTPKeyword = "";
  for (int i = 0; i < response.length(); i++) {
    String character = response.substring(i, i + 1);
    if (character.equalsIgnoreCase(";")) {
      analyzeFTPFileContents(FTPKeyword);
      FTPKeyword = "";
    }
    else {
      FTPKeyword += character;
    }
  }  

  if (startUpMode) {
    for (int i = 1; i <= IONum.toInt(); i++) {
      String di_feed = groupID + "_" + unitID + "_DI" + i;
      if (noHandshakeDigitalInputFeeds[i - 1]) {
        di_feed = globalZeroText + "_DI" + i;
      }
      *di_feeds[i - 1] = di_feed;

      String ai_feed = groupID + "_" + unitID + "_AI" + i;
      if (noHandshakeAnalogInputFeeds[i - 1]) {
        ai_feed = globalZeroText + "_AI" + i;
      }
      *ai_feeds[i - 1] = ai_feed;
    }
  }

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("CONFIG INFO", 40, 0, 1);
  cycleConfigItems(viewConfigItemsIterator);
}

void confConnect() {
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("RECEIVING", 65, 120, 1);
  M5.Lcd.drawString("CONFIG INFO", 60, 170, 1);

  delay(500);

  //GET CONFIG INFO?
  String response = String("");

  String FTPKeyword = "";
  for (int i = 0; i < response.length(); i++) {
    String character = response.substring(i, i + 1);
    if (character.equalsIgnoreCase(";")) {
      analyzeFTPFileContents(FTPKeyword);
      FTPKeyword = "";
    }
    else {
      FTPKeyword += character;
    }
  }

  returnToNormalOperation();
}

void returnToNormalOperation() {
  cycleCounter = 0;
  cyclingPaused = false;
  triggerSound = false;
  normalMode = true;
  cfgServerMode = false;
  copyMode = false;
  configMenu1 = false;
  configMenu2 = false;
  configMenu3 = false;
  warningMenu1 = false;
  warningMenu2 = false;
  centerCyclingPausePressed = false;
  centerCyclingScrollPressed = false;
  centerPressedOnce = false;
  leftCyclingPausePressed = false;
  leftCyclingScrollPressed = false;
  leftPressedOnce = false;
  leftPressedTwice = false;
  leftPressedThree = false;
  rightCyclingUnpausePressed = false;
  rightPressedOnce = false;
  rightPressedTwice = false;
  rightPressedThree = false;
  rightPressedFour = false;
  viewConfigItemsIterator = 0;
  configMenu1Iterator = 0;
  hasConfigInfo = true;
  ioKnown = false;

  M5.Lcd.fillRect(0, 190, 200, 50, BLACK);
  M5.Lcd.drawString("NORMAL MODE", 10, 200, 1);

  //mcp.setChannelValue(MCP4728_CHANNEL_A, (ai1_value.toInt() * 2) >> 4, MCP4728_VREF_INTERNAL,
  //                  MCP4728_GAIN_2X);
  //mcp.setChannelValue(MCP4728_CHANNEL_B, (ai2_value.toInt() * 2) >> 4, MCP4728_VREF_INTERNAL,
  //                  MCP4728_GAIN_2X);

  if (digitalOutputSuccess) {
    pcfw1.digitalWrite(0, !bool(do1_value.toInt()));
    pcfw1.digitalWrite(1, !bool(do2_value.toInt()));
    pcfw1.digitalWrite(2, !bool(do3_value.toInt()));
    pcfw1.digitalWrite(3, !bool(do4_value.toInt()));
    pcfw1.digitalWrite(4, !bool(do5_value.toInt()));
    pcfw1.digitalWrite(5, !bool(do6_value.toInt()));
    pcfw1.digitalWrite(6, !bool(do7_value.toInt()));
    pcfw1.digitalWrite(7, !bool(do8_value.toInt()));
  }
      
  if (analogOutOneSuccess) {
    Wire.beginTransmission(0x1f);
    Wire.write(byte(0));
    Wire.write(byte(ao1_value.toInt() >> 8));
    Wire.write(byte(ao1_value.toInt()));
    Wire.endTransmission();

    Wire.beginTransmission(0x1f);
    Wire.write(byte(1));
    Wire.write(byte(ao2_value.toInt() >> 8));
    Wire.write(byte(ao2_value.toInt()));
    Wire.endTransmission();

    Wire.beginTransmission(0x1f);
    Wire.write(byte(2));
    Wire.write(byte(ao3_value.toInt() >> 8));
    Wire.write(byte(ao3_value.toInt()));
    Wire.endTransmission();

    Wire.beginTransmission(0x1f);
    Wire.write(byte(3));
    Wire.write(byte(ao4_value.toInt() >> 8));
    Wire.write(byte(ao4_value.toInt()));
    Wire.endTransmission();
  }

  if (analogOutTwoSuccess) {
    Wire.beginTransmission(0x1c);
    Wire.write(byte(0));
    Wire.write(byte(ao5_value.toInt() >> 8));
    Wire.write(byte(ao5_value.toInt()));
    Wire.endTransmission();

    Wire.beginTransmission(0x1c);
    Wire.write(byte(1));
    Wire.write(byte(ao6_value.toInt() >> 8));
    Wire.write(byte(ao6_value.toInt()));
    Wire.endTransmission();

    Wire.beginTransmission(0x1c);
    Wire.write(byte(2));
    Wire.write(byte(ao7_value.toInt() >> 8));
    Wire.write(byte(ao7_value.toInt()));
    Wire.endTransmission();

    Wire.beginTransmission(0x1c);
    Wire.write(byte(3));
    Wire.write(byte(ao8_value.toInt() >> 8));
    Wire.write(byte(ao8_value.toInt()));
    Wire.endTransmission();
  }
      
  if (digitalDebugSuccess) {
    pcfw2.digitalWrite(0, false);
  }

  for (int i = 1; i <= IONum.toInt(); i++) {
    String di_feed = groupID + "_" + unitID + "_DI" + i;
    if (noHandshakeDigitalInputFeeds[i - 1]) {
      di_feed = globalZeroText + "_DI" + i;
    }
    *di_feeds[i - 1] = di_feed;

    String ai_feed = groupID + "_" + unitID + "_AI" + i;
    if (noHandshakeAnalogInputFeeds[i - 1]) {
      ai_feed = globalZeroText + "_AI" + i;
    }
    *ai_feeds[i - 1] = ai_feed;
  }

  myFile = SD.open(sdConfigFileName, FILE_WRITE);
  myFile.print(groupID + "_GID;" + unitID + "_UID;" + IONum + "_ION;" + updateTime + "_UPT;" + consumerName + "_CN;" +
  *di_feeds[0] + ";" + *di_feeds[1] + ";" + *di_feeds[2] + ";" + *di_feeds[3] + ";" + *di_feeds[4] + ";" + *di_feeds[5] + ";" + *di_feeds[6] + ";" + *di_feeds[7] + ";" +
  *ai_feeds[0] + ";" + *ai_feeds[1] + ";" + *ai_feeds[2] + ";" + *ai_feeds[3] + ";" + *ai_feeds[4] + ";" + *ai_feeds[5] + ";" + *ai_feeds[6] + ";" + *ai_feeds[7] + ";" +
  do1_feed + "_DO1;" + do2_feed + "_DO2;" + do3_feed + "_DO3;" + do4_feed + "_DO4;" + do5_feed + "_DO5;" + do6_feed + "_DO6;" + do7_feed + "_DO7;" + do8_feed + "_DO8;" +
  ao1_feed + "_AO1;" + ao2_feed + "_AO2;" + ao3_feed + "_AO3;" + ao4_feed + "_AO4;" + ao5_feed + "_AO5;" + ao6_feed + "_AO6;" + ao7_feed + "_AO7;" + ao8_feed + "_AO8;" +
  df1ReadValue + "_DF1;" + df2ReadValue + "_DF2;" + df3ReadValue + "_DF3;" + df4ReadValue + "_DF4;" + df5ReadValue + "_DF5;" + df6ReadValue + "_DF6;" + df7ReadValue + "_DF7;" + df8ReadValue + "_DF8;" +
  af1ReadValue + "_AF1;" + af2ReadValue + "_AF2;" + af3ReadValue + "_AF3;" + af4ReadValue + "_AF4;" + af5ReadValue + "_AF5;" + af6ReadValue + "_AF6;" + af7ReadValue + "_AF7;" + af8ReadValue + "_AF8;" +
  heartbeatSubscriptionsString + "_HB;");
  myFile.close();
  //ESP.restart();

  di1_feed = *di_feeds[0];
  di2_feed = *di_feeds[1];
  di3_feed = *di_feeds[2];
  di4_feed = *di_feeds[3];
  di5_feed = *di_feeds[4];
  di6_feed = *di_feeds[5];
  di7_feed = *di_feeds[6];
  di8_feed = *di_feeds[7];

  ai1_feed = *ai_feeds[0];
  ai2_feed = *ai_feeds[1];
  ai3_feed = *ai_feeds[2];
  ai4_feed = *ai_feeds[3];
  ai5_feed = *ai_feeds[4];
  ai6_feed = *ai_feeds[5];
  ai7_feed = *ai_feeds[6];
  ai8_feed = *ai_feeds[7];

  delay(1000);
  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
}

void reconnectRadio() {
  if (!reconnectFirstMessageStatus) {
    //FIRST CONNECTION ATTEMPT SCREEN?
    reconnectFirstMessageStatus = true;
  }

  confUpdateStep1 = false;
  confUpdateStep2 = false;
  internalUpdateStep1 = false;
  internalUpdateStep2 = false;
  credUpdateStep1 = false;
  credUpdateStep2 = false;
  apiUpdateStep1 = false;
  apiUpdateStep2 = false;
  confUpdateStep1PubOnce = false;
  confUpdateStep2PubOnce = false;
  internalUpdateStep1PubOnce = false;
  internalUpdateStep2PubOnce = false;
  credUpdateStep1PubOnce = false;
  credUpdateStep2PubOnce = false;
  apiUpdateStep1PubOnce = false;
  apiUpdateStep2PubOnce = false;

  config_update_feed = serialNumber + "_configUpdate";
  internal_update_feed = serialNumber + "_internalUpdate";
  credential_update_feed = serialNumber + "_credUpdate";
  api_update_feed = serialNumber + "_apiUpdate";

  createHeartbeatSubscriptionArrays(heartbeatSubscriptionsString);
  
  if (!reconnect) {
    //NEXT STEP SCREEN?
  }

  if (!reconnect) {
    //CONNECTION FAILED SCREEN?
    reconnect = true;
    //return;
  }

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("CONNECTION SUCCESS", 0, 120, 1);
  M5.Lcd.drawString("LOADING", 90, 170, 1);
  delay(1000);

  // set the message receive callback
  //RADIO ON MESSAGE?

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  reconnect = false;
  reconnectFirstMessageStatus = false;

  cycleCounter = 0;
  cyclingPaused = false;
  cycleComponentValues();

  cycleComponentsPreviousMillis = millis();

  for (int i = 0; i < subCount; i++) {
    heartbeatCheckPreviousMillis[i] = millis();
  }

  sentRadioString = groupID + "_" + unitID + "#";
}