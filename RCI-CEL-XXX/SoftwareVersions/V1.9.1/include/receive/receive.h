#include "M5StackMQTTFTP.h"

void callback(char* topic, byte* payload, unsigned int length) {
  ;
}

void onMqttMessage(int messageSize) {
  reconnectCount = 0;

  String message;
  message = "";
  // we received a message, print out the topic and contents

  String topic;
  topic = "";
  topic = mqttClient.messageTopic();

  // use the Stream interface to print the contents
  while (mqttClient.available()) {
    message += ((char)mqttClient.read());
  }

  Serial.println(topic);
  Serial.println(message);

  if (topic.substring(topic.length() - 2, topic.length()).equalsIgnoreCase("HB")) {
    checkHeartbeatSubscriptionArrays(topic.substring(topic.indexOf("_") + 1, topic.indexOf("_", topic.indexOf("_") + 1)));
  }

  if (topic.substring(topic.length() - 1, topic.length()).equalsIgnoreCase("p")) {
    subConnectedRecv = true;

    publishAllc = true;
  }
  if (topic.substring(topic.length() - 5, topic.length()).equalsIgnoreCase("p_ACK")) {
    pubConnectedRecv = true;
    pubConnectedSent = false;
    pubConnectedLoopCount = 0;
  }

  if (topic.substring(topic.length() - 12, topic.length()).equalsIgnoreCase("configUpdate")) {
    //subConfRecv = true;

    if (message.toInt() == 1) {
      confUpdateStep1 = true;
      confUpdateStep1PubOnce = true;
    }
    if (message.toInt() == 3 && confUpdateStep1) {
      confUpdateStep2 = true;
      confUpdateStep2PubOnce = true;
    }
  }
  /*
  if () {
    //pubConfRecv = true;
  }
  */

  if (topic.substring(topic.length() - 14, topic.length()).equalsIgnoreCase("internalUpdate")) {
    //subInternalRecv = true;

    if (message.toInt() == 1) {
      internalUpdateStep1 = true;
      internalUpdateStep1PubOnce = true;
    }
    if (message.toInt() == 3 && internalUpdateStep1) {
      internalUpdateStep2 = true;
      internalUpdateStep2PubOnce = true;
    }
  }
  /*
  if () {
    //pubInternalRecv = true
  }
  */

  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase("credUpdate")) {
    //subCredRecv = true;

    if (message.toInt() == 1) {
      credUpdateStep1 = true;
      credUpdateStep1PubOnce = true;
    }
    if (message.toInt() == 3 && credUpdateStep1) {
      credUpdateStep2 = true;
      credUpdateStep2PubOnce = true;
    }
  }
  /*
  if () {
    //pubCredRecv = true;
  }
  */

  if (topic.substring(topic.length() - 9, topic.length()).equalsIgnoreCase("apiUpdate")) {
    //subApiRecv = true;

    if (message.toInt() == 1) {
      apiUpdateStep1 = true;
      apiUpdateStep1PubOnce = true;
    }
    if (message.toInt() == 3 && apiUpdateStep1) {
      apiUpdateStep2 = true;
      apiUpdateStep2PubOnce = true;
    }
  }
  /*
  if () {
    //pubApiRecv = true
  }
  */

  if (topic.substring(topic.length() - 7, topic.length()).equalsIgnoreCase("version")) {
    if (message.toInt() == 1) {
      publishSoftwareVersionFlag = true;
    }
  }

  if (topic.substring(topic.length() - 7, topic.length()).equalsIgnoreCase("modemSN")) {
    if (message.toInt() == 1) {
      publishModemSerialNumberFlag = true;
    }
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do1_feed.substring(do1_feed.length() - 6, do1_feed.length()))) {
    do1Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(0, !bool(message.toInt()));
    }
    do1_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di1_feedACK.substring(di1_feedACK.length() - 10, di1_feedACK.length()))) {
    di1Recv = true;
    di1Sent = false;
    di1LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do2_feed.substring(do2_feed.length() - 6, do2_feed.length()))) {
    do2Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(1, !bool(message.toInt()));
    }
    do2_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di2_feedACK.substring(di2_feedACK.length() - 10, di2_feedACK.length()))) {
    di2Recv = true;
    di2Sent = false;
    di2LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do3_feed.substring(do3_feed.length() - 6, do3_feed.length()))) {
    do3Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(2, !bool(message.toInt()));
    }
    do3_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di3_feedACK.substring(di3_feedACK.length() - 10, di3_feedACK.length()))) {
    di3Recv = true;
    di3Sent = false;
    di3LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do4_feed.substring(do4_feed.length() - 6, do4_feed.length()))) {
    do4Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(3, !bool(message.toInt()));
    }
    do4_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di4_feedACK.substring(di4_feedACK.length() - 10, di4_feedACK.length()))) {
    di4Recv = true;
    di4Sent = false;
    di4LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do5_feed.substring(do5_feed.length() - 6, do5_feed.length()))) {
    do5Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(4, !bool(message.toInt()));
    }
    do5_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di5_feedACK.substring(di5_feedACK.length() - 10, di5_feedACK.length()))) {
    di5Recv = true;
    di5Sent = false;
    di5LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do6_feed.substring(do6_feed.length() - 6, do6_feed.length()))) {
    do6Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(5, !bool(message.toInt()));
    }
    do6_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di6_feedACK.substring(di6_feedACK.length() - 10, di6_feedACK.length()))) {
    di6Recv = true;
    di6Sent = false;
    di6LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do7_feed.substring(do7_feed.length() - 6, do7_feed.length()))) {
    do7Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(6, !bool(message.toInt()));
    }
    do7_value = message;
    //M5.Lcd.fillRect(90, 0, 300, 50, BLACK);
    //M5.Lcd.drawString(di1_value, 90, 0, 2);
    //replaceText(90, 0, 300, 50, 2 di1_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di7_feedACK.substring(di7_feedACK.length() - 10, di7_feedACK.length()))) {
    di7Recv = true;
    di7Sent = false;
    di7LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(do8_feed.substring(do8_feed.length() - 6, do8_feed.length()))) {
    do8Recv = true;

    if (digitalOutputSuccess) {
      pcfw1.digitalWrite(7, !bool(message.toInt()));
    }
    do8_value = message;
    //M5.Lcd.fillRect(90, 40, 300, 50, BLACK);
    //M5.Lcd.drawString(di2_value, 90, 40, 2);
    //replaceText(90, 40, 300, 50, 2 di2_value);
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(di8_feedACK.substring(di8_feedACK.length() - 10, di8_feedACK.length()))) {
    di8Recv = true;
    di8Sent = false;
    di8LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao1_feed.substring(ao1_feed.length() - 6, ao1_feed.length()))) {
    ao1Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao1_value = "0";

      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(0));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao1_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai1_feedACK.substring(ai1_feedACK.length() - 10, ai1_feedACK.length()))) {
    ai1Recv = true;
    ai1Sent = false;
    ai1LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao2_feed.substring(ao2_feed.length() - 6, ao2_feed.length()))) {
    ao2Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(1));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }
      
      //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao2_value = "0";

      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(1));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao2_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai2_feedACK.substring(ai2_feedACK.length() - 10, ai2_feedACK.length()))) {
    ai2Recv = true;
    ai2Sent = false;
    ai2LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao3_feed.substring(ao3_feed.length() - 6, ao3_feed.length()))) {
    ao3Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(2));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao3_value = "0";

      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(2));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao3_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai3_feedACK.substring(ai3_feedACK.length() - 10, ai3_feedACK.length()))) {
    ai3Recv = true;
    ai3Sent = false;
    ai3LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao4_feed.substring(ao4_feed.length() - 6, ao4_feed.length()))) {
    ao4Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(3));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }
      
      //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao4_value = "0";

      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      if (analogOutOneSuccess) {
        Wire.beginTransmission(0x1f);
        Wire.write(byte(3));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao4_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai4_feedACK.substring(ai4_feedACK.length() - 10, ai4_feedACK.length()))) {
    ai4Recv = true;
    ai4Sent = false;
    ai4LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao5_feed.substring(ao5_feed.length() - 6, ao5_feed.length()))) {
    ao5Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao5_value = "0";

      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(0));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao5_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai5_feedACK.substring(ai5_feedACK.length() - 10, ai5_feedACK.length()))) {
    ai5Recv = true;
    ai5Sent = false;
    ai5LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao6_feed.substring(ao6_feed.length() - 6, ao6_feed.length()))) {
    ao6Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(1));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }
      
      //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao6_value = "0";

      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(1));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao6_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai6_feedACK.substring(ai6_feedACK.length() - 10, ai6_feedACK.length()))) {
    ai6Recv = true;
    ai6Sent = false;
    ai6LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao7_feed.substring(ao7_feed.length() - 6, ao7_feed.length()))) {
    ao7Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(2));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao7_value = "0";

      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(2));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_A, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao7_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 80, 300, 50, BLACK);
      //M5.Lcd.drawString(ai1_value, 90, 80, 2);
      //replaceText(90, 80, 300, 50, 2 ai1_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai7_feedACK.substring(ai7_feedACK.length() - 10, ai7_feedACK.length()))) {
    ai7Recv = true;
    ai7Sent = false;
    ai7LoopCount = 0;
  }

  if (topic.substring(topic.length() - 6, topic.length()).equalsIgnoreCase(ao8_feed.substring(ao8_feed.length() - 6, ao8_feed.length()))) {
    ao8Recv = true;

    if ((message.toInt()) < 0) {
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(3));
        Wire.write(byte(0));
        Wire.write(byte(0));
        Wire.endTransmission();
      }
      
      //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao8_value = "0";

      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
    else {

      int aoSendValue = int(message.toInt() * 2.048);
      if (aoSendValue > 65535) {
        aoSendValue = 65535;
      }
      
      if (analogOutTwoSuccess) {
        Wire.beginTransmission(0x1c);
        Wire.write(byte(3));
        Wire.write(byte(aoSendValue >> 8));
        Wire.write(byte(aoSendValue));
        Wire.endTransmission();
      }

      //mcp.setChannelValue(MCP4728_CHANNEL_B, ((message.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
      //                MCP4728_GAIN_2X);
      
      ao8_value = String(aoSendValue);
      
      //M5.Lcd.fillRect(90, 120, 300, 50, BLACK);
      //M5.Lcd.drawString(ai2_value, 90, 120, 2);
      //replaceText(90, 120, 300, 50, 2 ai2_value);
    }
  }
  if (topic.substring(topic.length() - 10, topic.length()).equalsIgnoreCase(ai8_feedACK.substring(ai8_feedACK.length() - 10, ai8_feedACK.length()))) {
    ai8Recv = true;
    ai8Sent = false;
    ai8LoopCount = 0;
  }
}