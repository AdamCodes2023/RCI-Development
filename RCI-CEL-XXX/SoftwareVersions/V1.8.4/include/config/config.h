#include "M5StackMQTTFTP.h"

void analyzeFTPFileContents(String topic) {
  if (topic.indexOf('-') != -1) {
    serialNumber = topic;
    //*configItems[0] = serialNumber;
  }
  if (topic.indexOf(':') != -1) {
    stringMac = topic;
    //*configItems[1] = stringMac.substring(0, stringMac.length() - 1);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("GID")) {
    groupID = topic.substring(0, topic.length() - 4);
    *configItems[2] = "GID: " + groupID;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("UID")) {
    unitID = topic.substring(0, topic.length() - 4);
    *configItems[3] = "UID: " + unitID;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ION")) {
    IONum = topic.substring(0, topic.length() - 4);
    *configItems[4] = "IO#: " + IONum;
    ioKnown = true;
    rciTitle = "RCI-" + IONum + "00-CEL";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("UPT")) {
    updateTime = topic.substring(0, topic.length() - 4);
    *configItems[21] = "UPDATE: " + updateTime;
    checkForSubscribeInterval = updateTime.toInt();
    checkForPublishInterval = updateTime.toInt();
  }
  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("CN")) {
    consumerName = topic.substring(0, topic.length() - 3);
    *configItems[24] = "NAME: " + consumerName;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI1")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[0] = true;
    } else {
      noHandshakeDigitalInputFeeds[0] = false;
      di1_feed = topic;
      di1_feedACK = di1_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI2")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[1] = true;
    } else {
      noHandshakeDigitalInputFeeds[1] = false;
      di2_feed = topic;
      di2_feedACK = di2_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI3")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[2] = true;
    } else {
      noHandshakeDigitalInputFeeds[2] = false;
      di3_feed = topic;
      di3_feedACK = di3_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI4")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[3] = true;
    } else {
      noHandshakeDigitalInputFeeds[3] = false;
      di4_feed = topic;
      di4_feedACK = di4_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI5")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[4] = true;
    } else {
      noHandshakeDigitalInputFeeds[4] = false;
      di5_feed = topic;
      di5_feedACK = di5_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI6")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[5] = true;
    } else {
      noHandshakeDigitalInputFeeds[5] = false;
      di6_feed = topic;
      di6_feedACK = di6_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI7")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[6] = true;
    } else {
      noHandshakeDigitalInputFeeds[6] = false;
      di7_feed = topic;
      di7_feedACK = di7_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI8")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[7] = true;
    } else {
      noHandshakeDigitalInputFeeds[7] = false;
      di8_feed = topic;
      di8_feedACK = di8_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI1")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[0] = true;
    } else {
      noHandshakeAnalogInputFeeds[0] = false;
      ai1_feed = topic;
      ai1_feedACK = ai1_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI2")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[1] = true;
    } else {
      noHandshakeAnalogInputFeeds[1] = false;
      ai2_feed = topic;
      ai2_feedACK = ai2_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI3")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[2] = true;
    } else {
      noHandshakeAnalogInputFeeds[2] = false;
      ai3_feed = topic;
      ai3_feedACK = ai3_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI4")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[3] = true;
    } else {
      noHandshakeAnalogInputFeeds[3] = false;
      ai4_feed = topic;
      ai4_feedACK = ai4_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI5")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[4] = true;
    } else {
      noHandshakeAnalogInputFeeds[4] = false;
      ai5_feed = topic;
      ai5_feedACK = ai5_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI6")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[5] = true;
    } else {
      noHandshakeAnalogInputFeeds[5] = false;
      ai6_feed = topic;
      ai6_feedACK = ai6_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI7")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[6] = true;
    } else {
      noHandshakeAnalogInputFeeds[6] = false;
      ai7_feed = topic;
      ai7_feedACK = ai7_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI8")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[7] = true;
    } else {
      noHandshakeAnalogInputFeeds[7] = false;
      ai8_feed = topic;
      ai8_feedACK = ai8_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO1")) {
    do1_feed = topic.substring(0, topic.length() - 4);
    *configItems[5] = "DO1: " + do1_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO2")) {
    do2_feed = topic.substring(0, topic.length() - 4);
    *configItems[6] = "DO2: " + do2_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO3")) {
    do3_feed = topic.substring(0, topic.length() - 4);
    *configItems[7] = "DO3: " + do3_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO4")) {
    do4_feed = topic.substring(0, topic.length() - 4);
    *configItems[8] = "DO4: " + do4_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO5")) {
    do5_feed = topic.substring(0, topic.length() - 4);
    *configItems[9] = "DO5: " + do5_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO6")) {
    do6_feed = topic.substring(0, topic.length() - 4);
    *configItems[10] = "DO6: " + do6_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO7")) {
    do7_feed = topic.substring(0, topic.length() - 4);
    *configItems[11] = "DO7: " + do7_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO8")) {
    do8_feed = topic.substring(0, topic.length() - 4);
    *configItems[12] = "DO8: " + do8_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO1")) {
    ao1_feed = topic.substring(0, topic.length() - 4);
    *configItems[13] = "AO1: " + ao1_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO2")) {
    ao2_feed = topic.substring(0, topic.length() - 4);
    *configItems[14] = "AO2: " + ao2_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO3")) {
    ao3_feed = topic.substring(0, topic.length() - 4);
    *configItems[15] = "AO3: " + ao3_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO4")) {
    ao4_feed = topic.substring(0, topic.length() - 4);
    *configItems[16] = "AO4: " + ao4_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO5")) {
    ao5_feed = topic.substring(0, topic.length() - 4);
    *configItems[17] = "AO5: " + ao5_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO6")) {
    ao6_feed = topic.substring(0, topic.length() - 4);
    *configItems[18] = "AO6: " + ao6_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO7")) {
    ao7_feed = topic.substring(0, topic.length() - 4);
    *configItems[19] = "AO7: " + ao7_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO8")) {
    ao8_feed = topic.substring(0, topic.length() - 4);
    *configItems[20] = "AO8: " + ao8_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MBR")) {
    mqttBroker = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MUN")) {
    mqttUsername = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MPW")) {
    mqttPassword = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MPT")) {
    stringMqttPort = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FBR")) {
    ftpBroker = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FPT")) {
    stringFtpPort = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FUN")) {
    ftpUsername = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FPW")) {
    ftpPassword = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FWD")) {
    ftpWorkingDirectory = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ACC")) {
    optAccountID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("APP")) {
    optApplicationID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("SEC")) {
    optSecretID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("RSN")) {
    optRadioSN = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF1")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df1ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do1_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do1_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do1_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF2")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df2ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do2_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do2_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do2_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF3")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df3ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do3_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do3_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do3_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF4")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df4ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do4_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do4_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do4_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF5")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df5ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do5_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do5_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do5_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF6")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df6ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do6_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do6_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do6_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF7")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df7ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do7_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do7_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do7_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF8")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df8ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do8_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do8_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do8_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF1")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af1ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao1_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao1_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF2")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af2ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao2_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao2_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF3")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af3ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao3_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao3_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF4")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af4ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao4_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao4_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF5")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af5ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao5_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao5_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF6")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af6ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao6_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao6_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF7")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af7ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao7_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao7_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF8")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af8ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao8_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao8_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("HB")) {
    heartbeatSubscriptionsString = topic.substring(0, topic.length() - 3);
  }
}

