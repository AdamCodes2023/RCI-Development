#include "M5StackMQTTFTP.h"

void reconnectMqtt() {
  if (!reconnectFirstMessageStatus) {
    spnOnMQTTDisconnected(sparkplugNode);

    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);

    M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
    M5.Lcd.drawString(rciTitle, 50, 70, 1);
    M5.Lcd.drawString("ORGANIZING", 60, 120, 1);
    M5.Lcd.drawString("COMMUNICATION DATA", 0, 170, 1);
    reconnectFirstMessageStatus = true;
  }

  publishAllc = false;
  clearUpdateFlags();

  connected_feed_publish = groupID + "_p";
  connected_feed_publishACK = connected_feed_publish + "_ACK";

  connected_feed_subscribe = connected_feed_publish;
  config_update_feed = serialNumber + "_configUpdate";
  internal_update_feed = serialNumber + "_internalUpdate";
  credential_update_feed = serialNumber + "_credUpdate";
  api_update_feed = serialNumber + "_apiUpdate";
  software_version_feed = serialNumber + "_version";
  modem_sn_feed = serialNumber + "_modemSN";
  sparkplugb_feed = MQTT_SPARKPLUGB_TOPIC_PREFIX + groupID;
  sparkplugb_ncmd_feed = sparkplugb_feed + "/NCMD/#";
  sparkplugb_ndata_feed = sparkplugb_feed + "/NDATA/#";
  sparkplugb_all_feed = sparkplugb_feed + MQTT_WILDCARD_TOPIC_SUFFIX;

  sparkplugb_feedACK = MQTT_SPARKPLUGB_ACK_TOPIC_PREFIX + groupID + String("_") + unitID;

  heartbeat_feed = groupID + "_" + unitID + "_" + "HB";
  createHeartbeatSubscriptionArrays(heartbeatSubscriptionsString);

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
      if (firstTimeGet) {
        firstTimeValue = t;
      }
      ntpMonth = String(month(t));
      ntpDay = String(day(t));
      ntpYear = String(year(t));
      dateString = "DATE: " + ntpMonth + "/" + ntpDay + "/" + ntpYear;

      ethClientSSL.setVerificationTime((unsigned long) (epoch/86400UL) + 719528UL, 0);
      getTimePreviousMillis = getTimeCurrentMillis;
      firstTimeGet = false;
      udpHasTimePacket = false;
    }
  }

  reconnectCount = 0;

  if (!reconnect) {
    SparkplugNodeState result = makeNDEATHPayload(sparkplugNode);
    if (result == spn_NDEATH_PL_READY) {
      if (publishSparkplugBLastWill(sparkplugNode->mqtt_message.topic, sparkplugNode->mqtt_message.payload->buffer, sparkplugNode->mqtt_message.payload->written_length)) {
        Serial.println("PUBLISHING NDEATH");
      }
    }
  }
  
  mqttClient.setId(serialNumber);

  //mqttClient.setUsernamePassword("ADAMMQTT3","Tennis19");
  mqttClient.setUsernamePassword(mqttUsername, mqttPassword);
  
  if (!reconnect) {
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
    M5.Lcd.drawString(rciTitle, 50, 70, 1);
    M5.Lcd.drawString("VERIFYING", 65, 120, 1);
    M5.Lcd.drawString("CONNECTION", 60, 170, 1);
  }

  if (!mqttClient.connect(broker.c_str(), port)) {
    if (!reconnect) {
      M5.Lcd.clear();
      M5.Lcd.setCursor(0, 0);
      M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
      M5.Lcd.drawString(rciTitle, 50, 70, 1);
      M5.Lcd.drawString("CONNECTION FAILED", 5, 120, 1);
      M5.Lcd.drawString("RETRYING", 85, 170, 1);
      //M5.Lcd.print(mqttClient.connectError());
    }

    reconnect = true;
    return;
  }

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
  M5.Lcd.drawString(rciTitle, 50, 70, 1);
  M5.Lcd.drawString("CONNECTION SUCCESS", 0, 120, 1);
  M5.Lcd.drawString("LOADING", 90, 170, 1);

  // simulate mqtt broker connection
  spnOnMQTTConnected(sparkplugNode);

  // set the message receive callback
  //mqttClient.onMessage(onMqttMessage);
  mqttClient.onMessage(NCMDcallback);

  // subscribe to a topic
  // the second parameter sets the QoS of the subscription,
  // the the library supports subscribing at QoS 0, 1, or 2
  int subscribeQos = 0;

  mqttClient.subscribe(connected_feed_subscribe, subscribeQos);
  connected_feed_subscribeACK = connected_feed_subscribe + "_ACK";
  //mqttClient.subscribe(connected_feed_subscribeACK, subscribeQos);
  mqttClient.subscribe(connected_feed_publishACK, subscribeQos);

  mqttClient.subscribe(config_update_feed, subscribeQos);
  //config_update_feedACK = config_update_feed + "_ACK";
  //mqttClient.subscribe(config_update_feedACK, subscribeQos);
  
  mqttClient.subscribe(internal_update_feed, subscribeQos);
  //internal_update_feedACK = internal_update_feed + "_ACK";
  //mqttClient.subscribe(internal_update_feedACK, subscribeQos);
  
  mqttClient.subscribe(credential_update_feed, subscribeQos);
  //credential_update_feedACK = credential_update_feed + "_ACK";
  //mqttClient.subscribe(credential_update_feedACK, subscribeQos);

  mqttClient.subscribe(api_update_feed, subscribeQos);
  //api_update_feedACK = api_update_feed + "_ACK";
  //mqttClient.subscribe(api_update_feedACK, subscribeQos);

  mqttClient.subscribe(software_version_feed, subscribeQos);
  mqttClient.subscribe(modem_sn_feed, subscribeQos);

  mqttClient.subscribe(sparkplugNode->topics.NCMD, subscribeQos);
  
  //mqttClient.subscribe(sparkplugb_ncmd_feed, subscribeQos);
  //mqttClient.subscribe(sparkplugb_ndata_feed, subscribeQos);
  //mqttClient.subscribe(sparkplugb_all_feed, subscribeQos);

  for (int i = 0; i < numberOfRemoteUnits; i++) {
    String sparkplugb_remote_node_feed = String("");
    if (connectedRemoteUnitIDs[i] >= 10) {
      sparkplugb_remote_node_feed = sparkplugb_feed + MQTT_ANY_LAYER_TOPIC_CHARS + String(connectedRemoteUnitIDs[i]);
    } else {
      sparkplugb_remote_node_feed = sparkplugb_feed + MQTT_ANY_LAYER_TOPIC_CHARS + globalZeroText + String(connectedRemoteUnitIDs[i]);
    }
    mqttClient.subscribe(sparkplugb_remote_node_feed, subscribeQos);
  }

  mqttClient.subscribe(sparkplugb_feedACK, subscribeQos);

  /*
  //ACKNOWLEDGEMENT FEEDS
  if (!di1_feed.equalsIgnoreCase("") && !noHandshakeDigitalInputFeeds[0]) {
    mqttClient.subscribe(di1_feedACK, subscribeQos);
  }
  if (!di2_feed.equalsIgnoreCase("") && !noHandshakeDigitalInputFeeds[1]) {
    mqttClient.subscribe(di2_feedACK, subscribeQos);
  }
  if (!di3_feed.equalsIgnoreCase("") && !noHandshakeDigitalInputFeeds[2]) {
    mqttClient.subscribe(di3_feedACK, subscribeQos);
  }
  if (!di4_feed.equalsIgnoreCase("") && !noHandshakeDigitalInputFeeds[3]) {
    mqttClient.subscribe(di4_feedACK, subscribeQos);
  }
  if (!di5_feed.equalsIgnoreCase("") && !noHandshakeDigitalInputFeeds[4]) {
    mqttClient.subscribe(di5_feedACK, subscribeQos);
  }
  if (!di6_feed.equalsIgnoreCase("") && !noHandshakeDigitalInputFeeds[5]) {
    mqttClient.subscribe(di6_feedACK, subscribeQos);
  }
  if (!di7_feed.equalsIgnoreCase("") && !noHandshakeDigitalInputFeeds[6]) {
    mqttClient.subscribe(di7_feedACK, subscribeQos);
  }
  if (!di8_feed.equalsIgnoreCase("") && !noHandshakeDigitalInputFeeds[7]) {
    mqttClient.subscribe(di8_feedACK, subscribeQos);
  }
  if (!ai1_feed.equalsIgnoreCase("") && !noHandshakeAnalogInputFeeds[0]) {
    mqttClient.subscribe(ai1_feedACK, subscribeQos);
  }
  if (!ai2_feed.equalsIgnoreCase("") && !noHandshakeAnalogInputFeeds[1]) {
    mqttClient.subscribe(ai2_feedACK, subscribeQos);
  }
  if (!ai3_feed.equalsIgnoreCase("") && !noHandshakeAnalogInputFeeds[2]) {
    mqttClient.subscribe(ai3_feedACK, subscribeQos);
  }
  if (!ai4_feed.equalsIgnoreCase("") && !noHandshakeAnalogInputFeeds[3]) {
    mqttClient.subscribe(ai4_feedACK, subscribeQos);
  }
  if (!ai5_feed.equalsIgnoreCase("") && !noHandshakeAnalogInputFeeds[4]) {
    mqttClient.subscribe(ai5_feedACK, subscribeQos);
  }
  if (!ai6_feed.equalsIgnoreCase("") && !noHandshakeAnalogInputFeeds[5]) {
    mqttClient.subscribe(ai6_feedACK, subscribeQos);
  }
  if (!ai7_feed.equalsIgnoreCase("") && !noHandshakeAnalogInputFeeds[6]) {
    mqttClient.subscribe(ai7_feedACK, subscribeQos);
  }
  if (!ai8_feed.equalsIgnoreCase("") && !noHandshakeAnalogInputFeeds[7]) {
    mqttClient.subscribe(ai8_feedACK, subscribeQos);
  }
  */

  for (int i = 0; i < subCount; i++) {
    mqttClient.subscribe(*heartbeat_check_feeds[i], subscribeQos);
  }

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  reconnect = false;
  reconnectFirstMessageStatus = false;

  cycleCounter = 0;
  cyclingPaused = false;
  cycleComponentValues();

  reconnectPreviousMillis = millis();
  cycleComponentsPreviousMillis = millis();

  for (int i = 0; i < subCount; i++) {
    heartbeatCheckPreviousMillis[i] = millis();
  }

  heartbeatPublishPreviousMillis = millis();
  publishHeartbeat();
  publishConnected();
  publishSoftwareVersion();
}

