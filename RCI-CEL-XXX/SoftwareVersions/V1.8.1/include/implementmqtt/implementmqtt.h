#include "M5StackMQTTFTP.h"

void reconnectMqtt() {
  if (!reconnectFirstMessageStatus) {
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0);

    M5.Lcd.drawString("PRIBUSIN INC.", 40, 20, 1);
    M5.Lcd.drawString(rciTitle, 50, 70, 1);
    M5.Lcd.drawString("ORGANIZING", 60, 120, 1);
    M5.Lcd.drawString("COMMUNICATION DATA", 0, 170, 1);
    reconnectFirstMessageStatus = true;
  }

  publishAllc = false;
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

  connected_feed_publish = groupID + "_p";
  connected_feed_publishACK = connected_feed_publish + "_ACK";

  connected_feed_subscribe = connected_feed_publish;
  config_update_feed = serialNumber + "_configUpdate";
  internal_update_feed = serialNumber + "_internalUpdate";
  credential_update_feed = serialNumber + "_credUpdate";
  api_update_feed = serialNumber + "_apiUpdate";
  software_version_feed = serialNumber + "_version";

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

  String willPayload = "CONNECTION CHANGE DETECTED!";
  bool willRetain = true;
  int willQos = 0;

  mqttClient.beginWill(willTopic, willPayload.length(), willRetain, willQos);
  mqttClient.print(willPayload);
  mqttClient.endWill();
  
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

  // set the message receive callback
  mqttClient.onMessage(onMqttMessage);

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
  
  if (!do1_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do1_feed, subscribeQos);
    do1_feedACK = do1_feed + "_ACK";
    //mqttClient.subscribe(do1_feedACK, subscribeQos);
  }
  if (!do2_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do2_feed, subscribeQos);
    do2_feedACK = do2_feed + "_ACK";
    //mqttClient.subscribe(do2_feedACK, subscribeQos);
  }
  if (!do3_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do3_feed, subscribeQos);
    do3_feedACK = do3_feed + "_ACK";
    //mqttClient.subscribe(do3_feedACK, subscribeQos);
  }
  if (!do4_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do4_feed, subscribeQos);
    do4_feedACK = do4_feed + "_ACK";
    //mqttClient.subscribe(do4_feedACK, subscribeQos);
  }
  if (!do5_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do5_feed, subscribeQos);
    do5_feedACK = do5_feed + "_ACK";
    //mqttClient.subscribe(do5_feedACK, subscribeQos);
  }
  if (!do6_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do6_feed, subscribeQos);
    do6_feedACK = do6_feed + "_ACK";
    //mqttClient.subscribe(do6_feedACK, subscribeQos);
  }
  if (!do7_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do7_feed, subscribeQos);
    do7_feedACK = do7_feed + "_ACK";
    //mqttClient.subscribe(do7_feedACK, subscribeQos);
  }
  if (!do8_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(do8_feed, subscribeQos);
    do8_feedACK = do8_feed + "_ACK";
    //mqttClient.subscribe(do8_feedACK, subscribeQos);
  }
  if (!ao1_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao1_feed, subscribeQos);
    ao1_feedACK = ao1_feed + "_ACK";
    //mqttClient.subscribe(ao1_feedACK, subscribeQos);
  }
  if (!ao2_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao2_feed, subscribeQos);
    ao2_feedACK = ao2_feed + "_ACK";
    //mqttClient.subscribe(ao2_feedACK, subscribeQos);
  }
  if (!ao3_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao3_feed, subscribeQos);
    ao3_feedACK = ao3_feed + "_ACK";
    //mqttClient.subscribe(ao3_feedACK, subscribeQos);
  }
  if (!ao4_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao4_feed, subscribeQos);
    ao4_feedACK = ao4_feed + "_ACK";
    //mqttClient.subscribe(ao4_feedACK, subscribeQos);
  }
  if (!ao5_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao5_feed, subscribeQos);
    ao5_feedACK = ao5_feed + "_ACK";
    //mqttClient.subscribe(ao5_feedACK, subscribeQos);
  }
  if (!ao6_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao6_feed, subscribeQos);
    ao6_feedACK = ao6_feed + "_ACK";
    //mqttClient.subscribe(ao6_feedACK, subscribeQos);
  }
  if (!ao7_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao7_feed, subscribeQos);
    ao7_feedACK = ao7_feed + "_ACK";
    //mqttClient.subscribe(ao7_feedACK, subscribeQos);
  }
  if (!ao8_feed.equalsIgnoreCase("")) {
    mqttClient.subscribe(ao8_feed, subscribeQos);
    ao8_feedACK = ao8_feed + "_ACK";
    //mqttClient.subscribe(ao8_feedACK, subscribeQos);
  }


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

  for (int i = 0; i < subCount; i++) {
    mqttClient.subscribe(*heartbeat_check_feeds[i], subscribeQos);
  }

  M5.Lcd.clear();
  M5.Lcd.setCursor(0, 0);
  reconnect = false;
  reconnectFirstMessageStatus = false;

  //M5.Lcd.drawString("DI1: " + di1_value, 10, 0, 2);

  //M5.Lcd.drawString("DI2: " + di2_value, 10, 40, 2);

  //M5.Lcd.drawString("AI1: " + ai1_value, 10, 80, 2);

  //M5.Lcd.drawString("AI2: " + ai2_value, 10, 120, 2);

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
}