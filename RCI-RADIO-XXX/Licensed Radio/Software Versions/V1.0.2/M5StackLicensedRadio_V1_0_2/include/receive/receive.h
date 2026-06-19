#include "M5StackRadio.h"

void onRadioMessage(String message) {
  // we received a message, so print out the topic and contents
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
        do1_value = packagedValue;
      }

      if (fullTopic.equalsIgnoreCase(do2_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(1, !bool(packagedValue.toInt()));
        }
        do2_value = packagedValue;
      }

      if (fullTopic.equalsIgnoreCase(do3_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(2, !bool(packagedValue.toInt()));
        }
        do3_value = packagedValue;
      }

      if (fullTopic.equalsIgnoreCase(do4_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(3, !bool(packagedValue.toInt()));
        }
        do4_value = packagedValue;
      }

      if (fullTopic.equalsIgnoreCase(do5_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(4, !bool(packagedValue.toInt()));
        }
        do5_value = packagedValue;
      }

      if (fullTopic.equalsIgnoreCase(do6_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(5, !bool(packagedValue.toInt()));
        }
        do6_value = packagedValue;
      }

      if (fullTopic.equalsIgnoreCase(do7_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(6, !bool(packagedValue.toInt()));
        }
        do7_value = packagedValue;
      }

      if (fullTopic.equalsIgnoreCase(do8_feed)) {
        if (digitalOutputSuccess) {
          pcfw1.digitalWrite(7, !bool(packagedValue.toInt()));
        }
        do8_value = packagedValue;
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

          ao1_value = "0";
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

          ao1_value = String(aoSendValue);
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

          ao2_value = "0";
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

          ao2_value = String(aoSendValue);
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

          ao3_value = "0";
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

          ao3_value = String(aoSendValue);
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

          ao4_value = "0";
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

          ao4_value = String(aoSendValue);
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

          ao5_value = "0";
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

          ao5_value = String(aoSendValue);
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

          ao6_value = "0";
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

          ao6_value = String(aoSendValue);
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

          ao7_value = "0";
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

          ao7_value = String(aoSendValue);
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

          ao8_value = "0";
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

          ao8_value = String(aoSendValue);
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
    signalStrengthString = message.substring(message.lastIndexOf("-"));
    radioGettingRSSI = false;
    Serial.println(signalStrengthString);
  }
}