void createSparkplugTags() {
  //INPUT TAGS
  switch(IONum.toInt()) {
    case 8:
      createInt32Tag(di8_feed.c_str(), &pcfr7Prev, -208, true, false);
      createInt16Tag(ai8_feed.c_str(), &adc3secondPrev, -228, true, false);

    case 7:
      createInt32Tag(di7_feed.c_str(), &pcfr6Prev, -207, true, false);
      createInt16Tag(ai7_feed.c_str(), &adc2secondPrev, -227, true, false);

    case 6:
      createInt32Tag(di6_feed.c_str(), &pcfr5Prev, -206, true, false);
      createInt16Tag(ai6_feed.c_str(), &adc1secondPrev, -226, true, false);

    case 5:
      createInt32Tag(di5_feed.c_str(), &pcfr4Prev, -205, true, false);
      createInt16Tag(ai5_feed.c_str(), &adc0secondPrev, -225, true, false);

    case 4:
      createInt32Tag(di4_feed.c_str(), &pcfr3Prev, -204, true, false);
      createInt16Tag(ai4_feed.c_str(), &adc3Prev, -224, true, false);

    case 3:
      createInt32Tag(di3_feed.c_str(), &pcfr2Prev, -203, true, false);
      createInt16Tag(ai3_feed.c_str(), &adc2Prev, -223, true, false);

    case 2:
      createInt32Tag(di2_feed.c_str(), &pcfr1Prev, -202, true, false);
      createInt16Tag(ai2_feed.c_str(), &adc1Prev, -222, true, false);

    case 1:
      createInt32Tag(di1_feed.c_str(), &pcfr0Prev, -201, true, false);
      createInt16Tag(ai1_feed.c_str(), &adc0Prev, -221, true, false);

    default:
      ;
  }

  //OUTPUT TAGS
  if (!do1_feed.equalsIgnoreCase("")) {
    createInt32Tag(do1_feed.c_str(), &pcfw1Out1Recv, -2001, false, true);
    //do1_feedACK = do1_feed + "_ACK";
  }
  if (!do2_feed.equalsIgnoreCase("")) {
    createInt32Tag(do2_feed.c_str(), &pcfw1Out2Recv, -2002, false, true);
    //do2_feedACK = do2_feed + "_ACK";
  }
  if (!do3_feed.equalsIgnoreCase("")) {
    createInt32Tag(do3_feed.c_str(), &pcfw1Out3Recv, -2003, false, true);
    //do3_feedACK = do3_feed + "_ACK";
  }
  if (!do4_feed.equalsIgnoreCase("")) {
    createInt32Tag(do4_feed.c_str(), &pcfw1Out4Recv, -2004, false, true);
    //do4_feedACK = do4_feed + "_ACK";
  }
  if (!do5_feed.equalsIgnoreCase("")) {
    createInt32Tag(do5_feed.c_str(), &pcfw1Out5Recv, -2005, false, true);
    //do5_feedACK = do5_feed + "_ACK";
  }
  if (!do6_feed.equalsIgnoreCase("")) {
    createInt32Tag(do6_feed.c_str(), &pcfw1Out6Recv, -2006, false, true);
    //do6_feedACK = do6_feed + "_ACK";
  }
  if (!do7_feed.equalsIgnoreCase("")) {
    createInt32Tag(do7_feed.c_str(), &pcfw1Out7Recv, -2007, false, true);
    //do7_feedACK = do7_feed + "_ACK";
  }
  if (!do8_feed.equalsIgnoreCase("")) {
    createInt32Tag(do8_feed.c_str(), &pcfw1Out8Recv, -2008, false, true);
    //do8_feedACK = do8_feed + "_ACK";
  }
  if (!ao1_feed.equalsIgnoreCase("")) {
    createInt16Tag(ao1_feed.c_str(), &dac1Out1Recv, -2021, false, true);
    //ao1_feedACK = ao1_feed + "_ACK";
  }
  if (!ao2_feed.equalsIgnoreCase("")) {
    createInt16Tag(ao2_feed.c_str(), &dac1Out2Recv, -2022, false, true);
    //ao2_feedACK = ao2_feed + "_ACK";
  }
  if (!ao3_feed.equalsIgnoreCase("")) {
    createInt16Tag(ao3_feed.c_str(), &dac1Out3Recv, -2023, false, true);
    //ao3_feedACK = ao3_feed + "_ACK";
  }
  if (!ao4_feed.equalsIgnoreCase("")) {
    createInt16Tag(ao4_feed.c_str(), &dac1Out4Recv, -2024, false, true);
    //ao4_feedACK = ao4_feed + "_ACK";
  }
  if (!ao5_feed.equalsIgnoreCase("")) {
    createInt16Tag(ao5_feed.c_str(), &dac2Out1Recv, -2025, false, true);
    //ao5_feedACK = ao5_feed + "_ACK";
  }
  if (!ao6_feed.equalsIgnoreCase("")) {
    createInt16Tag(ao6_feed.c_str(), &dac2Out2Recv, -2026, false, true);
    //ao6_feedACK = ao6_feed + "_ACK";
  }
  if (!ao7_feed.equalsIgnoreCase("")) {
    createInt16Tag(ao7_feed.c_str(), &dac2Out3Recv, -2027, false, true);
    //ao7_feedACK = ao7_feed + "_ACK";
  }
  if (!ao8_feed.equalsIgnoreCase("")) {
    createInt16Tag(ao8_feed.c_str(), &dac2Out4Recv, -2028, false, true);
    //ao8_feedACK = ao8_feed + "_ACK";
  }
}

