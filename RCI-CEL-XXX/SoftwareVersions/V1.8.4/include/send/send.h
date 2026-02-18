#include "M5StackMQTTFTP.h"

void publishHeartbeat() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  payload = String(heartbeatPublishCount) + "_HB_" + unitID;
  heartbeatPublishCount++;

  mqttClient.beginMessage(heartbeat_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishConnected() {
  if (!pubConnectedSent) {
    pubConnectedSent = true;
    pubConnectedRecv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  
  payload = String(connectedPublishCount) + "_CONNGOOD_" + unitID;
  connectedPublishCount++;

  mqttClient.beginMessage(connected_feed_publish, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishConnectedReceipt() {
  payload = "1";

  mqttClient.beginMessage(connected_feed_subscribeACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishConf(bool final) {
  /*
  if (!pubConfSent) {
    pubConfSent = true;
  }
  */
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  if (final) {
    payload = "4";
  } else {
    payload = "2";
  }

  if (receivedConfigFTP) {
    payload = "CONFIGURATION UPDATE SUCCESSFUL!";
  }

  mqttClient.beginMessage(config_update_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishCreds(bool final) {
  /*
  if (!pubCredSent) {
    pubCredSent = true;
  }
  */
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  if (final) {
    payload = "4";
  } else {
    payload = "2";
  }

  mqttClient.beginMessage(credential_update_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishInternal(bool final) {
  /*
  if (!pubInternalSent) {
    pubInternalSent = true;
  }
  */
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  if (final) {
    payload = "4";
  } else {
    payload = "2";
  }

  if (receivedInternalFTP) {
    payload = "INTERNAL UPDATE SUCCESSFUL!";
  }

  mqttClient.beginMessage(internal_update_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishApi(bool final) {
  /*
  if (!pubApiSent) {
    pubApiSent = true;
  }
  */
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  if (final) {
    payload = "4";
  } else {
    payload = "2";
  }

  if (receivedApiFTP) {
    payload = "API UPDATE SUCCESSFUL!";
  }

  mqttClient.beginMessage(api_update_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishSoftwareVersion() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  //replaceText(10, 200, 300, 50, 1, "PUBLISHING DI1!");
  //clearTextPreviousMillis = millis();
  //clear = true;
  
  payload = versionNumber;

  mqttClient.beginMessage(software_version_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishDI1() {
  if (noHandshakeDigitalInputFeeds[0]) {
    return;
  }

  if (!di1Sent) {
    di1Sent = true;
    di1Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI1!");
  clearTextPreviousMillis = millis();
  clear = true;

  pcfr0Prev = int(pcfr.digitalRead(0));
  payload = String(pcfr0Prev);
  di1_value = payload;

  mqttClient.beginMessage(di1_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishDO1Receipt() {
  payload = "1";

  mqttClient.beginMessage(do1_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI2() {
  if (noHandshakeDigitalInputFeeds[1]) {
    return;
  }

  if (!di2Sent) {
    di2Sent = true;
    di2Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI2!");
  clearTextPreviousMillis = millis();
  clear = true;

  pcfr1Prev = int(pcfr.digitalRead(1));
  payload = String(pcfr1Prev);
  di2_value = payload;

  mqttClient.beginMessage(di2_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);  
}

void publishDO2Receipt() {
  payload = "1";

  mqttClient.beginMessage(do2_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI3() {
  if (noHandshakeDigitalInputFeeds[2]) {
    return;
  }

  if (!di3Sent) {
    di3Sent = true;
    di3Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI3!");
  clearTextPreviousMillis = millis();
  clear = true;

  pcfr2Prev = int(pcfr.digitalRead(2));
  payload = String(pcfr2Prev);
  di3_value = payload;

  mqttClient.beginMessage(di3_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishDO3Receipt() {
  payload = "1";

  mqttClient.beginMessage(do3_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI4() {
  if (noHandshakeDigitalInputFeeds[3]) {
    return;
  }

  if (!di4Sent) {
    di4Sent = true;
    di4Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI4!");
  clearTextPreviousMillis = millis();
  clear = true;

  pcfr3Prev = int(pcfr.digitalRead(3));
  payload = String(pcfr3Prev);
  di4_value = payload;

  mqttClient.beginMessage(di4_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);  
}

void publishDO4Receipt() {
  payload = "1";

  mqttClient.beginMessage(do4_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI5() {
  if (noHandshakeDigitalInputFeeds[4]) {
    return;
  }

  if (!di5Sent) {
    di5Sent = true;
    di5Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI5!");
  clearTextPreviousMillis = millis();
  clear = true;

  pcfr4Prev = int(pcfr.digitalRead(4));
  payload = String(pcfr4Prev);
  di5_value = payload;

  mqttClient.beginMessage(di5_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishDO5Receipt() {
  payload = "1";

  mqttClient.beginMessage(do5_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI6() {
  if (noHandshakeDigitalInputFeeds[5]) {
    return;
  }

  if (!di6Sent) {
    di6Sent = true;
    di6Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI6!");
  clearTextPreviousMillis = millis();
  clear = true;

  pcfr5Prev = int(pcfr.digitalRead(5));
  payload = String(pcfr5Prev);
  di6_value = payload;

  mqttClient.beginMessage(di6_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);  
}

void publishDO6Receipt() {
  payload = "1";

  mqttClient.beginMessage(do6_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI7() {
  if (noHandshakeDigitalInputFeeds[6]) {
    return;
  }

  if (!di7Sent) {
    di7Sent = true;
    di7Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI7!");
  clearTextPreviousMillis = millis();
  clear = true;

  pcfr6Prev = int(pcfr.digitalRead(6));
  payload = String(pcfr6Prev);
  di7_value = payload;

  mqttClient.beginMessage(di7_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishDO7Receipt() {
  payload = "1";

  mqttClient.beginMessage(do7_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishDI8() {
  if (noHandshakeDigitalInputFeeds[7]) {
    return;
  }

  if (!di8Sent) {
    di8Sent = true;
    di8Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING DO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING DI8!");
  clearTextPreviousMillis = millis();
  clear = true;

  pcfr7Prev = int(pcfr.digitalRead(7));
  payload = String(pcfr7Prev);
  di8_value = payload;

  mqttClient.beginMessage(di8_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);  
}

void publishDO8Receipt() {
  payload = "1";

  mqttClient.beginMessage(do8_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI1() {
  if (noHandshakeAnalogInputFeeds[0]) {
    return;
  }

  if (!ai1Sent) {
    ai1Sent = true;
    ai1Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI1!");
  clearTextPreviousMillis = millis();
  clear = true;

  adc0 = ads1115.readADC_SingleEnded(0);
  adc0Prev = adc0;
  payload = String(adc0);
  ai1_value = payload;
  if (ai1_value.toInt() < 0) {
    ai1_value = "0";
  }

  mqttClient.beginMessage(ai1_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO1Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao1_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI2() {
  if (noHandshakeAnalogInputFeeds[1]) {
    return;
  }

  if (!ai2Sent) {
    ai2Sent = true;
    ai2Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI2!");
  clearTextPreviousMillis = millis();
  clear = true;

  adc1 = ads1115.readADC_SingleEnded(1);
  adc1Prev = adc1;
  payload = String(adc1);
  ai2_value = payload;
  if (ai2_value.toInt() < 0) {
    ai2_value = "0";
  }

  mqttClient.beginMessage(ai2_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO2Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao2_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI3() {
  if (noHandshakeAnalogInputFeeds[2]) {
    return;
  }

  if (!ai3Sent) {
    ai3Sent = true;
    ai3Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI3!");
  clearTextPreviousMillis = millis();
  clear = true;

  adc2 = ads1115.readADC_SingleEnded(2);
  adc2Prev = adc2;
  payload = String(adc2);
  ai3_value = payload;
  if (ai3_value.toInt() < 0) {
    ai3_value = "0";
  }

  mqttClient.beginMessage(ai3_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO3Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao3_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI4() {
  if (noHandshakeAnalogInputFeeds[3]) {
    return;
  }

  if (!ai4Sent) {
    ai4Sent = true;
    ai4Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI4!");
  clearTextPreviousMillis = millis();
  clear = true;

  adc3 = ads1115.readADC_SingleEnded(3);
  adc3Prev = adc3;
  payload = String(adc3);
  ai4_value = payload;
  if (ai4_value.toInt() < 0) {
    ai4_value = "0";
  }

  mqttClient.beginMessage(ai4_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO4Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao4_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI5() {
  if (noHandshakeAnalogInputFeeds[4]) {
    return;
  }

  if (!ai5Sent) {
    ai5Sent = true;
    ai5Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI5!");
  clearTextPreviousMillis = millis();
  clear = true;

  adc0second = ads1115second.readADC_SingleEnded(0);
  adc0secondPrev = adc0second;
  payload = String(adc0second);
  ai5_value = payload;
  if (ai5_value.toInt() < 0) {
    ai5_value = "0";
  }

  mqttClient.beginMessage(ai5_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO5Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao5_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI6() {
  if (noHandshakeAnalogInputFeeds[5]) {
    return;
  }

  if (!ai6Sent) {
    ai6Sent = true;
    ai6Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI6!");
  clearTextPreviousMillis = millis();
  clear = true;

  adc1second = ads1115second.readADC_SingleEnded(1);
  adc1secondPrev = adc1second;
  payload = String(adc1second);
  ai6_value = payload;
  if (ai6_value.toInt() < 0) {
    ai6_value = "0";
  }

  mqttClient.beginMessage(ai6_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO6Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao6_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI7() {
  if (noHandshakeAnalogInputFeeds[6]) {
    return;
  }

  if (!ai7Sent) {
    ai7Sent = true;
    ai7Recv = false;
  }
  
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO1!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI7!");
  clearTextPreviousMillis = millis();
  clear = true;

  adc2second = ads1115second.readADC_SingleEnded(2);
  adc2secondPrev = adc2second;
  payload = String(adc2second);
  ai7_value = payload;
  if (ai7_value.toInt() < 0) {
    ai7_value = "0";
  }

  mqttClient.beginMessage(ai7_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO7Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao7_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAI8() {
  if (noHandshakeAnalogInputFeeds[7]) {
    return;
  }

  if (!ai8Sent) {
    ai8Sent = true;
    ai8Recv = false;
  }

  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING AO2!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING AI8!");
  clearTextPreviousMillis = millis();
  clear = true;

  adc3second = ads1115second.readADC_SingleEnded(3);
  adc3secondPrev = adc3second;
  payload = String(adc3second);
  ai8_value = payload;
  if (ai8_value.toInt() < 0) {
    ai8_value = "0";
  }

  mqttClient.beginMessage(ai8_feed, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  delay(500);
}

void publishAO8Receipt() {
  payload = "1";

  mqttClient.beginMessage(ao8_feedACK, payload.length(), retained, qos, duplicateMqttMessage);
  mqttClient.print(payload);
  mqttClient.endMessage();
  //delay(500);
}

void publishAll() {
  //M5.Lcd.fillRect(10, 200, 300, 50, BLACK);
  //M5.Lcd.drawString("PUBLISHING ALL!", 10, 200, 1);
  replaceText(10, 200, 300, 50, 1, "PUBLISHING ALL!");
  clearTextPreviousMillis = millis();
  clear = true;

  // save the last time a message was sent
  publishAllPreviousMillis = publishAllCurrentMillis;

  // send message, the Print interface can be used to set the message contents
  // in this case we know the size ahead of time, so the message payload can be streamed

  if (IONum.toInt() >= 1) {
    if (digitalInputSuccess) {
      publishDI1();
    }

    if (analogInOneSuccess) {
      publishAI1();
    }
  }  

  if (IONum.toInt() >= 2) {
    if (digitalInputSuccess) {
      publishDI2();
    }

    if (analogInOneSuccess) {
      publishAI2();
    }
  }  

  if (IONum.toInt() >= 3) {
    if (digitalInputSuccess) {
      publishDI3();
    }

    if (analogInOneSuccess) {
      publishAI3();
    }
  }  

  if (IONum.toInt() >= 4) {
    if (digitalInputSuccess) {
      publishDI4();
    }

    if (analogInOneSuccess) {
      publishAI4();
    }
  }  

  if (IONum.toInt() >= 5) {
    if (digitalInputSuccess) {
      publishDI5();
    }

    if (analogInTwoSuccess) {
      publishAI5();
    }
  }  

  if (IONum.toInt() >= 6) {
    if (digitalInputSuccess) {
      publishDI6();
    }

    if (analogInTwoSuccess) {
      publishAI6();
    }
  }  

  if (IONum.toInt() >= 7) {
    if (digitalInputSuccess) {
      publishDI7();
    }

    if (analogInTwoSuccess) {
      publishAI7();
    }
  }  

  if (IONum.toInt() >= 8) {
    if (digitalInputSuccess) {
      publishDI8();
    }

    if (analogInTwoSuccess) {
      publishAI8();
    }
  }  

  reconnectCount++;
}