#include "M5StackRadio.h"

void onRadioMessage(String message) {
  // We received a message, so print out the topic and contents.
  Serial.println(message);

  String topic;
  topic = "";
  
  String senderAddress;
  senderAddress = "";

  // use the Stream interface to print the contents
  for (int i = 0; i < message.length(); i++) {
    String character = message.substring(i, i + 1);

    if (character.equalsIgnoreCase("#")) {
      senderAddress = topic;

      if (senderAddress.substring(0, senderAddress.indexOf("_")).equalsIgnoreCase(groupID)) {
        checkHeartbeatSubscriptionArrays(senderAddress.substring(senderAddress.indexOf("_") + 1));
      }

      Serial.println(topic);
      topic = "";
    } else if (character.equalsIgnoreCase(";")) {
      String fullTopic;
      fullTopic = senderAddress + "_" + topic.substring(0, topic.indexOf("="));
      String packagedValue;
      packagedValue = topic.substring(topic.indexOf("=") + 1);

      if (fullTopic.equalsIgnoreCase(do1_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(0, !bool(packagedValue.toInt()));
        }
        
        if (newDO1Available(packagedValue)) {
          updateDO1(packagedValue);
          if (isDigitalOutputScreen()) {
            displayDO1();
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(do2_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(1, !bool(packagedValue.toInt()));
        }
        
        if (newDO2Available(packagedValue)) {
          updateDO2(packagedValue);
          if (isDigitalOutputScreen()) {
            displayDO2();
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(do3_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(2, !bool(packagedValue.toInt()));
        }
        
        if (newDO3Available(packagedValue)) {
          updateDO3(packagedValue);
          if (isDigitalOutputScreen()) {
            displayDO3();
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(do4_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(3, !bool(packagedValue.toInt()));
        }
        
        if (newDO4Available(packagedValue)) {
          updateDO4(packagedValue);
          if (isDigitalOutputScreen()) {
            displayDO4();
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(do5_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(4, !bool(packagedValue.toInt()));
        }
        
        if (newDO5Available(packagedValue)) {
          updateDO5(packagedValue);
          if (isDigitalOutputScreen()) {
            displayDO5();
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(do6_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(5, !bool(packagedValue.toInt()));
        }
        
        if (newDO6Available(packagedValue)) {
          updateDO6(packagedValue);
          if (isDigitalOutputScreen()) {
            displayDO6();
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(do7_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(6, !bool(packagedValue.toInt()));
        }
        
        if (newDO7Available(packagedValue)) {
          updateDO7(packagedValue);
          if (isDigitalOutputScreen()) {
            displayDO7();
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(do8_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(7, !bool(packagedValue.toInt()));
        }

        if (newDO8Available(packagedValue)) {
          updateDO8(packagedValue);
          if (isDigitalOutputScreen()) {
            displayDO8();
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(ao1_feed)) {
        if ((packagedValue.toInt()) < 0) {
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1f);
            Wire.write(byte(0));
            Wire.write(byte(0));
            Wire.write(byte(0));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO1Available("0")) {
            updateAO1("0");
            if (isAnalogOutputScreen()) {
              displayAO1();
            }
          }
        }
        else {
          int aoSendValue = int(packagedValue.toInt() * 2.048);
          if (aoSendValue > 65535) {
            aoSendValue = 65535;
          }
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1f);
            Wire.write(byte(0));
            Wire.write(byte(aoSendValue >> 8));
            Wire.write(byte(aoSendValue));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_A, ((packagedValue.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO1Available(String(aoSendValue))) {
            updateAO1(String(aoSendValue));
            if (isAnalogOutputScreen()) {
              displayAO1();
            }
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(ao2_feed)) {
        if ((packagedValue.toInt()) < 0) {
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1f);
            Wire.write(byte(1));
            Wire.write(byte(0));
            Wire.write(byte(0));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO2Available("0")) {
            updateAO2("0");
            if (isAnalogOutputScreen()) {
              displayAO2();
            }
          }
        }
        else {
          int aoSendValue = int(packagedValue.toInt() * 2.048);
          if (aoSendValue > 65535) {
            aoSendValue = 65535;
          }
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1f);
            Wire.write(byte(1));
            Wire.write(byte(aoSendValue >> 8));
            Wire.write(byte(aoSendValue));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_B, ((packagedValue.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO2Available(String(aoSendValue))) {
            updateAO2(String(aoSendValue));
            if (isAnalogOutputScreen()) {
              displayAO2();
            }
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(ao3_feed)) {
        if ((packagedValue.toInt()) < 0) {
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1f);
            Wire.write(byte(2));
            Wire.write(byte(0));
            Wire.write(byte(0));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_C, 0 >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO3Available("0")) {
            updateAO3("0");
            if (isAnalogOutputScreen()) {
              displayAO3();
            }
          }
        }
        else {
          int aoSendValue = int(packagedValue.toInt() * 2.048);
          if (aoSendValue > 65535) {
            aoSendValue = 65535;
          }
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1f);
            Wire.write(byte(2));
            Wire.write(byte(aoSendValue >> 8));
            Wire.write(byte(aoSendValue));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_C, ((packagedValue.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO3Available(String(aoSendValue))) {
            updateAO3(String(aoSendValue));
            if (isAnalogOutputScreen()) {
              displayAO3();
            }
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(ao4_feed)) {
        if ((packagedValue.toInt()) < 0) {
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1f);
            Wire.write(byte(3));
            Wire.write(byte(0));
            Wire.write(byte(0));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_D, 0 >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO4Available("0")) {
            updateAO4("0");
            if (isAnalogOutputScreen()) {
              displayAO4();
            }
          }
        }
        else {
          int aoSendValue = int(packagedValue.toInt() * 2.048);
          if (aoSendValue > 65535) {
            aoSendValue = 65535;
          }
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1f);
            Wire.write(byte(3));
            Wire.write(byte(aoSendValue >> 8));
            Wire.write(byte(aoSendValue));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_D, ((packagedValue.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO4Available(String(aoSendValue))) {
            updateAO4(String(aoSendValue));
            if (isAnalogOutputScreen()) {
              displayAO4();
            }
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(ao5_feed)) {
        if ((packagedValue.toInt()) < 0) {
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1c);
            Wire.write(byte(0));
            Wire.write(byte(0));
            Wire.write(byte(0));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO5Available("0")) {
            updateAO5("0");
            if (isAnalogOutputScreen()) {
              displayAO5();
            }
          }
        }
        else {
          int aoSendValue = int(packagedValue.toInt() * 2.048);
          if (aoSendValue > 65535) {
            aoSendValue = 65535;
          }
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1c);
            Wire.write(byte(0));
            Wire.write(byte(aoSendValue >> 8));
            Wire.write(byte(aoSendValue));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_A, ((packagedValue.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO5Available(String(aoSendValue))) {
            updateAO5(String(aoSendValue));
            if (isAnalogOutputScreen()) {
              displayAO5();
            }
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(ao6_feed)) {
        if ((packagedValue.toInt()) < 0) {
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1c);
            Wire.write(byte(1));
            Wire.write(byte(0));
            Wire.write(byte(0));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO6Available("0")) {
            updateAO6("0");
            if (isAnalogOutputScreen()) {
              displayAO6();
            }
          }
        }
        else {
          int aoSendValue = int(packagedValue.toInt() * 2.048);
          if (aoSendValue > 65535) {
            aoSendValue = 65535;
          }
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1c);
            Wire.write(byte(1));
            Wire.write(byte(aoSendValue >> 8));
            Wire.write(byte(aoSendValue));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_B, ((packagedValue.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO6Available(String(aoSendValue))) {
            updateAO6(String(aoSendValue));
            if (isAnalogOutputScreen()) {
              displayAO6();
            }
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(ao7_feed)) {
        if ((packagedValue.toInt()) < 0) {
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1c);
            Wire.write(byte(2));
            Wire.write(byte(0));
            Wire.write(byte(0));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_C, 0 >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO7Available("0")) {
            updateAO7("0");
            if (isAnalogOutputScreen()) {
              displayAO7();
            }
          }
        }
        else {
          int aoSendValue = int(packagedValue.toInt() * 2.048);
          if (aoSendValue > 65535) {
            aoSendValue = 65535;
          }
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1c);
            Wire.write(byte(2));
            Wire.write(byte(aoSendValue >> 8));
            Wire.write(byte(aoSendValue));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_C, ((packagedValue.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO7Available(String(aoSendValue))) {
            updateAO7(String(aoSendValue));
            if (isAnalogOutputScreen()) {
              displayAO7();
            }
          }
        }
      }

      if (fullTopic.equalsIgnoreCase(ao8_feed)) {
        if ((packagedValue.toInt()) < 0) {
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1c);
            Wire.write(byte(3));
            Wire.write(byte(0));
            Wire.write(byte(0));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_D, 0 >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO8Available("0")) {
            updateAO8("0");
            if (isAnalogOutputScreen()) {
              displayAO8();
            }
          }
        }
        else {
          int aoSendValue = int(packagedValue.toInt() * 2.048);
          if (aoSendValue > 65535) {
            aoSendValue = 65535;
          }
      
          if (analogOutOneSuccess) {
            Wire.beginTransmission(0x1c);
            Wire.write(byte(3));
            Wire.write(byte(aoSendValue >> 8));
            Wire.write(byte(aoSendValue));
            Wire.endTransmission();

            //mcp.setChannelValue(MCP4728_CHANNEL_D, ((packagedValue.toInt()) * 2) >> 4, MCP4728_VREF_INTERNAL,
            //                MCP4728_GAIN_2X);
          }

          if (newAO8Available(String(aoSendValue))) {
            updateAO8(String(aoSendValue));
            if (isAnalogOutputScreen()) {
              displayAO8();
            }
          }
        }
      }
      
      Serial.println(topic);
      topic = "";
    } else if (character.equalsIgnoreCase("?")) {
      if (senderAddress.substring(0, senderAddress.indexOf("_")).equalsIgnoreCase(groupID)) {
        if (topic.substring(0, topic.indexOf("_")).equalsIgnoreCase(groupID) && topic.substring(topic.indexOf("_") + 1).equalsIgnoreCase(unitID)) {
          publishAllFlag = true;
        }
      }
    } else if (character.equalsIgnoreCase("$")) {
      if (topic.substring(topic.length() - 12, topic.length()).equalsIgnoreCase("configUpdate")) {
        //SEND CONFIG TO REMOTE UNIT?
      }
    } else if (character.equalsIgnoreCase("!")) {
      if (senderAddress.substring(0, senderAddress.indexOf("_")).equalsIgnoreCase(groupID)) {
        if (topic.substring(0, topic.indexOf("_")).equalsIgnoreCase(groupID) && topic.substring(topic.indexOf("_") + 1).equalsIgnoreCase(unitID)) {
          publishSignalSend();
        } else if (topic.substring(0, topic.indexOf("_")).equalsIgnoreCase(groupID) && topic.substring(topic.indexOf("_") + 1).equalsIgnoreCase(MESSAGING_HOST_UNIT_ID) && !isHost) {
          radioGettingRSSI = true;
          getRadioSignal();
        } else if (topic.substring(0, topic.indexOf("_")).equalsIgnoreCase(groupID) && isHost) {
          radioGettingRSSI = true;
          getRadioSignal();
        }
      }
    } else {
      topic += character;
    }
  }
  
  if (message.indexOf("-") != -1 && !message.substring(message.lastIndexOf("-") + 1, message.lastIndexOf("-") + 2).equalsIgnoreCase("M") && radioGettingRSSI) {
    if (message.indexOf("OK", message.lastIndexOf("-")) != -1) {
      signalStrengthString = message.substring(message.lastIndexOf("-"), message.indexOf("OK", message.lastIndexOf("-")));
    } else {
      signalStrengthString = message.substring(message.lastIndexOf("-"));
    }
    signalStrengthString.trim();
    radioGettingRSSI = false;
    Serial.print("RSSI: ");
    Serial.println(signalStrengthString);
  }
}