void manageSparkplugNodeState() {
  // Call the tick node function
  sparkplugNodeState = tickSparkplugNode(sparkplugNode);

  // Check the resulting SparkplugNodeState and take appropriate action
  switch(sparkplugNodeState) {
    case spn_ERROR_NODE_NULL:
      Serial.println("FAILED TO START, IGNORING LOOP!");
      break;
    case spn_SCAN_NOT_DUE:
      //Serial.println("SCAN TAGS NOT DUE");
      break;
    case spn_SCAN_FAILED:
      Serial.println("ERROR: SCAN TAGS FAILED");
      break;
    case spn_MAKE_NBIRTH_FAILED:
      Serial.println("ERROR: FAILED TO MAKE NBIRTH PAYLOAD");
      break;
    case spn_NBIRTH_PL_READY:  
      if (publishSparkplugBMessage(sparkplugNode->mqtt_message.topic, sparkplugNode->mqtt_message.payload->buffer, sparkplugNode->mqtt_message.payload->written_length)) {
        Serial.println("PUBLISHING NBIRTH");
        spnOnPublishNBIRTH(sparkplugNode);
      }
      break;
    case spn_VALUES_UNCHANGED:
      Serial.println("Skipping, values unchanged.");
      break;
    case spn_MAKE_NDATA_FAILED:
      Serial.println("ERROR: FAILED TO MAKE NDATA PAYLOAD");
      break;
    case spn_NDATA_PL_READY:
      if (publishSparkplugBMessage(sparkplugNode->mqtt_message.topic, sparkplugNode->mqtt_message.payload->buffer, sparkplugNode->mqtt_message.payload->written_length)) {
        Serial.println("PUBLISHING NDATA");
        spnOnPublishNDATA(sparkplugNode);
      }
      break;
    default:
      Serial.print("ERROR: Unknown State returned: ");
      int nodeStateInt = (int)sparkplugNodeState;
      Serial.println(nodeStateInt);
  }
}