void analyzeSDCardContents() {
  bool state = false;
  int rawCh = 0;
  char ch = 'n';
  String topic = String("");
  while (!state) {
    rawCh = myFile.read();
    if (rawCh == 59) {
      state = true;
    }
    else {
      ch = char(rawCh);
      topic += ch;
    }
  }
  if (topic.indexOf('-') != -1) {
    serialNumber = topic;
    //*configItems[0] = serialNumber;
  }
  if (topic.indexOf(':') != -1) {
    stringMac = topic;
    //*configItems[1] = stringMac.substring(0, stringMac.length() - 1);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("GID")) {
    groupID = topic.substring(0, topic.length() - 4);
    *configItems[2] = "GID: " + groupID;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("UID")) {
    unitID = topic.substring(0, topic.length() - 4);
    *configItems[3] = "UID: " + unitID;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ION")) {
    IONum = topic.substring(0, topic.length() - 4);
    *configItems[4] = "IO#: " + IONum;
    rciTitle = "RCI-" + IONum + "00-CEL";
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("UPT")) {
    updateTime = topic.substring(0, topic.length() - 4);
    *configItems[21] = "UPDATE: " + updateTime;
    checkForSubscribeInterval = updateTime.toInt();
    checkForPublishInterval = updateTime.toInt();
  }
  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("CN")) {
    consumerName = topic.substring(0, topic.length() - 3);
    *configItems[24] = "NAME: " + consumerName;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI1")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[0] = true;
    } else {
      noHandshakeDigitalInputFeeds[0] = false;
      di1_feed = topic;
      di1_feedACK = di1_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI2")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[1] = true;
    } else {
      noHandshakeDigitalInputFeeds[1] = false;
      di2_feed = topic;
      di2_feedACK = di2_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI3")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[2] = true;
    } else {
      noHandshakeDigitalInputFeeds[2] = false;
      di3_feed = topic;
      di3_feedACK = di3_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI4")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[3] = true;
    } else {
      noHandshakeDigitalInputFeeds[3] = false;
      di4_feed = topic;
      di4_feedACK = di4_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI5")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[4] = true;
    } else {
      noHandshakeDigitalInputFeeds[4] = false;
      di5_feed = topic;
      di5_feedACK = di5_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI6")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[5] = true;
    } else {
      noHandshakeDigitalInputFeeds[5] = false;
      di6_feed = topic;
      di6_feedACK = di6_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI7")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[6] = true;
    } else {
      noHandshakeDigitalInputFeeds[6] = false;
      di7_feed = topic;
      di7_feedACK = di7_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DI8")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeDigitalInputFeeds[7] = true;
    } else {
      noHandshakeDigitalInputFeeds[7] = false;
      di8_feed = topic;
      di8_feedACK = di8_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI1")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[0] = true;
    } else {
      noHandshakeAnalogInputFeeds[0] = false;
      ai1_feed = topic;
      ai1_feedACK = ai1_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI2")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[1] = true;
    } else {
      noHandshakeAnalogInputFeeds[1] = false;
      ai2_feed = topic;
      ai2_feedACK = ai2_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI3")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[2] = true;
    } else {
      noHandshakeAnalogInputFeeds[2] = false;
      ai3_feed = topic;
      ai3_feedACK = ai3_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI4")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[3] = true;
    } else {
      noHandshakeAnalogInputFeeds[3] = false;
      ai4_feed = topic;
      ai4_feedACK = ai4_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI5")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[4] = true;
    } else {
      noHandshakeAnalogInputFeeds[4] = false;
      ai5_feed = topic;
      ai5_feedACK = ai5_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI6")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[5] = true;
    } else {
      noHandshakeAnalogInputFeeds[5] = false;
      ai6_feed = topic;
      ai6_feedACK = ai6_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI7")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[6] = true;
    } else {
      noHandshakeAnalogInputFeeds[6] = false;
      ai7_feed = topic;
      ai7_feedACK = ai7_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AI8")) {
    if (topic.substring(0, topic.length() - 4).equalsIgnoreCase("0")) {
      noHandshakeAnalogInputFeeds[7] = true;
    } else {
      noHandshakeAnalogInputFeeds[7] = false;
      ai8_feed = topic;
      ai8_feedACK = ai8_feed + "_ACK";
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO1")) {
    do1_feed = topic.substring(0, topic.length() - 4);
    *configItems[5] = "DO1: " + do1_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO2")) {
    do2_feed = topic.substring(0, topic.length() - 4);
    *configItems[6] = "DO2: " + do2_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO3")) {
    do3_feed = topic.substring(0, topic.length() - 4);
    *configItems[7] = "DO3: " + do3_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO4")) {
    do4_feed = topic.substring(0, topic.length() - 4);
    *configItems[8] = "DO4: " + do4_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO5")) {
    do5_feed = topic.substring(0, topic.length() - 4);
    *configItems[9] = "DO5: " + do5_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO6")) {
    do6_feed = topic.substring(0, topic.length() - 4);
    *configItems[10] = "DO6: " + do6_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO7")) {
    do7_feed = topic.substring(0, topic.length() - 4);
    *configItems[11] = "DO7: " + do7_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DO8")) {
    do8_feed = topic.substring(0, topic.length() - 4);
    *configItems[12] = "DO8: " + do8_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO1")) {
    ao1_feed = topic.substring(0, topic.length() - 4);
    *configItems[13] = "AO1: " + ao1_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO2")) {
    ao2_feed = topic.substring(0, topic.length() - 4);
    *configItems[14] = "AO2: " + ao2_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO3")) {
    ao3_feed = topic.substring(0, topic.length() - 4);
    *configItems[15] = "AO3: " + ao3_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO4")) {
    ao4_feed = topic.substring(0, topic.length() - 4);
    *configItems[16] = "AO4: " + ao4_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO5")) {
    ao5_feed = topic.substring(0, topic.length() - 4);
    *configItems[17] = "AO5: " + ao5_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO6")) {
    ao6_feed = topic.substring(0, topic.length() - 4);
    *configItems[18] = "AO6: " + ao6_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO7")) {
    ao7_feed = topic.substring(0, topic.length() - 4);
    *configItems[19] = "AO7: " + ao7_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AO8")) {
    ao8_feed = topic.substring(0, topic.length() - 4);
    *configItems[20] = "AO8: " + ao8_feed;
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MBR")) {
    mqttBroker = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MUN")) {
    mqttUsername = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MPW")) {
    mqttPassword = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("MPT")) {
    stringMqttPort = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FBR")) {
    ftpBroker = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FPT")) {
    stringFtpPort = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FUN")) {
    ftpUsername = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FPW")) {
    ftpPassword = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("FWD")) {
    ftpWorkingDirectory = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("ACC")) {
    optAccountID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("APP")) {
    optApplicationID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("SEC")) {
    optSecretID = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("RSN")) {
    optRadioSN = topic.substring(0, topic.length() - 4);
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF1")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df1ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do1_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do1_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do1_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF2")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df2ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do2_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do2_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do2_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF3")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df3ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do3_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do3_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do3_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF4")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df4ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do4_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do4_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do4_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF5")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df5ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do5_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do5_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do5_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF6")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df6ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do6_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do6_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do6_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF7")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df7ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do7_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do7_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do7_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("DF8")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    df8ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("ON")) {
      do8_fail_default = 1;
    } else if (analyzedFailValue.equalsIgnoreCase("OFF")) {
      do8_fail_default = 0;
    } else if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      do8_fail_default = 2;
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF1")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af1ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao1_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao1_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF2")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af2ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao2_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao2_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF3")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af3ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao3_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao3_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF4")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af4ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao4_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao4_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF5")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af5ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao5_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao5_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF6")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af6ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao6_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao6_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF7")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af7ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao7_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao7_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 3, topic.length()).equalsIgnoreCase("AF8")) {
    analyzedFailValue = topic.substring(0, topic.length() - 4);
    af8ReadValue = analyzedFailValue;
    if (analyzedFailValue.equalsIgnoreCase("LAST")) {
      ao8_fail_default = 30.0;
    } else if (analyzedFailValue.toDouble() != 0.0) {
      ao8_fail_default = analyzedFailValue.toDouble();
    }
  }
  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("HB")) {
    heartbeatSubscriptionsString = topic.substring(0, topic.length() - 3);
  }
}

