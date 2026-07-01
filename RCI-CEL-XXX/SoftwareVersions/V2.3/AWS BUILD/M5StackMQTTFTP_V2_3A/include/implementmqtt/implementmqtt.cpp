#include "M5StackMQTTFTP.h"

void reconnectMqtt() {
  if (!mqttClient.connected() && logDisconnect) {
    logDisconnectEvent(true);
    logDisconnect = false;
  }

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

  if (!checkTimeRoutine()) {
    errorCode = "ERROR CODE: 21";
    M5.Lcd.drawString(errorCode, 35, 210, 1);
    return;
  }

  delay(250);

  //INITIAL CONFIGURATION CONNECTION
  myFile = SD.open(sdConfigFileName);
  if ((myFile.available() < 1 && !configReadSuccess) || (groupID.isEmpty())) {
    myFile.close();

    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);

    normalMode = false;
    cfgServerMode = true;
    hasConfigInfo = false;
    initialSDCheck = true;
    configConnect();

    forceUpdate = true;

    while (!hasConfigInfo) {
      M5.update();

      timeOutCurrentMillis = millis();
      onRightPress();
      onRightRelease();
      onLeftPress();
      onLeftRelease();
      onCenterPress();
      onCenterRelease();

      //toggleResetClock();

      Ethernet.maintain();

      if (!normalMode && timeOutCurrentMillis - timeOutPreviousMillis >= timeOutInterval) {
        returnToNormalOperation();
      }
    }
  } else {
    myFile.close();
  }

  delay(250);

  connected_feed_publish = groupID + "_p";
  connected_feed_publishACK = connected_feed_publish + "_ACK";

  connected_feed_subscribe = connected_feed_publish;
  config_update_feed = serialNumber + "_configUpdate";
  internal_update_feed = serialNumber + "_internalUpdate";
  credential_update_feed = serialNumber + "_credUpdate";
  api_update_feed = serialNumber + "_apiUpdate";
  software_version_feed = serialNumber + "_version";
  config_dump_feed = serialNumber + "_configDump";
  modem_sn_feed = serialNumber + "_modemSN";
  modem_rssi_feed = serialNumber + "_RSSI";
  log_upload_feed = serialNumber + "_logUpload";
  log_delete_feed = serialNumber + "_logDelete";
  sparkplugb_feed = MQTT_SPARKPLUGB_TOPIC_PREFIX + groupID;
  sparkplugb_ncmd_feed = sparkplugb_feed + "/NCMD/#";
  sparkplugb_ndata_feed = sparkplugb_feed + "/NDATA/#";
  sparkplugb_all_feed = sparkplugb_feed + MQTT_WILDCARD_TOPIC_SUFFIX;

  sparkplugb_feedACK = MQTT_SPARKPLUGB_ACK_TOPIC_PREFIX + groupID + String("_") + unitID;

  heartbeat_feed = groupID + "_" + unitID + "_" + "HB";
  createHeartbeatSubscriptionArrays(heartbeatSubscriptionsString);

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

      errorCode = "ERROR CODE: 22";
      M5.Lcd.drawString(errorCode, 35, 210, 1);
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
  mqttClient.subscribe(config_dump_feed, subscribeQos);
  mqttClient.subscribe(modem_sn_feed, subscribeQos);
  mqttClient.subscribe(modem_rssi_feed, subscribeQos);

  mqttClient.subscribe(log_upload_feed, subscribeQos);
  mqttClient.subscribe(log_delete_feed, subscribeQos);

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

  logConnectEvent();
  logDisconnect = true;

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  reconnect = false;
  reconnectFirstMessageStatus = false;

  cycleCounter = 0;
  cyclingPaused = false;
  cyclingFrozen = false;
  cycleComponentValues(!screenRefresh);

  cycleComponentsPreviousMillis = millis();

  /*
  for (int i = 0; i < subCount; i++) {
    heartbeatCheckPreviousMillis[i] = millis();
  }
  */

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
      //Serial.println("Skipping, values unchanged.");
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

  //return uint64_t(firstTimeValue) + millis(); //POSSIBLE INACCURACIES BECAUSE OF TIME NEEDED TO ACTUALLY CONNECT TO INTERNET!
  
  //return uint64_t(time(NULL)); //ONLY RETURNS SECONDS. NEEDS MILLISECONDS!

  //MOST ACCURATE. NTP SYNCED HARDWARE CLOCK (MICROSECONDS)!
  struct timeval tv;
  // Get high-precision time from the ESP32 system clock
  gettimeofday(&tv, NULL);
  
  // Convert seconds to milliseconds and microseconds to milliseconds
  uint64_t timeMs = ((uint64_t)tv.tv_sec * 1000ULL) + ((uint64_t)tv.tv_usec / 1000ULL);
  
  return timeMs;
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
    if (!do1CommFailTriggered) {
      pcfw1.digitalWrite(0, !bool(pcfw1Out1Recv));
    }
    if (!do2CommFailTriggered) {
      pcfw1.digitalWrite(1, !bool(pcfw1Out2Recv));
    }
    if (!do3CommFailTriggered) {
      pcfw1.digitalWrite(2, !bool(pcfw1Out3Recv));
    }
    if (!do4CommFailTriggered) {
      pcfw1.digitalWrite(3, !bool(pcfw1Out4Recv));
    }
    if (!do5CommFailTriggered) {
      pcfw1.digitalWrite(4, !bool(pcfw1Out5Recv));
    }
    if (!do6CommFailTriggered) {
      pcfw1.digitalWrite(5, !bool(pcfw1Out6Recv));
    }
    if (!do7CommFailTriggered) {
      pcfw1.digitalWrite(6, !bool(pcfw1Out7Recv));
    }
    if (!do8CommFailTriggered) {
      pcfw1.digitalWrite(7, !bool(pcfw1Out8Recv));
    }
  }

  if (newDO1Available(String(pcfw1Out1Recv)) && !do1CommFailTriggered) {
    updateDO1(String(pcfw1Out1Recv));
    if (isDigitalOutputScreen()) {
      displayDO1();
    }
  }

  if (newDO2Available(String(pcfw1Out2Recv)) && !do2CommFailTriggered) {
    updateDO2(String(pcfw1Out2Recv));
    if (isDigitalOutputScreen()) {
      displayDO2();
    }
  }

  if (newDO3Available(String(pcfw1Out3Recv))  && !do3CommFailTriggered) {
    updateDO3(String(pcfw1Out3Recv));
    if (isDigitalOutputScreen()) {
      displayDO3();
    }
  }

  if (newDO4Available(String(pcfw1Out4Recv))  && !do4CommFailTriggered) {
    updateDO4(String(pcfw1Out4Recv));
    if (isDigitalOutputScreen()) {
      displayDO4();
    }
  }

  if (newDO5Available(String(pcfw1Out5Recv))  && !do5CommFailTriggered) {
    updateDO5(String(pcfw1Out5Recv));
    if (isDigitalOutputScreen()) {
      displayDO5();
    }
  }

  if (newDO6Available(String(pcfw1Out6Recv))  && !do6CommFailTriggered) {
    updateDO6(String(pcfw1Out6Recv));
    if (isDigitalOutputScreen()) {
      displayDO6();
    }
  }

  if (newDO7Available(String(pcfw1Out7Recv))  && !do7CommFailTriggered) {
    updateDO7(String(pcfw1Out7Recv));
    if (isDigitalOutputScreen()) {
      displayDO7();
    }
  }

  if (newDO8Available(String(pcfw1Out8Recv))  && !do8CommFailTriggered) {
    updateDO8(String(pcfw1Out8Recv));
    if (isDigitalOutputScreen()) {
      displayDO8();
    }
  }


  if ((dac1Out1Recv) < 0) {
    
    if (analogOutOneSuccess && !ao1CommFailTriggered) {
      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO1Available("0") && !ao1CommFailTriggered) {
      updateAO1("0");
      if (isAnalogOutputScreen()) {
        displayAO1();
      }
    }
  }
  else {

    int aoSendValue = int(dac1Out1Recv * 2.048);
    if (aoSendValue > 65535) {
      aoSendValue = 65535;
    }
    
    if (analogOutOneSuccess && !ao1CommFailTriggered) {
      Wire.beginTransmission(0x1f);
      Wire.write(byte(0));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_A, ((dac1Out1Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO1Available(String(aoSendValue)) && !ao1CommFailTriggered) {
      updateAO1(String(aoSendValue));
      if (isAnalogOutputScreen()) {
        displayAO1();
      }
    }
  }

  if ((dac1Out2Recv) < 0) {
    
    if (analogOutOneSuccess && !ao2CommFailTriggered) {
      Wire.beginTransmission(0x1f);
      Wire.write(byte(1));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
    }
    
    //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO2Available("0") && !ao2CommFailTriggered) {
      updateAO2("0");
      if (isAnalogOutputScreen()) {
        displayAO2();
      }
    }
  }
  else {

    int aoSendValue = int(dac1Out2Recv * 2.048);
    if (aoSendValue > 65535) {
      aoSendValue = 65535;
    }
    
    if (analogOutOneSuccess && !ao2CommFailTriggered) {
      Wire.beginTransmission(0x1f);
      Wire.write(byte(1));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_B, ((dac1Out2Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO2Available(String(aoSendValue)) && !ao2CommFailTriggered) {
      updateAO2(String(aoSendValue));
      if (isAnalogOutputScreen()) {
        displayAO2();
      }
    }
  }

  if ((dac1Out3Recv) < 0) {
    
    if (analogOutOneSuccess && !ao3CommFailTriggered) {
      Wire.beginTransmission(0x1f);
      Wire.write(byte(2));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO3Available("0") && !ao3CommFailTriggered) {
      updateAO3("0");
      if (isAnalogOutputScreen()) {
        displayAO3();
      }
    }
  }
  else {

    int aoSendValue = int(dac1Out3Recv * 2.048);
    if (aoSendValue > 65535) {
      aoSendValue = 65535;
    }
    
    if (analogOutOneSuccess && !ao3CommFailTriggered) {
      Wire.beginTransmission(0x1f);
      Wire.write(byte(2));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_A, ((dac1Out3Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO3Available(String(aoSendValue)) && !ao3CommFailTriggered) {
      updateAO3(String(aoSendValue));
      if (isAnalogOutputScreen()) {
        displayAO3();
      }
    }
  }

  if ((dac1Out4Recv) < 0) {
    
    if (analogOutOneSuccess && !ao4CommFailTriggered) {
      Wire.beginTransmission(0x1f);
      Wire.write(byte(3));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
    }
    
    //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO4Available("0") && !ao4CommFailTriggered) {
      updateAO4("0");
      if (isAnalogOutputScreen()) {
        displayAO4();
      }
    }
  }
  else {

    int aoSendValue = int(dac1Out4Recv * 2.048);
    if (aoSendValue > 65535) {
      aoSendValue = 65535;
    }
    
    if (analogOutOneSuccess && !ao4CommFailTriggered) {
      Wire.beginTransmission(0x1f);
      Wire.write(byte(3));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_B, ((dac1Out4Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO4Available(String(aoSendValue)) && !ao4CommFailTriggered) {
      updateAO4(String(aoSendValue));
      if (isAnalogOutputScreen()) {
        displayAO4();
      }
    }
  }

  if ((dac2Out1Recv) < 0) {
    
    if (analogOutTwoSuccess && !ao5CommFailTriggered) {
      Wire.beginTransmission(0x1c);
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO5Available("0") && !ao5CommFailTriggered) {
      updateAO5("0");
      if (isAnalogOutputScreen()) {
        displayAO5();
      }
    }
  }
  else {

    int aoSendValue = int(dac2Out1Recv * 2.048);
    if (aoSendValue > 65535) {
      aoSendValue = 65535;
    }
    
    if (analogOutTwoSuccess && !ao5CommFailTriggered) {
      Wire.beginTransmission(0x1c);
      Wire.write(byte(0));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_A, ((dac2Out1Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO5Available(String(aoSendValue)) && !ao5CommFailTriggered) {
      updateAO5(String(aoSendValue));
      if (isAnalogOutputScreen()) {
        displayAO5();
      }
    }
  }

  if ((dac2Out2Recv) < 0) {
    
    if (analogOutTwoSuccess && !ao6CommFailTriggered) {
      Wire.beginTransmission(0x1c);
      Wire.write(byte(1));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
    }
    
    //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO6Available("0") && !ao6CommFailTriggered) {
      updateAO6("0");
      if (isAnalogOutputScreen()) {
        displayAO6();
      }
    }
  }
  else {

    int aoSendValue = int(dac2Out2Recv * 2.048);
    if (aoSendValue > 65535) {
      aoSendValue = 65535;
    }
    
    if (analogOutTwoSuccess && !ao6CommFailTriggered) {
      Wire.beginTransmission(0x1c);
      Wire.write(byte(1));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_B, ((dac2Out2Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO6Available(String(aoSendValue)) && !ao6CommFailTriggered) {
      updateAO6(String(aoSendValue));
      if (isAnalogOutputScreen()) {
        displayAO6();
      }
    }
  }

  if ((dac2Out3Recv) < 0) {
    
    if (analogOutTwoSuccess && !ao7CommFailTriggered) {
      Wire.beginTransmission(0x1c);
      Wire.write(byte(2));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_A, 0 >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO7Available("0") && !ao7CommFailTriggered) {
      updateAO7("0");
      if (isAnalogOutputScreen()) {
        displayAO7();
      }
    }
  }
  else {

    int aoSendValue = int(dac2Out3Recv * 2.048);
    if (aoSendValue > 65535) {
      aoSendValue = 65535;
    }
    
    if (analogOutTwoSuccess && !ao7CommFailTriggered) {
      Wire.beginTransmission(0x1c);
      Wire.write(byte(2));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_A, ((dac2Out3Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO7Available(String(aoSendValue)) && !ao7CommFailTriggered) {
      updateAO7(String(aoSendValue));
      if (isAnalogOutputScreen()) {
        displayAO7();
      }
    }
  }

  if (dac2Out4Recv < 0) {
    
    if (analogOutTwoSuccess && !ao8CommFailTriggered) {
      Wire.beginTransmission(0x1c);
      Wire.write(byte(3));
      Wire.write(byte(0));
      Wire.write(byte(0));
      Wire.endTransmission();
    }
    
    //mcp.setChannelValue(MCP4728_CHANNEL_B, 0 >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO8Available("0") && !ao8CommFailTriggered) {
      updateAO8("0");
      if (isAnalogOutputScreen()) {
        displayAO8();
      }
    }
  }
  else {

    int aoSendValue = int(dac2Out4Recv * 2.048);
    if (aoSendValue > 65535) {
      aoSendValue = 65535;
    }
    
    if (analogOutTwoSuccess && !ao8CommFailTriggered) {
      Wire.beginTransmission(0x1c);
      Wire.write(byte(3));
      Wire.write(byte(aoSendValue >> 8));
      Wire.write(byte(aoSendValue));
      Wire.endTransmission();
    }

    //mcp.setChannelValue(MCP4728_CHANNEL_B, ((dac2Out4Recv) * 2) >> 4, MCP4728_VREF_INTERNAL,
    //                MCP4728_GAIN_2X);
    
    if (newAO8Available(String(aoSendValue)) && !ao8CommFailTriggered) {
      updateAO8(String(aoSendValue));
      if (isAnalogOutputScreen()) {
        displayAO8();
      }
    }
  }
}