void printSparkplugNodeConfig(SparkplugNodeConfig* node) {
  // Prints relevant data from a sparkplug node
  if (node == NULL) {
    Serial.println("Provided SparkplugNodeConfig* is NULL!");
    return;
  }
  Serial.println("SparkplugNodeConfig:");

  // Print the topics
  Serial.println("Topics:");
  Serial.println(node->topics.NBIRTH);
  Serial.println(node->topics.NDEATH);
  Serial.println(node->topics.NCMD);
  Serial.println(node->topics.NDATA);
  Serial.println();

  // Print the node's tags
  Serial.print("bdSeq value: ");
  Serial.println(*(node->vars.bd_seq_tag_value));
  Serial.print("rebirth value: ");
  Serial.println(*(node->vars.rebirth_tag_value));
  Serial.print("Scan Rate value: ");
  Serial.println(*(node->vars.scan_rate_tag_value));
  Serial.println();
}

uint64_t timestampFunction() {
  /*
  This function provides an actual timestamp.
  */
  return uint64_t(firstTimeValue) + millis();
}

void NCMDcallback(int messageLength) {
  if (mqttClient.messageTopic().indexOf(sparkplugb_feed) != -1) {
    sparkplugb_feedACK = MQTT_SPARKPLUGB_ACK_TOPIC_PREFIX + groupID + String("_") + mqttClient.messageTopic().substring(mqttClient.messageTopic().lastIndexOf(MQTT_TOPIC_LAYER_SEPARATION_CHAR) + 1, mqttClient.messageTopic().lastIndexOf(MQTT_TOPIC_LAYER_SEPARATION_CHAR) + 3);

    byte payload_buffer[messageLength];
    mqttClient.read(payload_buffer, messageLength);
    SparkplugNodeState result = processIncomingNCMDPayload(sparkplugNode, payload_buffer, messageLength);
    Serial.print("SparkplugB Receive Result: ");
    Serial.println(result);
    //Serial.println(*(sparkplugNode->mqtt_message.payload)->buffer);
    if (result == spn_PROCESS_NCMD_SUCCESS) {
      Serial.print("SparkplugB ACK Feed: ");
      Serial.println(sparkplugb_feedACK);
      receivedSparkplugBMessage = true;
    }
  } else {
    onMqttMessage(messageLength);
  }
}