void createHeartbeatSubscriptionArrays(String subscriptions) {
  subCount = 0;
  heartbeatCheckUnitID = String("");
  for (int i = 0; i < subscriptions.length(); i++) {
    if (subscriptions[i] == ',' && subCount < maxHeartbeatChecks) {
      *heartbeat_check_feeds[subCount] = groupID + "_" + heartbeatCheckUnitID + "_" + "HB";
      heartbeatCheckPreviousMillis[subCount] = 1;
      heartbeatCheckCurrentMillis[subCount] = 1;
      subCount++;
      heartbeatCheckUnitID = String("");
    } else {
      heartbeatCheckUnitID += subscriptions[i];
    }
  }
  if (heartbeatCheckUnitID.length() != 0 && subCount < maxHeartbeatChecks) {
    *heartbeat_check_feeds[subCount] = groupID + "_" + heartbeatCheckUnitID + "_" + "HB";
    heartbeatCheckPreviousMillis[subCount] = 1;
    heartbeatCheckCurrentMillis[subCount] = 1;
    subCount++;
    heartbeatCheckUnitID = String("");
  }
}

void checkHeartbeatSubscriptionArrays(String subscription) {
  for (int i = 0; i < subCount; i++) {
    String tempHeartbeatCheckFeed = *heartbeat_check_feeds[i];
    if (tempHeartbeatCheckFeed.substring(tempHeartbeatCheckFeed.indexOf("_") + 1, tempHeartbeatCheckFeed.indexOf("_", tempHeartbeatCheckFeed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
      heartbeatCheckPreviousMillis[i] = millis();
      heartbeatCheckAlreadySetFailDefaults[i] = false;
    }
  }

  if (IONum.toInt() >= 1) {
    if (analogOutOneSuccess) {
      if (ao1_feed.substring(ao1_feed.indexOf("_") + 1, ao1_feed.indexOf("_", ao1_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao1CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do1_feed.substring(do1_feed.indexOf("_") + 1, do1_feed.indexOf("_", do1_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do1CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 2) {
    if (analogOutOneSuccess) {
      if (ao2_feed.substring(ao2_feed.indexOf("_") + 1, ao2_feed.indexOf("_", ao2_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao2CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do2_feed.substring(do2_feed.indexOf("_") + 1, do2_feed.indexOf("_", do2_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do2CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 3) {
    if (analogOutOneSuccess) {
      if (ao3_feed.substring(ao3_feed.indexOf("_") + 1, ao3_feed.indexOf("_", ao3_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao3CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do3_feed.substring(do3_feed.indexOf("_") + 1, do3_feed.indexOf("_", do3_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do3CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 4) {
    if (analogOutOneSuccess) {
      if (ao4_feed.substring(ao4_feed.indexOf("_") + 1, ao4_feed.indexOf("_", ao4_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao4CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do4_feed.substring(do4_feed.indexOf("_") + 1, do4_feed.indexOf("_", do4_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do4CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 5) {
    if (analogOutTwoSuccess) {
      if (ao5_feed.substring(ao5_feed.indexOf("_") + 1, ao5_feed.indexOf("_", ao5_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao5CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do5_feed.substring(do5_feed.indexOf("_") + 1, do5_feed.indexOf("_", do5_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do5CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 6) {
    if (analogOutTwoSuccess) {
      if (ao6_feed.substring(ao6_feed.indexOf("_") + 1, ao6_feed.indexOf("_", ao6_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao6CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do6_feed.substring(do6_feed.indexOf("_") + 1, do6_feed.indexOf("_", do6_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do6CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 7) {
    if (analogOutTwoSuccess) {
      if (ao7_feed.substring(ao7_feed.indexOf("_") + 1, ao7_feed.indexOf("_", ao7_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao7CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do7_feed.substring(do7_feed.indexOf("_") + 1, do7_feed.indexOf("_", do7_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do7CommFailTriggered = false;
      }
    }
  }

  if (IONum.toInt() >= 8) {
    if (analogOutTwoSuccess) {
      if (ao8_feed.substring(ao8_feed.indexOf("_") + 1, ao8_feed.indexOf("_", ao8_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        ao8CommFailTriggered = false;
      }
    }

    if (digitalOutputSuccess) {
      if (do8_feed.substring(do8_feed.indexOf("_") + 1, do8_feed.indexOf("_", do8_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        do8CommFailTriggered = false;
      }
    }
  }
}

void setGroupMemberLossOfCommunicationDefaults(String subscription) {
  if (IONum.toInt() >= 1) {
    if (analogOutOneSuccess) {
      if (ao1_feed.substring(ao1_feed.indexOf("_") + 1, ao1_feed.indexOf("_", ao1_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao1_fail_default != 30.0) {
          Wire.beginTransmission(0x1f);
          Wire.write(byte(0));
          Wire.write(byte(int(ao1_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao1_fail_default * 3276.75)));
          Wire.endTransmission();
          ao1_value = String(int(ao1_fail_default * 3276.75));
        }
        ao1CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do1_feed.substring(do1_feed.indexOf("_") + 1, do1_feed.indexOf("_", do1_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do1_fail_default != 2) {
          pcfw1.digitalWrite(0, !bool(do1_fail_default));
          do1_value = String(do1_fail_default);
        }
        do1CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 2) {
    if (analogOutOneSuccess) {
      if (ao2_feed.substring(ao2_feed.indexOf("_") + 1, ao2_feed.indexOf("_", ao2_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao2_fail_default != 30.0) {
          Wire.beginTransmission(0x1f);
          Wire.write(byte(1));
          Wire.write(byte(int(ao2_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao2_fail_default * 3276.75)));
          Wire.endTransmission();
          ao2_value = String(int(ao2_fail_default * 3276.75));
        }
        ao2CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do2_feed.substring(do2_feed.indexOf("_") + 1, do2_feed.indexOf("_", do2_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do2_fail_default != 2) {
          pcfw1.digitalWrite(1, !bool(do2_fail_default));
          do2_value = String(do2_fail_default);
        }
        do2CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 3) {
    if (analogOutOneSuccess) {
      if (ao3_feed.substring(ao3_feed.indexOf("_") + 1, ao3_feed.indexOf("_", ao3_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao3_fail_default != 30.0) {
          Wire.beginTransmission(0x1f);
          Wire.write(byte(2));
          Wire.write(byte(int(ao3_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao3_fail_default * 3276.75)));
          Wire.endTransmission();
          ao3_value = String(int(ao3_fail_default * 3276.75));
        }
        ao3CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do3_feed.substring(do3_feed.indexOf("_") + 1, do3_feed.indexOf("_", do3_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do3_fail_default != 2) {
          pcfw1.digitalWrite(2, !bool(do3_fail_default));
          do3_value = String(do3_fail_default);
        }
        do3CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 4) {
    if (analogOutOneSuccess) {
      if (ao4_feed.substring(ao4_feed.indexOf("_") + 1, ao4_feed.indexOf("_", ao4_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao4_fail_default != 30.0) {
          Wire.beginTransmission(0x1f);
          Wire.write(byte(3));
          Wire.write(byte(int(ao4_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao4_fail_default * 3276.75)));
          Wire.endTransmission();
          ao4_value = String(int(ao4_fail_default * 3276.75));
        }
        ao4CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do4_feed.substring(do4_feed.indexOf("_") + 1, do4_feed.indexOf("_", do4_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do4_fail_default != 2) {
          pcfw1.digitalWrite(3, !bool(do4_fail_default));
          do4_value = String(do4_fail_default);
        }
        do4CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 5) {
    if (analogOutTwoSuccess) {
      if (ao5_feed.substring(ao5_feed.indexOf("_") + 1, ao5_feed.indexOf("_", ao5_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao5_fail_default != 30.0) {
          Wire.beginTransmission(0x1c);
          Wire.write(byte(0));
          Wire.write(byte(int(ao5_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao5_fail_default * 3276.75)));
          Wire.endTransmission();
          ao5_value = String(int(ao5_fail_default * 3276.75));
        }
        ao5CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do5_feed.substring(do5_feed.indexOf("_") + 1, do5_feed.indexOf("_", do5_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do5_fail_default != 2) {
          pcfw1.digitalWrite(4, !bool(do5_fail_default));
          do5_value = String(do5_fail_default);
        }
        do5CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 6) {
    if (analogOutTwoSuccess) {
      if (ao6_feed.substring(ao6_feed.indexOf("_") + 1, ao6_feed.indexOf("_", ao6_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao6_fail_default != 30.0) {
          Wire.beginTransmission(0x1c);
          Wire.write(byte(1));
          Wire.write(byte(int(ao6_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao6_fail_default * 3276.75)));
          Wire.endTransmission();
          ao6_value = String(int(ao6_fail_default * 3276.75));
        }
        ao6CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do6_feed.substring(do6_feed.indexOf("_") + 1, do6_feed.indexOf("_", do6_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do6_fail_default != 2) {
          pcfw1.digitalWrite(5, !bool(do6_fail_default));
          do6_value = String(do6_fail_default);
        }
        do6CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 7) {
    if (analogOutTwoSuccess) {
      if (ao7_feed.substring(ao7_feed.indexOf("_") + 1, ao7_feed.indexOf("_", ao7_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao7_fail_default != 30.0) {
          Wire.beginTransmission(0x1c);
          Wire.write(byte(2));
          Wire.write(byte(int(ao7_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao7_fail_default * 3276.75)));
          Wire.endTransmission();
          ao7_value = String(int(ao7_fail_default * 3276.75));
        }
        ao7CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do7_feed.substring(do7_feed.indexOf("_") + 1, do7_feed.indexOf("_", do7_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do7_fail_default != 2) {
          pcfw1.digitalWrite(6, !bool(do7_fail_default));
          do7_value = String(do7_fail_default);
        }
        do7CommFailTriggered = true;
      }
    }
  }

  if (IONum.toInt() >= 8) {
    if (analogOutTwoSuccess) {
      if (ao8_feed.substring(ao8_feed.indexOf("_") + 1, ao8_feed.indexOf("_", ao8_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (ao8_fail_default != 30.0) {
          Wire.beginTransmission(0x1c);
          Wire.write(byte(3));
          Wire.write(byte(int(ao8_fail_default * 3276.75) >> 8));
          Wire.write(byte(int(ao8_fail_default * 3276.75)));
          Wire.endTransmission();
          ao8_value = String(int(ao8_fail_default * 3276.75));
        }
        ao8CommFailTriggered = true;
      }
    }

    if (digitalOutputSuccess) {
      if (do8_feed.substring(do8_feed.indexOf("_") + 1, do8_feed.indexOf("_", do8_feed.indexOf("_") + 1)).equalsIgnoreCase(subscription)) {
        if (do8_fail_default != 2) {
          pcfw1.digitalWrite(7, !bool(do8_fail_default));
          do8_value = String(do8_fail_default);
        }
        do8CommFailTriggered = true;
      }
    }
  }
}