void updateOutputsFromTags() {
  if (digitalOutputSuccess) {
    pcfw1.digitalWrite(0, !bool(pcfw1Out1Recv));
    pcfw1.digitalWrite(1, !bool(pcfw1Out2Recv));
    pcfw1.digitalWrite(2, !bool(pcfw1Out3Recv));
    pcfw1.digitalWrite(3, !bool(pcfw1Out4Recv));
    pcfw1.digitalWrite(4, !bool(pcfw1Out5Recv));
    pcfw1.digitalWrite(5, !bool(pcfw1Out6Recv));
    pcfw1.digitalWrite(6, !bool(pcfw1Out7Recv));
    pcfw1.digitalWrite(7, !bool(pcfw1Out8Recv));
  }
  do1_value = String(pcfw1Out1Recv);
  do2_value = String(pcfw1Out2Recv);
  do3_value = String(pcfw1Out3Recv);
  do4_value = String(pcfw1Out4Recv);
  do5_value = String(pcfw1Out5Recv);
  do6_value = String(pcfw1Out6Recv);
  do7_value = String(pcfw1Out7Recv);
  do8_value = String(pcfw1Out8Recv);

  if ((dac1Out1Recv) < 0) {
    
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
  }
  else {

    int aoSendValue = int(dac1Out1Recv * 2.048);
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

    //mcp.setChannelValue(MCP4728_CHANNEL_A, ((dac1Out1Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    ao1_value = String(aoSendValue);
  }

  if ((dac1Out2Recv) < 0) {
    
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
  }
  else {

    int aoSendValue = int(dac1Out2Recv * 2.048);
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

    //mcp.setChannelValue(MCP4728_CHANNEL_B, ((dac1Out2Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    ao2_value = String(aoSendValue);
  }

  if ((dac1Out3Recv) < 0) {
    
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
  }
  else {

    int aoSendValue = int(dac1Out3Recv * 2.048);
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

    //mcp.setChannelValue(MCP4728_CHANNEL_A, ((dac1Out3Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    ao3_value = String(aoSendValue);
  }

  if ((dac1Out4Recv) < 0) {
    
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
  }
  else {

    int aoSendValue = int(dac1Out4Recv * 2.048);
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

    //mcp.setChannelValue(MCP4728_CHANNEL_B, ((dac1Out4Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    ao4_value = String(aoSendValue);
  }

  if ((dac2Out1Recv) < 0) {
    
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
  }
  else {

    int aoSendValue = int(dac2Out1Recv * 2.048);
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

    //mcp.setChannelValue(MCP4728_CHANNEL_A, ((dac2Out1Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    ao5_value = String(aoSendValue);
  }

  if ((dac2Out2Recv) < 0) {
    
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
  }
  else {

    int aoSendValue = int(dac2Out2Recv * 2.048);
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

    //mcp.setChannelValue(MCP4728_CHANNEL_B, ((dac2Out2Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    ao6_value = String(aoSendValue);
  }

  if ((dac2Out3Recv) < 0) {
    
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
  }
  else {

    int aoSendValue = int(dac2Out3Recv * 2.048);
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

    //mcp.setChannelValue(MCP4728_CHANNEL_A, ((dac2Out3Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    ao7_value = String(aoSendValue);
  }

  if (dac2Out4Recv < 0) {
    
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
  }
  else {

    int aoSendValue = int(dac2Out4Recv * 2.048);
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

    //mcp.setChannelValue(MCP4728_CHANNEL_B, ((dac2Out4Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    ao8_value = String(aoSendValue);
  }
}